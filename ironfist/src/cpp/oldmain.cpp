#include <cstring>
#include <cstdio>

#include "gui/gui.h"
#include "game/game.h"
#include "manager.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"
#include "gui/dialog.h"

extern int bKBDone;
extern void __fastcall ShutDown(char *);
extern void __fastcall KBChangeMenu(void *);
extern void __fastcall SetupCDRom(void);
extern int __fastcall CheckMem(void);
extern void __fastcall LoadSystemwideIcons(void);
extern int __fastcall PlaySmacker(int);
extern int __fastcall InitMenuHandler(struct tag_message &);
extern int __fastcall NetPosToGamePos(int);
extern void __fastcall RemoteMain(int);
extern void __fastcall ComputeAdvNetControl(void);
extern int __fastcall TransmitRemoteData(char *, int, int, signed char, signed char, signed char, signed char);
extern void __fastcall ShutDown(char *);
extern void __fastcall RemoteCleanup(void);

extern executive* gpExec;
extern inputManager* gpInputManager;
extern mouseManager* gpMouseManager;
extern heroWindowManager* gpWindowManager;
extern resourceManager* gpResourceMAnager;
extern soundManager* gpSoundManager;

class ExpCampaign
	{
	public:
		int HandleVictory(void);
		void InitMap(void);
		signed char IsThisMapCompleted(void);
		void RemoveManager(class baseManager *);
		int AddManager(class baseManager *, int);
	};

ExpCampaign* xCampaign;

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
extern signed char * gbGamePosToNetPos;
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

int __fastcall oldmain(void)
	{
	char *v1; // ST1C_4@153
	signed int v2; // eax@153
	int v3; // eax@172
	const char *v4; // ST1C_4@198
	int v5; // ebx@198
	__int16 v6; // ax@198
	//heroWindow *thisa; // [sp+24h] [bp-14Ch]@52
	signed int v8; // [sp+28h] [bp-148h]@184
	bool v9; // [sp+28h] [bp-148h]@197
	char v10; // [sp+2Ch] [bp-144h]@122
	char v11; // [sp+32h] [bp-13Eh]@131
	char v12; // [sp+33h] [bp-13Dh]@131
	char v13; // [sp+34h] [bp-13Ch]@122
	char v14[8]; // [sp+12Ch] [bp-44h]@92
	int j; // [sp+134h] [bp-3Ch]@92
	int k; // [sp+138h] [bp-38h]@96
	char v17[8]; // [sp+13Ch] [bp-34h]@92
	int v18; // [sp+144h] [bp-2Ch]@68
	int v19; // [sp+148h] [bp-28h]@11
	int v20; // [sp+154h] [bp-1Ch]@14
	int i; // [sp+158h] [bp-18h]@62
	int v22; // [sp+15Ch] [bp-14h]@133
	int mainMenuButton; // [sp+164h] [bp-Ch]@3
	int v24; // [sp+168h] [bp-8h]@14
	int v25; // [sp+16Ch] [bp-4h]@14

	if(bKBDone)
		return 0;
	bKBDone = 1;
	LogStr("OM1");
	LogStr("OM2");
	mainMenuButton = -1;
	if(gpExec->InitSystem())
		ShutDown("Initialization failed!");
	LogStr("OM3");
	
	KBChangeMenu(hmnuDflt);

	gPalette = (palette *)gpResourceManager->GetPalette("kb.pal");
	gpWindowManager->cycleColors = 1;
	smallFont = gpResourceManager->GetFont("smalfont.fnt");
	bigFont = gpResourceManager->GetFont("bigfont.fnt");
	gpMouseManager->SetPointer("advmice.mse", 0, -999);
	//gpMouseManager->SetColorMice(*(&bMenu + 7 * giCurExe + 6));
	LogStr("OM4");
	SetupCDRom();
	LogStr("OM5");
	//if((**(int(__thisacall ***)(_DWORD))gpSoundManager)(gpSoundManager))
	if(gpSoundManager->Open(0xffffffff))
		ShutDown("Unable to initialize sound.");

	if(giDebugLevel < 9)
		CheckMem();
	LogStr("OM6");
	/*if(giShowIntro)
		{
		FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 640u, 480, 0);
		BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
		if(!gbSkipIntro)
			{
			v19 = gpWindowManager->cycleColors;
			gpWindowManager->cycleColors = 0;
			if(PlaySmacker(66))
				PlaySmacker(1);
			PlaySmacker(65);
			gpWindowManager->cycleColors = v19;
			}
		}*/
	LoadSystemwideIcons();
	memset(gbThisNetHumanPlayer, 0, 6u);
	gpMouseManager->ShowColorPointer();
	v25 = 0;
	v20 = 0;
	v24 = 1;
LABEL_15:
	if(!v25)
		{
		while(1)
			{
			do
				{
				while(1)
					{
				LABEL_16:
					if(!gShingleAnim)
						gShingleAnim = gpResourceManager->GetIcon("shnganim.icn");
					if(gGameCommand != 105)
						gpSoundManager->SwitchAmbientMusic(42);
					if(!v20)
						{
						if(gGameCommand != 105)
							{
							gpResourceManager->GetBackdrop("heroes.icn", gpWindowManager->screenBuffer, 1);
							gpWindowManager->UpdateScreenRegion(0, 0, 0x280u, 480);
							if(v24)
								SetPalette(gPalette->contents, 1);
							else
								gpWindowManager->FadeScreen(0, 8, gPalette);
							v24 = 0;
							}
						gpMouseManager->SetPointer("advmice.mse", 0, -999);
						}
					v20 = 1;
					if(gGameCommand != 105)
						gpWindowManager->cycleColors = 1;
					if(giTCPHostStatus == -1 || !gbTCPFirstTime)
						{
						if(giMenuCommand != -1)
							goto LABEL_48;
						if(gGameCommand == -1)
							{
							//thisa = (heroWindow *)operator new(68);
							//if(thisa)
							//gpInitWin = new heroWindow(0, 0, "stpmain.bin");
							gpInitWin = new heroWindow(80, 0, "stpmain.bin");
							//else
							//	gpInitWin = 0;
							if(!gpInitWin)
								MemError();
							gbInSetupDialog = 1;
							gpWindowManager->DoDialog(
								(heroWindow*)gpInitWin,
								//(int(__fastcall *)(tag_message *))InitMenuHandler,
								InitMenuHandler,
								0);
							operator delete(gpInitWin);
							gpInitWin = 0;
							mainMenuButton = gpWindowManager->buttonPressedCode;
							gbInSetupDialog = 0;
							}
						else
							{
							mainMenuButton = gGameCommand;
							gGameCommand = -1;
							}
						goto LABEL_58;
						}
					gbTCPFirstTime = 0;
					iLastMsgNumHumanPlayers = 1;
					iMPBaseType = 1;
					iMPNetProtocol = 2;
					iMPExtendedType = giTCPHostStatus ? 1 : 2;
					giSetupGameType = giTCPType;
					RemoteMain(iMPExtendedType);
					gbWaitForRemoteReceive = iMPExtendedType == 2;
					giTCPHostStatus = -1;
					if(!giSetupGameType)
						break;
					if((unsigned __int8)giSetupGameType != 1 || gpGame->PickLoadGame())
						goto LABEL_58;
					}
				} while(!gpGame->NewGame());
			LABEL_58:
				if(giMenuCommand != -1)
					goto LABEL_48;
				switch(mainMenuButton)
					{
					case 102:
						giSetupGameType = 1;
						goto LABEL_62;
					case 101:
						giSetupGameType = 0;
					LABEL_62:
						for(i = 0; i < 6; ++i)
							{
							//sprintf(cPlayerNames[i], byte_50CE04);
							//sprintf(cPlayerNames[i], "\0\0\0\0");
							}
						if(!gpGame->SetupGame())
							goto LABEL_16;
						if(!giSetupGameType)
							{
							if(gbInCampaign)
								{
								//gpGame->InitEntireCampaign(gbCampaignSideChoice[0]);
								gpGame->InitEntireCampaign(gbCampaignSideChoice);
								v18 = gpGame->HandleCampaignWin();
								if(v18)
									{
									gpGame->InitCampaignMap();
									goto LABEL_147;
									}
								gpWindowManager->FadeScreen(1, 8, gPalette);
								v20 = 0;
								}
							else if(xIsPlayingExpansionCampaign)
								{
								if(xCampaign->HandleVictory())
									{
									xCampaign->InitMap();
									goto LABEL_147;
									}
								gpWindowManager->FadeScreen(1, 8, gPalette);
								v20 = 0;
								}
							else
								{
								LogStr("New Game 1");
								if(gpGame->NewGame())
									{
									LogStr("New Game 2");
									goto LABEL_88;
									}
								}
							goto LABEL_16;
							}
						if((unsigned __int8)giSetupGameType != 1)
							{
						LABEL_88:
							while(giMenuCommand != -1)
								{
							LABEL_48:
								switch(giMenuCommand)
									{
									case 40123:
									case 40124:
									case 40127:
									case 40128:
									case 40129:
									case 40131:
									case 40132:
									case 40134:
									case 40135:
									case 40137:
									case 40138:
										if(gpGame->PickLoadGame())
											goto LABEL_88;
										goto LABEL_16;
									case 40102:
									case 40104:
									case 40105:
									case 40106:
									case 40107:
									case 40110:
									case 40111:
									case 40112:
									case 40114:
									case 40115:
									case 40117:
									case 40118:
									case 40120:
									case 40121:
										if(gpGame->NewGame())
											goto LABEL_88;
										goto LABEL_16;
									default:
										goto LABEL_88;
									}
								}
							LogStr("DWM 1");
							if(!v25)
								{
								LogStr("DWM 2");
								if(gbRemoteOn && !giThisNetPos)
									{
									LogStr("DWM 3");
									memset(v17, 0, 6u);
									memset(v14, 0, 6u);
									for(j = 0; j < 6; ++j)
										{
										if(gbHumanPlayer[j])
											{
											for(k = 0; k < 6; ++k)
												{
												if(strlen(&gpGame->field_637D[4 * k]) == 3
												   //&& !strcmp((int)&gpGame->field_637D[4 * k], (int)((char *)&gsNetPlayerInfo + 34 * j)) //FIXME
												   && !gpGame->playerDead[k]
												   && !v17[k])
													{
													if(!v14[j])
														{
														v17[k] = 1;
														v14[j] = 1;
														gbGamePosToNetPos[k] = j;
														}
													}
												}
											}
										}
									for(k = 0; k < 6 && v17[k]; ++k)
										;
									for(j = 0; j < 6; ++j)
										{
										if(!v14[j])
											{
											if(gbHumanPlayer[j])
												{
												gbGamePosToNetPos[j] = k;
												strcpy(&gpGame->field_637D[4 * k++], (char *)&gsNetPlayerInfo + 34 * j);
												while(k < 6 && v17[k])
													++k;
												}
											else
												{
												gbGamePosToNetPos[j] = -1;
												}
											}
										}
									memcpy(&v10, gbGamePosToNetPos, 6u);
									memcpy(&v13, &gsNetPlayerInfo, 0xCCu);
									giThisGamePos = NetPosToGamePos(0);
									gbUseDiffCompression = 1;
									gbUseRegularCompression = 1;
									if(giHighMemBuffer < 6000)
										gbUseRegularCompression = 0;
									for(i = 0; i < iLastMsgNumHumanPlayers; ++i)
										{
										//if(!((char*)byte_526CFA)[34 * i])
											gbUseRegularCompression = 0;
										//if(!byte_526CFB[34 * i])
											gbUseDiffCompression = 0;
										}
									v11 = gbUseRegularCompression;
									v12 = gbUseDiffCompression;
									for(i = 1; i < iLastMsgNumHumanPlayers; ++i)
										{
										v22 = TransmitRemoteData(&v10, i, 0xD4u, 32, 1, 1, -1);
										if(!v22)
											ShutDown(0);
										}
									for(i = 1; i < iLastMsgNumHumanPlayers; ++i)
										{
										if(gpGame->TransmitSaveGame(i, 0, 1))
											ShutDown(0);
										}
									memset(gbThisNetHumanPlayer, 0, 6u);
									gbThisNetHumanPlayer[giThisGamePos] = 1;
									iLastDiffSendTo = -1;
									gpGame->SaveGame((char *)&gConfig + 314, 0, 0);
									}
								LogStr("DWM 4");
								if(gbRemoteOn && gbWaitForRemoteReceive)
									{
									/*LogStr("DWM 5");
									giWaitType = 0;
									NormalDialog("Waiting to receive game data.", 6, -1, -1, -1, 0, -1, 0, -1, 0);
									if(!gbFunctionComplete)
										ShutDown(0);
									char *)&gConfig + 327->LoadGame(gpGame, (0, 1);
									sprintf(gpGame->lastSaveFile, "NEWGAME");
									iLastDiffSendTo = -1;
									const char *)&gConfig + 353->SaveGame(gpGame, (0, 0);*/
									}
								goto LABEL_147;
								}
						LABEL_177:
							if(gbGameOver)
								{
								while(1)
									{
									RemoteCleanup();
									bShowIt = 1;
									gpMouseManager->SetPointer("advmice.mse", 0, -999);
									//sprintf(
									//	gcWinText,
									//	"My heroes, our foes have been scattered, their castles broken and laid bare.  The great campaign is now complete, and I stand before you as the undisputed High King!\n\nOur victory was achieved in %d days!",
									//	giCurTurn);
									if(giEndSequence != 1)
										break;
									/*if(gbInCampaign)
										{
										v8 = gpGame->HandleCampaignWin();
										if(gpGame->field_4 == 10 && gpGame->_1[12 * gpGame->field_2 + 10]
										   || gpGame->field_4 == 9 && !gpGame->field_2 && gpGame->_1[12 * gpGame->field_2 + 9])
											{
											gbShowHighScore = 1;
											ShowCongrats(0);
											AddScoreToHighScore(
												*(_WORD *)&gpGame->_11[49],
												*(_WORD *)&gpGame->_11[49],
												0,
												0,
												&aArchibald[("Roland" - "Archibald") & ((gpGame->field_2 == 1) - 1)]);
											}
										if(!v8)
											goto LABEL_208;
										for(i = 0; i < 6; ++i)
											sprintf(cPlayerNames[i], byte_50CFB4);
										gpGame->InitCampaignMap();
										gbGameOver = 0;
										bForceCheckTimeEvent = 1;
										}
									else
										{
										if(!xIsPlayingExpansionCampaign)
											{
											ShowCongrats((void *)1);
											if(gbShowHighScore)
												{
												gpSoundManager->PlayAmbientMusic(43, 0, -1);
												}
											else
												{
												gpWindowManager->FadeScreen(1, 8, gPalette);
												gpResourceManager->GetBackdrop("heroes.icn", gpWindowManager->screenBuffer, 1);
												gpWindowManager->UpdateScreenRegion(0, 0, 0x280u, 480);
												gpWindowManager->FadeScreen(0, 8, gPalette);
												gpWindowManager->cycleColors = 1;
												v20 = 1;
												gpSoundManager->PlayAmbientMusic(42, 0, -1);
												}
											goto LABEL_208;
											}
										v9 = ExpCampaign::HandleVictory((int)&xCampaign);
										if(ExpCampaign::IsCompleted((int)&xCampaign))
											{
											gbShowHighScore = 1;
											ShowCongrats((void *)2);
											v4 = (&xHSCampaignNames)[4 * ExpCampaign::CampaignID(&xCampaign)];
											v5 = (signed __int16)ExpCampaign::Days((int)&xCampaign);
											v6 = ExpCampaign::Days((int)&xCampaign);
											AddScoreToHighScore(v6, v5, 0, 2, v4);
											}
										if(!v9)
											goto LABEL_208;
										for(i = 0; i < 6; ++i)
											sprintf(cPlayerNames[i], byte_50CFB8);
										ExpCampaign::InitMap((int)&xCampaign);
										gbGameOver = 0;
										bForceCheckTimeEvent = 1;
										}*/
								LABEL_147:
									gpWindowManager->cycleColors = 1;
									if(gShingleAnim)
										gpResourceManager->Dispose((resource *)gShingleAnim);
									gShingleAnim = 0;
									if(iLastMsgNumHumanPlayers > 1)
										{
										for(i = 0; i < iLastMsgNumHumanPlayers; ++i)
											{
											if(iMPBaseType != 2)
												{
												v1 = (char *)&gsNetPlayerInfo + 34 * i + 4;
												v2 = NetPosToGamePos(i);
												strcpy(cPlayerNames[v2], v1);
												}
											}
										}
									for(i = 0; gpGame->numPlayers > i; ++i)
										{
										if(!strlen(cPlayerNames[i]))
											{
											sprintf(cPlayerNames[i], "%s player", (&gColors)[4 * gpGame->players[i].color]);
											cPlayerNames[i][0] -= 32;
											}
										}
									ComputeAdvNetControl();
									gbGameInitialized = 1;
									v20 = 0;
									gpSoundManager->StopAllSamples(1);
									gpWindowManager->FadeScreen(1, 8, 0);
									gMapX = 0;
									gMapY = 0;
									for(giCurWatchPlayer = giCurPlayer;
										!gbThisNetHumanPlayer[giCurWatchPlayer];
										giCurWatchPlayer = (giCurWatchPlayer + 1) % gpGame->numPlayers)
										;
									giCurWatchPlayerBit = 1 << giCurWatchPlayer;
									if(gbInCampaign && gpGame->_11[71])
										{
										giEndSequence = 1;
										}
									else
										{
										if(!xIsPlayingExpansionCampaign || !xCampaign->IsThisMapCompleted())
											{
											if(gpExec->AddManager(gpAdvManager, -1))
												ShutDown("Can't add manager!");
											if(mainMenuButton == 101)
												{
												v3 = gpGame->players->NextHero(0);
												gpAdvManager->SetHeroContext(v3, 0);
												}
											if(mainMenuButton == 101 || bForceCheckTimeEvent)
												{
												bForceCheckTimeEvent = 0;
												gpGame->CheckForTimeEvent();
												}
											gpExec->MainLoop();
											gMapX = gpAdvManager->viewX;
											gMapY = gpAdvManager->viewY;
											gpExec->RemoveManager((baseManager *)gpAdvManager);
											gpWindowManager->FadeScreen(1, 8, gPalette);
											goto LABEL_177;
											}
										giEndSequence = 1;
										}
									}
								gpWindowManager->cycleColors = 0;
								if(xIsExpansionMap)
									PlaySmacker(64);
								else
									PlaySmacker(3);
								gpWindowManager->FadeScreen(1, 128, gPalette);
								gpResourceManager->GetBackdrop("heroes.icn", gpWindowManager->screenBuffer, 1);
								gpWindowManager->UpdateScreenRegion(0, 0, 0x280u, 480);
								gpWindowManager->FadeScreen(0, 8, gPalette);
								gpWindowManager->cycleColors = 1;
								v20 = 1;
								gpSoundManager->PlayAmbientMusic(42, 0, -1);
							LABEL_208:
								gbGameOver = 0;
								if(gbShowHighScore)
									{
									gbShowHighScore = 0;
									if(gpExec->AddManager((baseManager*)gpHighScoreManager, -1))
										ShutDown("Can't add manager!");
									gpExec->MainLoop();
									gpExec->RemoveManager((baseManager*)gpHighScoreManager);
									giHighScoreRank = -1;
									gpSoundManager->SwitchAmbientMusic(42);
									gpResourceManager->GetBackdrop("heroes.icn", gpWindowManager->screenBuffer, 1);
									gpWindowManager->UpdateScreenRegion(0, 0, 0x280u, 480);
									gpWindowManager->FadeScreen(0, 8, gPalette);
									v20 = 1;
									}
								}
							if(gbRemoteOn)
								v25 = 1;
							goto LABEL_15;
							}
						LogStr("Load Game 1");
						if(gpGame->PickLoadGame())
							{
							LogStr("Load Game 2");
							goto LABEL_88;
							}
						break;
					case 103:
						if(gpExec->AddManager((baseManager*)gpHighScoreManager, -1))
							ShutDown("Can't add manager!");
						gpExec->MainLoop();
						gpExec->RemoveManager((baseManager*)gpHighScoreManager);
						v20 = 0;
						goto LABEL_16;
					case 104:
						gpWindowManager->FadeScreen(1, 8, gPalette);
						PlaySmacker(72);
						PlaySmacker(36);
						v20 = 0;
						gpWindowManager->FadeScreen(1, 128, gPalette);
						goto LABEL_16;
					case 105:
						v25 = 1;
						goto LABEL_88;
					default:
						goto LABEL_88;
					}
			}
		}
	ShutDown(0);
	return 0;
	}