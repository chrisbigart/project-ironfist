#ifndef TOWN_H
#define TOWN_H

#include "adventure/adv.h"

#pragma pack(push,1)

extern unsigned long gTownEligibleBuildMask[];
extern signed char gDwellingType[][12];

extern signed char gSpellLimits[];

extern char cHeroTypeInitial[];

#define MAX_CASTLES 72

#define NUM_DWELLINGS 12

enum FACTION
{
	FACTION_KNIGHT = 0,
	FACTION_BARBARIAN = 1,
	FACTION_SORCERESS = 2,
	FACTION_WARLOCK = 3,
	FACTION_WIZARD = 4,
	FACTION_NECROMANCER = 5,
	FACTION_MULTIPLE = 6,
	FACTION_RANDOM = 7,

	FACTION_CYBORG = 13,
};

enum BUILDING_CODE : __int8
{
  BUILDING_MAGE_GUILD = 0x0,
  BUILDING_THIEVES_GUILD = 0x1,
  BUILDING_TAVERN = 0x2,
  BUILDING_DOCK = 0x3,
  BUILDING_WELL = 0x4,
  BUILDING_TENT = 0x5,
  BUILDING_CASTLE = 0x6,
  BUILDING_STATUE = 0x7,
  BUILDING_LEFT_TURRET = 0x8,
  BUILDING_RIGHT_TURRET = 0x9,
  BUILDING_MARKET = 0xA,
  BUILDING_SPECIAL_GROWTH = 0xB,
  BUILDING_MOAT = 0xC,
  BUILDING_SPECIAL = 0xD,
  BUILDING_BOAT = 0xE,
  BUILDING_CAPTAIN = 0xF,
  BUILDING_EXT_0 = 0x10,
  BUILDING_EXT_1 = 0x11,
  BUILDING_EXT_2 = 0x12,
  BUILDING_DWELLING_1 = 0x13,
  BUILDING_DWELLING_2 = 0x14,
  BUILDING_DWELLING_3 = 0x15,
  BUILDING_DWELLING_4 = 0x16,
  BUILDING_DWELLING_5 = 0x17,
  BUILDING_DWELLING_6 = 0x18,
  //Why is "upgrade 1" an upgrade to dwelling 2?
  //Don't know; these names were found in the executable
  BUILDING_UPGRADE_1 = 0x19,
  BUILDING_UPGRADE_2 = 0x1A,
  BUILDING_UPGRADE_3 = 0x1B,
  BUILDING_UPGRADE_4 = 0x1C,
  BUILDING_UPGRADE_5 = 0x1D,
  BUILDING_UPGRADE_5B = 0x1E,
  BUILDING_EXT_3 = 0x1F,
};

class town {
public:
  char idx;
  char ownerIdx;
  char alignment;
  char factionID;
  char x;
  char y;
  char buildDockRelated;
  char field_7;
  armyGroup garrison;
  char visitingHeroIdx;
  unsigned int buildingsBuiltFlags;
  char mageGuildLevel;
  char field_1D;
  __int16 numCreaturesInDwelling[NUM_DWELLINGS];
  char exists;
  char mayNotBeUpgradedToCastle;
  char field_38;
  char playerPos;
  __int16 extraIdx;
  char mageGuildSpells[5][4];
  char numSpellsOfLevel[5];
  __int16 field_55;
  char name[12];
  char field_63;

  town();

  void SelectSpells();
  void SetNumSpellsOfLevel(int,int);
};
#pragma pack(push, 1)
class border : public widget
	{
	public:
		bitmap *bitmap;
		icon *icon;
		__int16 color;
	};
#pragma pack(pop)
#pragma pack(push, 1)
struct BuildingDisplay
	{
	int animationLength;
	int animationIdx;
	int built;
	int buildingCode;
	icon *icon;
	border *guiElement;
	};
#pragma pack(pop)
#pragma pack(push, 1)
struct strip
	{
	heroWindow *window;
	char _1[24];
	int x;
	int y;
	int field_24;
	int drawBorder;
	void *field_2C[6];
	icon *stripIcon;
	icon *creaturePortraits[5];
	int creatureTypes[5];
	icon *portraitIcon;
	icon *portraitFlagIcon;
	int portraitIconIdx;
	int field_7C;
	armyGroup *army;
	};
#pragma pack(pop)

class playerData;

#pragma pack(push, 1)
struct bankBox
	{
	playerData *player;
	__int16 x;
	__int16 y;
	heroWindow *window;
	};
#pragma pack(pop)

class townManager : public baseManager {
public: 
	town *castle;
	icon *couldBeBackground;
	BuildingDisplay *buildingDisplays[32];
	int curBuilding;
	int factionID;
	int field_C6;
	heroWindow *townScreen;
	strip *garrisonDisplay;
	strip *visitingArmyDisplay;
	strip *field_D6;
	int field_DA;
	strip *field_DE;
	int field_E2;
	strip *field_E6;
	int field_EA;
	bankBox *bankbox;
	char infoMessage[80];
	int field_142;
	int field_146;
	int field_14A;
	int field_14E;
	int field_152;
	int field_156;
	int field_15A;
	int field_15E;
	heroWindow *curScreen;
	heroWindow *dialog;
	int numberOfCreaturesToSplit; // field_16A;
	int maxNumberCreaturesToSplit;// field_16E;
	int recruitHeroConfirmed;
	hero *heroBeingRecruited;

	townManager();

	void BuildObj(signed int);

	virtual int Open(int);
	int Open_orig(int);
	void SetupMage(heroWindow*);

	int RecruitHero(int,int);
	int RecruitHero_orig(int,int);
};


extern char *xNecromancerShrine;
extern char *gWellExtraNames[];
extern char *gSpecialBuildingNames[];
extern char *gNeutralBuildingNames[];
extern char *gDwellingNames[][12];
extern unsigned long gTownEligibleBuildMask[];

int BuildingBuilt(town*, int);
char *__fastcall GetBuildingName(int faction, int building);

extern townManager* gpTownManager;

#pragma pack(pop)

#endif