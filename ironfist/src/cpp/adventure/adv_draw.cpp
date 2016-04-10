#include "base.h"
#include "game/game.h"
#include "spell/spells.h"
#include "combat/creatures.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"


extern int giLimitUpdMinX;
extern int giFrameCount;
extern int giFrameStep;
extern int glTimers;
extern int giLimitUpdMinY;
extern int giLimitUpdMaxX;
extern int giLimitUpdMaxY;
extern int giDeferObjDrawX;
extern int giDeferObjDrawY;
extern int giScrollX;
extern int giScrollY;

extern void __fastcall BlitBitmapToScreen(bitmap *bmp, int xOff, int yOff, int width, int height, int screenX, int screenY);
extern long __fastcall KBTickCount();
extern void __fastcall Process1WindowsMessage();

void advManager::UpdateScreen(int a2, int a3)
	{
	static int update_width = 0x1C0u + 160;
	static int update_height = 448 + 10;
	if(a3 || bShowIt)
		{
		PollSound();
		giScrollX = this->field_1F6;
		giScrollY = this->field_1FA;
		if(giLimitUpdMinX == -1)
			BlitBitmapToScreen(gpWindowManager->screenBuffer, 16, 16, update_width, update_height, 16, 16);
		else
			BlitBitmapToScreen(
				gpWindowManager->screenBuffer,
				giLimitUpdMinX,
				giLimitUpdMinY,
				giLimitUpdMaxX - giLimitUpdMinX + 160,
				giLimitUpdMaxY - giLimitUpdMinY,
				giLimitUpdMinX,
				giLimitUpdMinY);
		giScrollY = 0;
		giScrollX = 0;
		PollSound();
		if(KBTickCount() > glTimers)
			{
			++this->field_202;
			++this->field_1FE;
			if(this->field_1FE >= 6)
				this->field_1FE = 0;
			glTimers = KBTickCount() + 120;
			if(this->field_1FE != 1 && this->field_1FE != 3 && this->field_1FE != 5)
				{
				++this->field_20A;
				this->field_20A %= 18;
				++this->field_212;
				this->field_212 %= 18;
				}
			else
				{
				++this->field_20E;
				this->field_20E %= 18;
				++this->field_216;
				this->field_216 %= 18;
				}
			}
		giLimitUpdMinX = -1;
		Process1WindowsMessage();
		}
	else if(KBTickCount() > glTimers)
		{
		glTimers = KBTickCount() + 120;
		}
	}