/*
 * Various low-level things used by Heroes II
 * all over the codebase, for better or for worse
 */

#ifndef BASE_H
#define BASE_H

#define ELEMENTS_IN(x) ((sizeof(x))/(sizeof((x)[0])))

extern void __fastcall BaseFree(void *,char *,int);
extern void * __fastcall BaseAlloc(unsigned int,char *,int);

#define FREE(x) (BaseFree((x), __FILE__, __LINE__))
#define ALLOC(x) (BaseAlloc((x), __FILE__, __LINE__))

extern void __fastcall MemError();

extern void __fastcall ProcessAssert(int,char *,int);

#define ASSERT(x) (ProcessAssert((x), __FILE__, __LINE__))

extern void __fastcall ShutDown(char *);
extern void __fastcall EarlyShutdown(char*, char*);

extern char gText[];
extern void __fastcall LogStr(char *);

//

//hex-rays decompiler macros
#define BYTEn(x, n)   (*((BYTE*)&(x)+n))
#define WORDn(x, n)   (*((WORD*)&(x)+n))
#define BYTE1(x)   BYTEn(x,  1)         // byte 1 (counting from 0)
#define BYTE2(x)   BYTEn(x,  2)
#define BYTE3(x)   BYTEn(x,  3)
#define BYTE4(x)   BYTEn(x,  4)
//

//function declarations from asm
#include <Windows.h>
//struct BITMAPINFO;
//class bitmap;
//typedef void* HDC;
//typedef void* HBITMAP;
//class icon;

extern "C" int __stdcall thunk_WinGRecommendDIBFormat(BITMAPINFO*);
extern "C" int __stdcall thunk_WinGCreateDC(void);
extern "C" HBITMAP __stdcall thunk_WinGCreateBitmap(HDC, BITMAPINFO*, void**);

extern void __fastcall InitializePalette();
extern void __fastcall UpdatePalette(signed char *);

extern void __fastcall BlitBitmap(class bitmap *, int, int, int, int, class bitmap *, int, int);
extern void __fastcall BlitBitmapToScreen(bitmap *bmp, int xOff, int yOff, int width, int height, int screenX, int screenY);
extern "C" void __fastcall BlitBitmapToScreenVesa(bitmap* bmp, int x, int y, unsigned int width, int height, int screenX, signed int screenY);

void __fastcall IconToBitmap(class icon * icn, class bitmap * bmp,
							 int x, int y, int spriteIdx, int a6, int a7, int a8,
							 int width, int height,
							 int a11);

extern void __fastcall Process1WindowsMessage();
extern void __fastcall DelayTilMilli(long);
extern void __fastcall DelayMilli(long);
extern void __fastcall DelayTil(int *);
extern long __fastcall KBTickCount();

const int MAX_CREATURES = 256;
const int RAND_DEFAULT = 3;
const int CREATURE_TOOK_TURN_EVENT_CODE = 1;

//variable declarations from asm
extern int giDebugLevel;
extern int giViewWorldScale;
extern int giFrameCount;
extern int giFrameStep;
extern int glTimers;
extern int giLimitUpdMinY;
extern int giLimitUpdMinX;
extern int giLimitUpdMaxX;
extern int giLimitUpdMaxY;
extern int giDeferObjDrawX;
extern int giDeferObjDrawY;
extern int giScrollX;
extern int giScrollY;
extern int iMainWinScreenWidth;
extern int iMainWinScreenHeight;
extern int gbEnlargeScreenBlit; //BOOL
extern void* hpalApp; //HPALETTE;
extern void* hdcImage;
extern void* gbmOldMonoBitmap;
extern void* hwndApp;
extern void* lpInitWin;
extern int gbNoCDRom;
extern int bShowIt; //BOOL
extern int gbAllBlack; //BOOL
extern int gbInViewWorld; //BOOL
extern signed char gbThisNetHumanPlayer[];
extern unsigned char giCurPlayerBit;
extern unsigned char giGroundToTerrain[];
extern class mouseManager* gpMouseManager;
extern class inputManager* gpInputManager;
extern int bInCheckChangeCursor; //BOOL
extern int bLastMouseOffscreen; //BOOL
extern int bLastOnscreenMouseColor; //BOOL
extern int giMinExtentX;
extern int giMinExtentY;
extern int giMaxExtentX;
extern int giMaxExtentY;
extern int gbComputeExtent;
extern int gbSaveBiggestExtent;
extern int gbReturnAfterComputeExtent;
extern int gbLimitToExtent;
extern int giWalkingTo;
extern int giWalkingTo2;
extern int giWalkingFrom;
extern int giWalkingFrom2;
extern int giWalkingYMod;
extern int giWalkingXMod;
extern int giCombatSpeed;
extern int gbFullCombatScreenDrawn;
extern float gfCombatSpeedMod[3];
extern unsigned char * moatCell;
extern struct SCmbtHero sCmbtHero[];

extern char* gCombatFxNames[];
extern int gCurLoadedSpellEffect;
extern class icon * gCurLoadedSpellIcon;
extern unsigned char giNumPowFrames[];

extern int giMinExtentX;
extern int giMinExtentY;
extern int giMaxExtentX;
extern int giMaxExtentY;
extern int giCombatSpeed;
extern int gbFullCombatScreenDrawn;
extern float gfCombatSpeedMod[3];
extern int bSecondAttack;

extern int giNumCreatures;
extern char *cMonFilename[MAX_CREATURES];
extern char *cArmyFrameFileNames[MAX_CREATURES];
extern char *gArmyNames[MAX_CREATURES];
extern char *gArmyNamesPlural[MAX_CREATURES];
extern int gMonRandBound[MAX_CREATURES][2];

extern char* gResourceNames[];
extern char* xBarrierColor[];

extern int gCurSpellEffectFrame;
extern struct _IMAGE screenImage;
//

/*
 * Updates sound, graphics if needed.
 *
 * This is called in a lot of really random, low-level places.
 * It's how Heroes II implements concurrency without having real threads.
 */
extern "C" void __fastcall PollSound();

extern int __fastcall Random(int,int);
extern int __fastcall SRandom(int,int);

#endif