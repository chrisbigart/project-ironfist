#ifndef MAP_H
#define MAP_H

#include "adventure/adv.h"

#define MAX_TOWNS 72
#define MAX_PLACED_EVENTS 50
#define MAX_MINES 144

#pragma pack(push, 1)

extern unsigned char gTileTerrainTypes[];

class mapCell {
public:
  unsigned int groundIndex : 16;
  unsigned int hasObject : 1;
  unsigned int isRoad : 1;
  unsigned int objTileset : 6;
  signed int objectIndex : 8;
  unsigned int field_4_1 : 1;
  unsigned int isShadow : 1;
  unsigned int field_4_3 : 1;
  unsigned int extraInfo : 13;
  unsigned int hasOverlay : 1;
  unsigned int hasLateOverlay : 1;
  unsigned int overlayTileset : 6;
  signed int overlayIndex : 8;
  unsigned int displayFlags : 8;
  unsigned int objType : 8;
  unsigned int extraIdx : 16;
#ifdef EDITOR
  unsigned int objLink;
  unsigned int ovrLink;
#endif
};

struct mapCellExtra {
  __int16 nextIdx;
  unsigned int animatedObject : 1;
  unsigned int objTileset : 7;
  unsigned int objectIndex : 8;
  unsigned int field_4_1 : 1;
  unsigned int field_4_2 : 1;
  unsigned int field_4_3 : 1;
  unsigned int field_4_4 : 5;
  unsigned int animatedLateOverlay : 1;
  unsigned int hasLateOverlay : 1;
  unsigned int tileset : 6;

  // Cannot declare as "unsigned int : 8"; ran afoul of this:  http://stackoverflow.com/a/3919325/546591
  unsigned __int8 overlayIndex;
#ifdef EDITOR
  unsigned int objLink;
  unsigned int ovrLink;
#endif
};

class fullMap {
public:
	mapCell *tiles;
	mapCellExtra *cellExtras;
	int width;
	int height;
	int numCellExtras;
	fullMap();
	~fullMap();

	void Read(int,int);
	void Write(int);

	mapCellExtra* GetNewCellExtraOverlay(int x, int y);
	mapCellExtra* GetNewCellExtraObject(int x, int y);
	void MoveInfoToCellExtra(int x, int y);
};


struct SMapHeader {
	int field_0;
	__int16 field_4;
	char width;
	char height;
	char hasPlayer[6];
	char playerMayBeHuman[6];
	char playerMayBeComp[6];
	char numPlayers;
	char minHumans;
	char maxHumans;
	char winConditionType;
	char field_1E;
	char allowDefeatAllVictory;
	__int16 winConditionArgument;
	char field_22;
	char field_23;
	char field_24;
	char noStartingHeroInCastle;
	char playerFactions[6];
	__int16 field_2C;
	int field_2E;
	int field_32;
	char field_36;
	char field_37;
	char nextTownName;
	char field_39;
	char name[60];
	char description[298];
	char field_1A0;
	char field_1A1;
	char numRumors;
	char numEvents;
};


extern int MAP_HEIGHT;
extern int MAP_WIDTH;

extern unsigned char* mapRevealed;

int MapCellVisible(int x, int y, int player);
void RevealMapCell(int x, int y, int player);

extern int iMaxMapExtra;
extern void** ppMapExtra;
extern short* pwSizeOfMapExtra;

extern signed char xIsExpansionMap;

extern void __fastcall ClearMapExtra();


struct TownExtra {
    TownExtra() {
        memset(this, 0, sizeof(TownExtra));
    }

  char color;
  char customBuildings;
  int buildingsBuilt;
  char mageGuildLevel;
  char customGarrison;
  armyGroup garrison;
  char hasCaptain;
  char customName;
  char name[13];
  char faction;
  char isCastle;
  char disallowCastle;
  char _[25];
  char field_42;
  char field_43;
  char field_44;
  char field_45;
};

class SignExtra {
public:

  SignExtra() {
      memset(this, 0, sizeof(SignExtra));
      this->field_0 = 1;
  }

  char field_0;
  int field_1;
  int field_5;
  char message;
};

class EventExtra {
public:

  EventExtra() {
      memset(this, 0, sizeof(EventExtra));
      this->field_0 = 1;
      this->artifactReward = -1;
      this->cancelAfterFirstVisit = 1;
      for (int c = 0; c < ELEMENTS_IN(this->colorCanSee); c++) {
          this->colorCanSee[c] = 1;
      }
  }

  char field_0;
  int resourceReward[7];
  __int16 artifactReward;
  char field_1F;
  char cancelAfterFirstVisit;
  char field_21;
  char field_22;
  char field_23;
  char field_24;
  char unclaimed;
  __int16 x;
  __int16 y;
  char field_2A;
  char colorCanSee[6];
  char message;
};

struct SphinxExtra {

  SphinxExtra() {
      memset(this, 0, sizeof(SphinxExtra));
      this->artifactReward = -1;
  }

  char unclaimed;
  int resourceReward[7];
  __int16 artifactReward;
  unsigned __int8 numAnswers;
  char answers[8][13];
  char riddle;
};

class HeroExtra {
public:
    HeroExtra() {
        memset(this, 0, sizeof(HeroExtra));
    }

  char owner;
  char field_1;
  armyGroup army;
  char field_11;
  char field_12;
  char artifacts[3];
  char field_16;
  char field_17;
  char field_18;
  char field_19;
  char field_1A;
  char field_1B;
  char secondarySkills[8];
  char firstSecondarySkillLevel;
  char secondSecondarySkillLevel;
  char field_26;
  char field_27;
  char field_28[20];
  char field_3C;
  char field_3D;
  char field_3E;
  char field_3F;
  char field_40;
  char field_41;
  char field_42;
  char field_43;
  char field_44;
  char field_45;
  char field_46;
  char field_47;
  char field_48;
  char field_49;
  char field_4A;
  char field_4B;
};

enum ADVENTURE_MAP_LOCATION {
  LOCATION_ALCHEMIST_LAB = 1,
  LOCATION_SIGN = 2,
  LOCATION_BUOY = 3,
  LOCATION_SKELETON = 4,
  LOCATION_DAEMON_CAVE = 5,
  LOCATION_TREASURE_CHEST = 6,
  LOCATION_FAERIE_RING = 7,
  LOCATION_CAMPFIRE = 8,
  LOCATION_FOUNTAIN = 9,
  LOCATION_GAZEBO = 10,
  LOCATION_ANCIENT_LAMP = 11,
  LOCATION_GRAVEYARD = 12,
  LOCATION_ARCHERS_HOUSE = 13,
  LOCATION_GOBLIN_HUT = 14,
  LOCATION_DWARF_COTTAGE = 15,
  LOCATION_PEASANT_HUT = 16,
  LOCATION_LOG_CABIN = 17,
  LOCATION_ROAD = 18,
  LOCATION_EVENT = 19,
  LOCATION_DRAGON_CITY = 20,
  LOCATION_LIGHTHOUSE = 21,
  LOCATION_WATERWHEEL = 22,
  LOCATION_MINE = 23,
  LOCATION_ARMY_CAMP = 24,
  LOCATION_OBELISK = 25,
  LOCATION_OASIS = 26,
  LOCATION_RESOURCE = 27,
  LOCATION_SAWMILL = 29,
  LOCATION_ORACLE = 30,
  LOCATION_SHRINE_FIRST = 31,
  LOCATION_SHIPWRECK = 32,
  LOCATION_SEA_CHEST = 33,
  LOCATION_DESRT_TENT = 34,
  LOCATION_TOWN = 35,
  LOCATION_STONE_LITHS = 36,
  LOCATION_WAGON_CAMP = 37,
  LOCATION_WELL = 38,
  LOCATION_WHIRLPOOL = 39,
  LOCATION_WINDMILL = 40,
  LOCATION_ARTIFACT = 41,
  LOCATION_HERO = 42,
  LOCATION_BOAT = 43,
  LOCATION_ULTIMATE_ARTIFACT = 44,
  LOCATION_RANDOM_ARTIFACT = 45,
  LOCATION_RANDOM_RESOURCE = 46,
  LOCATION_RANDOM_MONSTER = 47,
  LOCATION_RANDOM_TOWN = 48,
  LOCATION_RANDOM_CASTLE = 49,
  LOCATION_RANDOM_MONSTER_WEAK = 51,
  LOCATION_RANDOM_MONSTER_MEDIUM = 52,
  LOCATION_RANDOM_MONSTER_STRONG = 53,
  LOCATION_RANDOM_MONSTER_VERY_STRONG = 54,
  LOCATION_RANDOM_HERO = 55,
  LOCATION_NOTHING_SPECIAL = 56,
  LOCATION_WATCH_TOWER = 58,
  LOCATION_TREE_HOUSE = 59,
  LOCATION_TREE_CITY = 60,
  LOCATION_RUINS = 61,
  LOCATION_FORT = 62,
  LOCATION_TRADING_POST = 63,
  LOCATION_ABANDONED_MINE = 64,
  LOCATION_DWARF_CABIN = 65,
  LOCATION_STANDING_STONES = 66,
  LOCATION_IDOL = 67,
  LOCATION_TREE_OF_KNOWLEDGE = 68,
  LOCATION_WITCH_DOCTORS_HUT = 69,
  LOCATION_TEMPLE = 70,
  LOCATION_HILL_FORT = 71,
  LOCATION_HALFLING_HOLE = 72,
  LOCATION_MERCENARY_CAMP = 73,
  LOCATION_SHRINE_SECOND_ORDER = 74,
  LOCATION_SHRINE_THIRD_ORDER = 75,
  LOCATION_PYRAMID = 76,
  LOCATION_CITY_OF_DEAD = 77,
  LOCATION_EXCAVATION = 78,
  LOCATION_SPHINX = 79,
  LOCATION_WAGON = 80,
  LOCATION_TAR_PIT = 81,
  LOCATION_ARTESIAN_SPRING = 82,
  LOCATION_TROLL_BRIDGE = 83,
  LOCATION_WATERING_HOLE = 84,
  LOCATION_WITCH_HUT = 85,
  LOCATION_XANADU = 86,
  LOCATION_CAVE = 87,
  LOCATION_LEAN_TO = 88,
  LOCATION_MAGELLANS_MAPS = 89,
  LOCATION_FLOTSAM = 90,
  LOCATION_DERELICT_SHIP = 91,
  LOCATION_SHIPWRECK_SURVIVOR = 92,
  LOCATION_BOTTLE = 93,
  LOCATION_MAGIC_WELL = 94,
  LOCATION_MAGIC_GARDEN = 95,
  LOCATION_OBSERVATION_TOWER = 96,
  LOCATION_FREEMANS_FOUNDRY = 97,
  LOCATION_STREAM = 98,
  LOCATION_TREES = 99,
  LOCATION_MOUNTAINS = 100,
  LOCATION_VOLCANO = 101,
  LOCATION_FLOWERS = 102,
  LOCATION_ROCK = 103,
  LOCATION_LAKE = 104,
  LOCATION_MANDRAKE = 105,
  LOCATION_DEAD_TREE = 106,
  LOCATION_STUMP = 107,
  LOCATION_CRATER = 108,
  LOCATION_CACTUS = 109,
  LOCATION_MOUND = 110,
  LOCATION_DUNE = 111,
  LOCATION_LAVA_POOL = 112,
  LOCATION_SHRUB = 113,
  LOCATION_HOLE = 114,
  LOCATION_OUTCROPPING = 115,
  LOCATION_RANDOM_ARTIFACT_TREASURE = 116,
  LOCATION_RANDOM_ARTIFACT_MINOR = 117,
  LOCATION_RANDOM_ARTIFACT_MAJOR = 118,
  LOCATION_BARRIER = 119,
  LOCATION_TRAVELLER_TENT = 120,
  LOCATION_EXPANSION_DWELLING = 121,
  LOCATION_ALCHEMIST_TOWER = 122,
  LOCATION_JAIL = 123,
  TILE_HAS_EVENT = 128,
};

#pragma pack(pop)

#endif