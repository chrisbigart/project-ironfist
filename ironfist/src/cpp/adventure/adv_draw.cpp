#include "base.h"
#include "game/game.h"
#include "spell/spells.h"
#include "combat/creatures.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"

void game::ShowHeroesLogo()
	{
	icon *v0; // ST34_4@2

	if (!gpAdvManager->field_37A)
		{
		gpAdvManager->field_37A = 1;
		v0 = gpResourceManager->GetIcon("herologo.icn");
		IconToBitmap(v0, gpWindowManager->screenBuffer, 480 + 160, 16, 0, 0, 0, 0, 0x280u, 480, 0);
		gpWindowManager->UpdateScreenRegion(480 + 160, 16, 0x90u, 144);
		gpResourceManager->Dispose((resource *)v0);
		}
	}

void advManager::UpdateScreen(int a2, int a3)
	{
	static int update_width = 0x1C0u + 160;
	static int update_height = 448 + 10;
	if(a3 || bShowIt)
		{
		PollSound();
		//giScrollX = this->field_1F6;
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
//		giScrollY = 0;
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