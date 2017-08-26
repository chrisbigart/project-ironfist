#include "adventure/adv.h"
#include "game/game.h"
#include "sound/sound.h"
#include "resource/resourceManager.h"

#define HIDWORD(_qw)    ((DWORD)(((_qw) >> 32) & 0xffffffff))

extern int gbDrawingPuzzle;
extern signed char puzzlePiecesRemoved[];
extern unsigned char gColorTableTan[];

extern int __fastcall EventWindowHandler(tag_message &);

const int SCREEN_WIDTH = 800;
const int SCREEN_ADDITIONAL_WIDTH = 160;

void advManager::ViewPuzzle()
	{
	__int64 v1; // qax@15
	heroWindow *thisa; // [sp+18h] [bp-60h]@4

	char v51; // [sp+4Bh] [bp-2Dh]@1
	int i; // [sp+4Ch] [bp-2Ch]@1
	int j; // [sp+50h] [bp-28h]@20
	int v54 = 0; // [sp+54h] [bp-24h]@1
	int a3; // [sp+58h] [bp-20h]@9
	icon *v56; // [sp+5Ch] [bp-1Ch]@1
	int v57; // [sp+60h] [bp-18h]@9
	heroWindow *a2; // [sp+64h] [bp-14h]@5
	unsigned int v59; // [sp+68h] [bp-10h]@22
	unsigned int v60; // [sp+6Ch] [bp-Ch]@22
	int v61; // [sp+70h] [bp-8h]@9
	int v62; // [sp+74h] [bp-4h]@9

	gpGame->SetupPuzzlePieces(giCurPlayer, 0);
	char unknown_color_table[] = 
		{
		23,  7, 44, 05, 24, 47,  1, 39,
		16, 36, 11, 45, 31,  2, 30, 38,
		43,  4,  3, 14, 40, 37, 34, 00,
		12,	17, 35, 42, 15,  8, 26, 41,
		28, 46,	10, 22, 21,  6, 32, 18, 
		19, 29, 13,	27,  9, 20, 33, 25,
		0
		};
	
	gpSoundManager->SwitchAmbientMusic(23);
	gpMouseManager->SetPointer("advmice.mse", 0, -999);
	v56 = gpResourceManager->GetIcon("puzzle.icn");

	const int PUZZLE_X_OFFSET = 80;

	for (i = 0; i < 48; ++i)
		{
		if (i % 6 == 5)
			v56->DrawToBuffer(0 - 368, 0, i, 0);

		v56->DrawToBuffer(0 + PUZZLE_X_OFFSET, 0, i, 0);
		
		if(i % 6 == 0)
			v56->DrawToBuffer(0 + 448 + PUZZLE_X_OFFSET, 0, i, 0);
		}
	
	gpWindowManager->UpdateScreenRegion(16, 16, 0x1C0u + SCREEN_ADDITIONAL_WIDTH, 448);
	gpWindowManager->SaveFizzleSource(16 + SCREEN_ADDITIONAL_WIDTH, 16, 448 + SCREEN_ADDITIONAL_WIDTH, 448);
	
	a2 = new heroWindow(480 + SCREEN_ADDITIONAL_WIDTH, 16, "viewpuzl.bin");

	if (!a2)
		MemError();
	gpWindowManager->AddWindow(a2, -1, 1);
	v57 = gpGame->field_6395 - 7;
	a3 = gpGame->field_6396 - 7;
	v62 = 0;
	v61 = 0;
	v62 = (gpGame->field_6396 + gpGame->field_6395) % 3 - 1;
	v61 = (5 * gpGame->field_6396 + 2 * gpGame->field_6395) % 3 - 1;
	if ((gpGame->field_6396 + gpGame->field_6395) % 3 == 1)
		{
		if (v62 <= 0)
			{
			if (v62 < 0)
				--v62;
			}
		else
			{
			++v62;
			}
		}
	else
		{
		v1 = (signed int)gpGame->field_6396 + (signed int)gpGame->field_6395;
		if ((HIDWORD(v1) ^ ((BYTE4(v1) ^ (unsigned __int8)v1) - BYTE4(v1)) & 1) - HIDWORD(v1) == 1)
			{
			if (v61 <= 0)
				{
				if (v61 < 0)
					--v61;
				}
			else
				{
				++v61;
				}
			}
		}
	v57 += v62;
	a3 += v61;
	this->PuzzleDraw(v57, a3, gpGame->field_6395, gpGame->field_6396);
	for (j = 16; j < 464; ++j)
		{
		v59 = (unsigned int)&gpWindowManager->screenBuffer->contents[SCREEN_WIDTH * j + 16];
		v60 = v59 + 448;
		while (v59 < v60)
			{
			*(BYTE *)v59 = gColorTableTan[*(BYTE *)v59];
			++v59;
			}
		}

	//for (j = 464; j < 464 + 16 + SCREEN_ADDITIONAL_WIDTH; ++j) //bit of a hack
	//	{
	//	int SCREEN_HEIGHT = 480;

	//	for (int i = 0; i < SCREEN_HEIGHT; i++)
	//		{
	//		gpWindowManager->screenBuffer->contents[SCREEN_WIDTH * i + 16 + j] = 1;
	//		}
	//	}

	for (i = 0; i < 48; ++i)
		{
		if (!BitTest((const long*)&puzzlePiecesRemoved, i))
			{
			v56->DrawToBuffer(0, 0, unknown_color_table[i], 0);
			++v54;
			}
		}

	if (v54 == 48)
		gpWindowManager->ReleaseFizzleSource();
	else
		gpWindowManager->FizzleForward(16, 16, 448, 448, 220, 0, 0);
	
	gpWindowManager->DoDialog(a2, EventWindowHandler, 0);
	operator delete(a2);
	this->CompleteDraw(this->viewX, this->viewY, 0, 1);
	this->UpdateScreen(0, 0);
	this->UpdateRadar(1, 0);
	gpSoundManager->SwitchAmbientMusic((unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
	}


//const int 
void advManager::PuzzleDraw(int a2, int a3, int a4, int a5)
	{
	gbDrawingPuzzle = 1;
	CompleteDraw(a2, a3, 0, 0, 15, 15);
	gbDrawingPuzzle = 0;
	//IconToBitmap((icon *)field_CE[17],
	//			gpWindowManager->screenBuffer,
	//			32 * (a4 - a2) - 12 + SCREEN_ADDITIONAL_WIDTH / 2,
	//			32 * (a5 - a3),
	//			0,
	//			1,
	//			0,
	//			0,
	//			0x1E0u,
	//			480,
	//			0);
	this->UpdateScreen(0, 0);

	}