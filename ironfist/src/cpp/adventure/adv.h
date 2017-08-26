#ifndef ADV_H
#define ADV_H

#include "gui/gui.h"
#include "resource/resources.h"

#include "base.h"

#define ORIG_SPELLS 65

#pragma pack(push, 1)

#define MAX_TOTAL_HEROES 48

extern bool draw_mask_0;
extern bool draw_mask_1;
extern bool draw_mask_2;
extern bool draw_mask_3;
extern bool draw_mask_4;
extern bool draw_mask_5;
extern bool draw_mask_6;

enum PRIMARY_SKILL
{
  PRIMARY_SKILL_ATTACK = 0,
  PRIMARY_SKILL_DEFENSE = 1,
  PRIMARY_SKILL_SPELLPOWER = 2,
  PRIMARY_SKILL_KNOWLEDGE = 3,
};

enum SECONDARY_SKILL
{
  SECONDARY_SKILL_PATHFINDING = 0,
  SECONDARY_SKILL_ARCHERY = 1,
  SECONDARY_SKILL_LOGISTICS = 2,
  SECONDARY_SKILL_SCOUTING = 3,
  SECONDARY_SKILL_DIPLOMACY = 4,
  SECONDARY_SKILL_NAVIGATION = 5,
  SECONDARY_SKILL_LEADERSHIP = 6,
  SECONDARY_SKILL_WISDOM = 7,
  SECONDARY_SKILL_MYSTICISM = 8,
  SECONDARY_SKILL_LUCK = 9,
  SECONDARY_SKILL_BALLISTICS = 10,
  SECONDARY_SKILL_EAGLE_EYE = 11,
  SECONDARY_SKILL_NECROMANCY = 12,
  SECONDARY_SKILL_ESTATES = 13,
};

class armyGroup
{
public:
  char creatureTypes[5];
  __int16 quantities[5];

  armyGroup() {
      for (int i = 0; i < ELEMENTS_IN(this->creatureTypes); i++) {
          this->creatureTypes[i] = -1;
      }

      for (int i = 0; i < ELEMENTS_IN(this->quantities); i++) {
          this->quantities[i] = 0;
      }
  };

  int Add(int,int,int);
};

class hero
{
public:
  __int16 spellpoints;
  char idx;
  char ownerIdx;
  char field_4;
  char field_5;
  char field_6;
  char field_7;
  char field_8;
  char field_9;
  char name[13];
  char factionID;
  char heroID;
  int x;
  int y;
  __int16 field_21;
  __int16 field_23;
  __int16 field_25;
  __int16 field_27;
  __int16 field_29;
  __int16 field_2B;
  __int16 occupiedObjType;
  __int16 occupiedObjVal;
  int mobility;
  int remainingMobility;
  int experience;
  __int16 oldLevel;
  char primarySkills[4];
  char field_43;
  char tempMoraleBonuses;
  char tempLuckBonuses;
  char field_46;
  int gazeboesVisited;
  int fortsVisited;
  int witchDoctorHutsVisited;
  int mercenaryCampsVisited;
  int standingStonesVisited;
  int treesOfKnowledgeVisited;
  int xanadusVisited;
  char randomSeed;
  char wisdomLastOffered;
  armyGroup army;
  char secondarySkillLevel[14];
  char skillIndex[14];
  int numSecSkillsKnown;
  
  /*
   * In order to put more space in the hero class for new spells,
   * we would need to decompile virtually the entire codebase, as doing so would also
   * change the size of the game class.
   *
   * We instead replace the statically-allocated spellsLearned array with a pointer to a dynamically-allocated one,
   * so that we only need to decompile the direct accesses.
   *
   * There ARE memory leaks associated with doing this. We've done much of what we can to avoid this,
   * but there's no easy way out, and the leak is upper-bounded by 3 kb every time you load a map
   */
  //char spellsLearned[65];
  char* spellsLearned;
  char _[ORIG_SPELLS - sizeof(char*)];

#define FIELD_AFTER_SPELLS_LEARNED artifacts
  char artifacts[14];
  int flags;
  char isCaptain;
  int field_E8;
#define LAST_SW_HERO_FIELD scrollSpell
  char scrollSpell[14];

  hero();
  ~hero(); //newly added
  void AddSpell(int);
  void AddSpell(int,int);
  int HasSpell(int);
  int GetNumSpells(int);
  int GetNthSpell(int,int);
  void UseSpell(int);
	  
  int HasArtifact(int);
  void TakeArtifact(int);

  signed char Stats(int);
  void SetSS(int,int);
  int CalcMobility();

  void Read(int, signed char);
  void ResetSpellsLearned();

  void SetPrimarySkill(int,int);

  void Clear();
};

enum HERO_FLAGS {
	HERO_AT_SEA = 0x80
};

char cHeroTypeInitial[];

class mapCell;
class fullMap;
class tileset;

class advManager : public baseManager {
public:
	int field_36;
	widget *someComponents[2][12];
	heroWindow *adventureScreen;
	int sizeOfSomethingMapRelated;
	int field_A2;
	int currentTerrain;
	int field_AA;
	fullMap *map;
	//iconWidget *heroScrollbarKnob;
	//iconWidget *castleScrollbarKnob;

	void *heroScrollbarKnob;
	void *castleScrollbarKnob;
	int field_BA;
	int field_BE;
	tileset *groundTileset;
	tileset *clofTileset;
	tileset *stonTileset;
	int field_CE[64];
	icon *radarIcon;
	icon *clopIcon;
	int viewX; //0x1D6 (470)
	int viewY; //0x1DA (474)
	int field_1DE;
	int field_1E2;
	int xOff;
	int yOff;
	int field_1EE;
	int field_1F2;
	int field_1F6;
	int field_1FA;
	int field_1FE;
	int field_202;
	int field_206;
	int field_20A;
	int field_20E;
	int field_212;
	int field_216;
	void *heroIcons[6];
	icon *boatIcon;
	icon *frothIcon;
	icon *shadowIcon;
	icon *boatShadowIcon;
	void *flagIcons1[6];
	void *flagIcons2[6];
	int field_272;
	int field_276;
	int field_27A;
	int field_27E;
	int field_282;
	int field_286;
	int field_28A;
	int field_28E;
	int field_292;
	int field_296;
	int field_29A;
	int field_29E;
	int field_2A2;
	int heroMobilized;
	int field_2AA;
	int field_2AE;
	int field_2B2;
	int field_2B6;
	int field_2BA;
	int field_2BE;
	int field_2C2[4][2];
	void *loopSamples[28];
	sample *walkSamples[9];
	int identifyCast;
	int field_37A;

	advManager();

	void Reseed(int, int);
	void SeedTo(int, int);

	int GetCursorBaseFrame(int);

	mapCell *GetCell(int x, int y);

	void PurgeMapChangeQueue();
	void CheckSetEvilInterface(int,int);
	
	void DemobilizeCurrHero();
	void DeactivateCurrTown();
	void DeactivateCurrHero();

	void DimensionDoor();
	void TeleportTo(hero*, int, int, int, int);

	void CastSpell(int);
	void CastSpell_orig(int);

	void FizzleCenter(int);
	void FizzleCenter_orig(int);

	int ComboDraw(int, int, int);
	int ComboDraw_orig(int, int, int);

	void CompleteDraw(int);
	void CompleteDraw(int left, int top, int a6, int a5);
	void CompleteDraw(int left, int top, int a6, int a5, int width, int height);
	void CompleteDraw_orig(int left, int top, int a6, int a5);

	void DrawCell(int, int, int, int, int, int);
	void DrawCell_orig(int, int, int, int, int, int);

	void ViewPuzzle();
	void ViewPuzzle_orig();
	void PuzzleDraw(int a2, int a3, int a4, int a5);
	void PuzzleDraw_orig(int a2, int a3, int a4, int a5);

	void DrawAdventureBorder();
	void DrawAdventureBorder_orig();
	void SaveAdventureBorder();
	void SaveAdventureBorder_orig();

	void SetEnvironmentOrigin(int, int, int);
	void SetEnvironmentOrigin_orig(int, int, int);

	int IsCrystalBallInEffect(int, int, int);

	void UpdBottomView(int, int, int);
	void UpdBottomView_orig(int, int, int);

	void HeroQuickView(int, int, int, int);
	void TownQuickView(int, int, int, int);
	void SetHeroContext_orig(int, int);
	void SetHeroContext(int, int);
	void SetTownContext_orig(int);
	void SetTownContext(int);
	void HideRoute(int, int, int);

	void DoHeroKnob(void);
	void DoTownKnob(void);
	void QuickInfo(int, int);
	void QuickInfo_orig(int, int);

	void ShowRoute(int, int, int);

	int ProcessSelect_orig(struct tag_message *, class mapCell * *);
	int ProcessSelect(struct tag_message *, class mapCell * *);
	int ProcessDeSelect_orig(struct tag_message *, int *, class mapCell * *);
	int ProcessDeSelect(struct tag_message *, int *, class mapCell * *);

	void RedrawAdvScreen(int,int);
	void RedrawAdvScreen_orig(int, int);

	void UpdateRadar_orig(int, int);
	void UpdateRadar(int, int);
	void UpdateScreen(int, int);
    void UpdateHeroLocator(int, int, int);
	void UpdateHeroLocators(int, int);
	void UpdateTownLocators(int, int);

	char* GetArmySizeName(int, int);
	int GetCloudLookup(int, int);
	mapCell* DoAdvCommand();
	void DoEvent(mapCell *loc, int locX, int locY);

    void EventSound(int locType, int locType2, SAMPLE2 *samp);

	virtual int Open(int);
	int Open_orig(int);

    void PasswordEvent(mapCell *tile, hero *hero);
    int BarrierEvent(mapCell *tile, hero *hero);
};

extern advManager* gpAdvManager;

extern int giMapChangeCtr;

extern heroWindow* heroWin;
extern int giHeroScreenSrcIndex;

hero* GetCurrentHero();

int __fastcall GiveArtifact(hero*, int artifact, int checkEndGame, signed char scrollSpell);

#pragma pack(push, 1)
struct PathfindingInfo
	{
	char field_0;
	char field_1;
	__int16 field_2;
	char field_4;
	int field_5;
	};
#pragma pack(pop)

#pragma pack(push, 1)
class searchArray //gpSearchArray is declared as 'class searchArray*' in asm
	{
	public:
		int field_0;
		int field_4;
		int field_8;
		char _1[8];
		PathfindingInfo mainDataStructure[1024];
		PathfindingInfo *field_2414;
		int field_2418;
		int field_241C[63];
	};
#pragma pack(pop)

extern searchArray* gpSearchArray;

#pragma pack(pop)

#endif