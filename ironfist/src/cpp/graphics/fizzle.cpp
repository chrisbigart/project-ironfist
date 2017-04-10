#include "base.h"
#include "game/game.h"
#include "spell/spells.h"
#include "combat/creatures.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"

void heroWindowManager::SaveFizzleSource(int a1, int a2, int a3, int a4)
	{
	return SaveFizzleSource_orig(a1, a2, a3, a4);
	}

void advManager::FizzleCenter(int a2)
	{
	int v2; // eax@4
	//__int64 v3; // ST3C_8@8
	SAMPLE2 sound_sample;

	if (bShowIt)
		{
		if (a2)
			{
			if (a2 != 1)
				return;
			v2 = Random(1, 7);
			sprintf(gText, "pickup%02d.82M", v2);
			}
		else
			{
			sprintf(gText, "killfade.82M");
			}
		sound_sample = LoadPlaySample(gText);
		gpMouseManager->HideColorPointer();
		gpWindowManager->SaveFizzleSource(168, 160, 132, 132);
		CompleteDraw(0);
		gpWindowManager->FizzleForward(168, 160, 132, 132, 65, 0, 0);
		gpMouseManager->ShowColorPointer();
		WaitEndSample(sound_sample, -1);
		}
	}


void heroWindowManager::FizzleForward(int x, int y, int width, int height, int delay, signed char *a7, signed char * a8)
	{
	int v8; // ecx@2
	int v9; // eax@4
	int v10; // eax@12
	bitmap *v11; // eax@14
	void *v12; // ebp@17
	int v13; // eax@18
	signed __int8 *v14; // eax@20
	signed __int8 *v15; // esi@20
	int v16; // ecx@20
	int v17; // edi@21
	__int16 v18; // dx@22
	__int16 v19; // bx@22
	signed int v20; // esi@25
	__int64 v21; // qax@26
	resource *v22; // ecx@29
	bitmap **v24; // [sp+14h] [bp-28h]@15
	signed int v25; // [sp+18h] [bp-24h]@17
	int v26; // [sp+1Ch] [bp-20h]@18
	void *pal; // [sp+20h] [bp-1Ch]@14
	int v28; // [sp+24h] [bp-18h]@19
	int v29; // [sp+28h] [bp-14h]@19
	int v30; // [sp+2Ch] [bp-10h]@2
	int v31; // [sp+30h] [bp-Ch]@17
	int v32; // [sp+38h] [bp-4h]@12

	typedef BYTE _BYTE;
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;

	if(bShowIt)
		{
		v8 = x;
		gbEnlargeScreenBlit = 0;
		v30 = 0;
		if(x < 0)
			{
			x = 0;
			width += v8;
			}
		v9 = y;
		if(y < 0)
			{
			y = 0;
			height += v9;
			}
		if(x + width > SCREEN_WIDTH)
			width = SCREEN_WIDTH - x;
		if(y + height > SCREEN_HEIGHT)
			height = SCREEN_HEIGHT - y;
		if(width > 0 && height > 0)
			{
			v10 = this->cycleColors;
			this->cycleColors = 0;
			v32 = v10;
			if(delay == -1)
				delay = 150;
			pal = BaseAlloc(0x300u, "F:\\h2xsrc\\Base\\WINMGR.CPP", 808);
			v11 = new bitmap(0, width, height);
			if(v11)
				{
				v24 = &this->field_4E;
				this->field_4E = v11;
				}
			else
				{
				this->field_4E = 0;
				v24 = &this->field_4E;
				}
			v12 = BaseAlloc(0x10000u, "F:\\h2xsrc\\Base\\WINMGR.CPP", 810);
			BlitBitmap(this->screenBuffer, x, y, width, height, *v24, 0, 0);
			v25 = 0;
			v31 = height + y;
			do
				{
				sprintf(gText, "CCYCLE%02d.BIN", v25);
				v13 = gpResourceManager->MakeId(gText, 1);
				gpResourceManager->PointToFile(v13);
				gpResourceManager->ReadBlock((signed char*)v12, 0x10000u);
				v26 = y;
				if(y < v31)
					{
					v28 = SCREEN_WIDTH * y;
					v29 = 0;
					do
						{
						v14 = &this->fizzleSource->contents[this->fizzleSource->width * (v26 - y)];
						v15 = &this->screenBuffer->contents[x] + v28;
						v16 = (int)&(*v24)->contents[v29];
						if(x < width + x)
							{
							v17 = width;
							do
								{
								v18 = *(_BYTE *)v16;
								v19 = (unsigned __int8)*v14++ << 8;
								++v16;
								++v15;
								--v17;
								*(v15 - 1) = *((_BYTE *)v12 + (unsigned __int16)(v18 | v19));
								} while(v17);
							}
						v28 += SCREEN_WIDTH;
						v29 += width;
						++v26;
						} while(v26 < v31);
					}
				PollSound();
				DelayTilMilli(v30 + delay);
				v30 = KBTickCount();
				BlitBitmapToScreen(this->screenBuffer, x, y, width, height, x, y);
				if(a7)
					{
					memcpy(pal, a7, 0x300u);
					v20 = 0;
					do
						{
						v21 = (v25 + 1) * ((signed int)*(_BYTE *)(a8 + v20) - (signed int)*((_BYTE *)a7 + v20));
						++v20;
						*((_BYTE *)pal + v20 - 1) += ((BYTE4(v21) & 7) + (signed int)v21) >> 3;
						} while(v20 < 768);
						UpdatePalette((signed char* )pal);
					}
				PollSound();
				++v25;
				} while(v25 < 8);
				DelayTilMilli(v30 + delay);
				BlitBitmap(*v24, 0, 0, width, height, this->screenBuffer, x, y);
				BlitBitmapToScreen(this->screenBuffer, x, y, width, height, x, y);
				gbEnlargeScreenBlit = 1;
				this->cycleColors = v32;
				v22 = (resource *)this->fizzleSource;
				if(v22)
					{
					//v22->vtable->scalarDeletingDestructor(v22, 1);
					delete v22;
					}
				this->fizzleSource = 0;
				if(*v24)
					{
					//(*v24)->vtable->scalarDeletingDestructor((resource *)*v24, 1);
					delete *v24;
					}
				*v24 = 0;
				BaseFree(v12, "F:\\h2xsrc\\Base\\WINMGR.CPP", 897);
				BaseFree(pal, "F:\\h2xsrc\\Base\\WINMGR.CPP", 898);
			}
		}
	}