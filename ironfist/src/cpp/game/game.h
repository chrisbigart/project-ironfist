#ifndef GAME_H
#define GAME_H

#include "adventure/adv.h"
#include "adventure/map.h"
#include "town/town.h"

#define NUM_PLAYERS 6
#define MAX_HEROES 54
#define MAX_TOWNS 72

extern signed char gcColorToPlayerPos[];

extern int gbHumanPlayer[];

extern void * hmnuDflt;
extern class font * bigFont;
extern class icon * gShingleAnim;
extern int giTCPHostStatus;
//extern DWORD gbthisaNetHumanPlayer;
extern int gGameCommand;
//extern signed char * gbThisNetHumanPlayer;
extern int gbTCPFirstTime;
extern int giMenuCommand;
extern class heroWindow * gpInitWin;
extern int gbInSetupDialog;
extern int gbWaitForRemoteReceive;
extern void* gpWindowManagerDoDialog;
extern unsigned char giSetupGameType;
extern int gMapX;
extern int gMapY;
extern int gbRemoteOn;
extern int gbCampaignSideChoice;
extern unsigned char xIsPlayingExpansionCampaign;
//extern DWORD gbGamePosToNetPos;
extern int giThisNetPos;
extern signed char gbGamePosToNetPos[];
extern int gbShowHighScore;
//?cPlayerNames@@3PAY0BF@DA
//char* cPlayerNames[21];
extern char cPlayerNames[6][21];
//extern char** cPlayerNames;
extern int gbGameInitialized;
extern class highScoreManager * gpHighScoreManager;
extern char ** gColors;
extern int iLastDiffSendTo;
extern struct configStruct gConfig;
extern int giHighScoreRank;
extern int giThisGamePos;
//extern int gbGamePosToNetPos;
extern struct SNetPlayerInfo * gsNetPlayerInfo;
//extern int gbGamePosToNetPos;
//extern int gbGamePosToNetPos;
//extern int githisaGamePos;
extern char gbUseDiffCompression;
extern int giHighMemBuffer;
extern int iLastMsgNumHumanPlayers;
extern unsigned int byte_526CFA;
extern char* byte_526CFB;
extern char gbUseRegularCompression;
extern int iLastMsgNumHumanPlayers;
extern int iMPBaseType;
extern int iMPNetProtocol;
extern int iMPExtendedType;
extern int giTCPType;
extern int iMPExtendedType;
extern int iMPExtendedType;
//extern int cPlayerNames;
extern int byte_50CE04;
extern int gbInCampaign;
extern int giCurWatchPlayer;
extern int gbthisaNetHumanPlayer;
extern unsigned char giCurWatchPlayerBit;
extern int giEndSequence;
extern int bForceCheckTimeEvent;

extern int giCurExe;

extern void __fastcall SetPalette(signed char *a1, int a2);

#pragma pack(push,1)

extern char* gAlignmentNames[];

#define BUILDING_RIGHT_TURRET_BUILT     0x1
#define BUILDING_LEFT_TURRET_BUILT      0x2
#define BUILDING_SPECIAL_DEFENSE_BUILT  0x20



/*
class executive
	{
	public:
		//baseManager *firstManager;
		//baseManager *lastManager;
		//baseManager *currentManager;
		//unsigned long field_C;
		char _[16];
		void MainLoop();
		void MainLoop_orig();
	};*/

class executive
	{
	public:
		char _[16];
		//unsigned long field_C;
		executive();
		void MainLoop_orig();
		void MainLoop();
		int InitSystem(void);
		int AddManager(class baseManager *, int);
		void RemoveManager(class baseManager *);
	};

extern executive* gpExec;

class playerData {
public:
	char color;
	char numHeroes;
	char curHeroIdx;
	char field_3;
	char heroesOwned[8];
	char heroesForPurchase[2];
	char _2;
	int personality;
	char _3[45];
	char field_40;
	__int16 field_41;
	char field_43;
	char numCastles;
	__int16 field_45;
	char castlesOwned[MAX_TOWNS];
	int resources[7];
    char _4_1;
    char barrierTentsVisited;
    char _4_2[58];
	int field_E7[7];
	char _5[23];
	char field_11A;

	void Read(int);
	void Write(int);

	int NextHero(int);
};

extern int giCurPlayer;
extern playerData* gpCurPlayer;

struct mine
{
	char field_0;
	char owner;
	char type;
	char guardianType;
	char guadianQty;
	char x;
	char y;
};

struct boat
{
	char idx;
	char x;
	char y;
	char field_3;
	char underlyingObjType;
	char underlyingObjExtra;
	char field_6;
	char owner;
};

class game {
public:
	__int16 gameDifficulty;
	char field_2;
	char field_3;
	char field_4;
	char _1[120];
	char field_7D;
	char hasDwarfAlliance;
	char field_7F;
	char field_80;
	char field_81;
	char field_82;
	char field_83;
	char field_84;
	char field_85;
	char isDwarfbane;
	char hasDragonAlliance;
	char field_88;
	char _11[193];
	char lastSaveFile[251];
	char _12[100];
	SMapHeader mapHeader;
	int field_44D;
	__int16 field_451;
	char playerHandicap[6];
	char field_459[6];
	char field_45F[6];
	char difficulty;
	char mapFilename[40];
	char numPlayers;
	char couldBeNumDefeatedPlayers;
	char playerDead[NUM_PLAYERS];
	__int16 day;
	__int16 week;
	__int16 month;
	playerData players[NUM_PLAYERS];
	fullMap map;
	char numObelisks;
	town castles[MAX_TOWNS];
	char field_2773[72];
	char field_27BB[9];
	hero heroes[MAX_HEROES];
	char relatedToHeroForHireStatus[54];
	mine mines[144];
	char field_60A6[144];
	char artifactGeneratedRandomly[103];
	boat boats[48];
	char boatBuilt[48];
	char obeliskVisitedMasks[48];
	char field_637D[24];
	char field_6395;
	char field_6396;
	char field_6397;
	int field_6398;
	char _B[14];
	char currentRumor[301];
	__int16 numRumors;
	__int16 rumorIndices[30];
	__int16 numEvents;
	char eventIndices[60];
	char _C[40];
	__int16 field_657B;
	char _D[140];
	int (__thiscall *callback)(tag_message *);
	char field_660D;
	char field_660E;

    // New state
    //bool sharePlayerVision[NUM_PLAYERS][NUM_PLAYERS];

	int NewGame(void);
	int SetupGame();
	int SetupGame_orig();
	void SetupTowns();
	void InitEntireCampaign(int);
	void InitCampaignMap(void);

	void RandomizeHeroPool();
	void SetRandomHeroArmies(int,int);

	void CheckHeroConsistency();
	int GetRandomNumTroops(int);
	void GiveTroopsToNeutralTown(int);
	void LoadGame(char*, int, int);
	void LoadGame_orig(char*, int, int);
	void NewMap(char*);
	void NewMap_orig(char*);
	int SaveGame(char*, int, signed char);
	void SetupOrigData();
	void SetMapSize(int, int);
	void SetupAdjacentMons();
	int SetupPuzzlePieces(int, int);
	void SetVisibility(int,int,int,int);
    void SetVisibility_orig(int, int, int, int);

	void ShowHeroesLogo();
	void ShowHeroesLogo_orig();

	int HandleCampaignWin(void);
	void CheckForTimeEvent(void);

	int TransmitSaveGame(int, int, int);

	int IsMobile(int);
	
	int PickLoadGame(void);
	
	void ClaimTown(int,int,int);

	void NextPlayer();
	void NextPlayer_orig();

	void PerDay();
	void PerDay_orig();

    void ResetIronfistGameState();
    void ShareVision(int sourcePlayer, int destPlayer);

	void RestoreCell(int, int, int, int, class mapCell *, int);

    void MakeAllWaterVisible(int player);
    void MakeAllWaterVisible_orig(int player);

private:
    void PropagateVision();
};

extern game* gpGame;

extern int gbGameOver;

#pragma pack(pop)

#endif