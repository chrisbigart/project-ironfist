#include <cstring>
#include <cstdio>

#include "gui/gui.h"
#include "game/game.h"
#include "manager.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"
#include "gui/dialog.h"
#include "combat/combat.h"
#include "base.h"


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

#pragma pack(push, 1)
struct Point16
	{
	__int16 x;
	__int16 y;
	};
#pragma pack(pop)


void __thiscall combatManager::DrawFrame(int redrawAll, int a3, int a4, int a5, signed int delay, int a7, int waitUntilItIsTime)
	{
	int v8; // ecx@127
	int v9; // ST50_4@148
	int v10; // eax@146
	int offsetX; // [sp+24h] [bp-C4h]@22
	int offsetY; // [sp+28h] [bp-C0h]@19
	int offY; // [sp+34h] [bp-B4h]@96
	int imageIdx; // [sp+38h] [bp-B0h]@96
	int offX; // [sp+3Ch] [bp-ACh]@96
	unsigned __int8 v17[7]; // [sp+44h] [bp-A4h]@94
	Point16 v18[6][4]; // [sp+4Ch] [bp-9Ch]@94
	int v19; // [sp+ACh] [bp-3Ch]@151
	int colBound; // [sp+B0h] [bp-38h]@55
	int v21; // [sp+B4h] [bp-34h]@72
	int deltaX; // [sp+B8h] [bp-30h]@55
	int colStart; // [sp+BCh] [bp-2Ch]@55
	int i; // [sp+C0h] [bp-28h]@7
	int v25; // [sp+D4h] [bp-14h]@5
	int l; // [sp+DCh] [bp-Ch]@5
	int j; // [sp+E0h] [bp-8h]@47
	int k; // [sp+E4h] [bp-4h]@78

	if(this->field_F357 || gbNoShowCombat || !this->field_F42F)
		return;
	PollSound();
	gpMouseManager->couldBeShowMouse = 0;
	if(a3)
		{
		v25 = 0;
		for(l = 0; l < 2; ++l)
			{
			for(i = 0; i < 20; ++i)
				{
				if(limitCreature[l][i] > 0)
					{
					v25 = 1;
					gbComputeExtent = 1;
					gbSaveBiggestExtent = 1;
					gbReturnAfterComputeExtent = 1;
					(&(creatures[l][i]))->DrawToBuffer(
						combatGrid[creatures[l][i].occupiedHex].centerX,
						combatGrid[creatures[l][i].occupiedHex].occupyingCreatureBottomY,
						0);
					gbReturnAfterComputeExtent = 0;
					gbComputeExtent = 0;
					gbSaveBiggestExtent = 0;
					}
				}
			}
		for(l = 0; l < 2; ++l)
			{
			if(field_F41F[l])
				{
				v25 = 1;
				gbComputeExtent = 1;
				gbSaveBiggestExtent = 1;
				gbReturnAfterComputeExtent = 1;
				heroIcon[l]->CombatClipDrawToBuffer(
					(unsigned int)l < 1 ? 30 : 610,
					(unsigned int)l < 1 ? 183 : 148,
					sCmbtHero[heroType[l]].frameIndex[heroAnimationType[l]][heroAnimationFrameCount[l]],
					(SLimitData*)&(heroBounds[l]),
					1,
					0,
					0,
					0);
				gbReturnAfterComputeExtent = 0;
				gbComputeExtent = 0;
				gbSaveBiggestExtent = 0;
				}
			if(field_F427[l])
				{
				v25 = 1;
				gbComputeExtent = 1;
				gbSaveBiggestExtent = 1;
				gbReturnAfterComputeExtent = 1;
				if(l)
					offsetY = (unsigned int)heroes[l]->isCaptain < 1 ? 148 : 135;
				else
					offsetY = 183;
				if(l)
					offsetX = (unsigned int)heroes[l]->isCaptain < 1 ? 610 : 103;
				else
					offsetX = 30;
					heroFlagIcon[l]->CombatClipDrawToBuffer(
						offsetX,
						offsetY,
						heroFlagIconIdx[l],
						(SLimitData*)&(heroFlagBounds[l]),
						1,
						0,
						0,
						0);
				gbReturnAfterComputeExtent = 0;
				gbComputeExtent = 0;
				gbSaveBiggestExtent = 0;
				}
			}
		if(a5 || !v25)
			goto LABEL_168;
		--giMinExtentX;
		--giMinExtentY;
		++giMaxExtentX;
		++giMaxExtentY;
		if(giMinExtentX < 0)
			giMinExtentX = 0;
		if(giMinExtentY < 0)
			giMinExtentY = 0;
		if(giMaxExtentX > 639)
			giMaxExtentX = 639 + 160;
		if(giMaxExtentY > 442)
			giMaxExtentY = 442;
		}
	if(a7)
		{
		if(zeroedAfterAnimatingDeathAndHolySpells)
			{
			if(a3 || a4 || gbLimitToExtent)
				probablyBitmapForCombatScreen->CopyTo(
					gpWindowManager->screenBuffer,
					giMinExtentX,
					giMinExtentY,
					giMinExtentX,
					giMinExtentY,
					giMaxExtentX - giMinExtentX + 1,
					giMaxExtentY - giMinExtentY + 1);
			else
				probablyBitmapForCombatScreen->CopyTo(gpWindowManager->screenBuffer, 0, 0, 0, 0, 640u + 160, 443);
			}
		else
			{
			DrawBackground();
			}
		}
	if(a3)
		{
		gbLimitToExtent = 1;
		gbComputeExtent = 1;
		}
	for(j = 0; j < 9; ++j)
		{
		if(j == 1 && heroes[1])
			{
				heroIcon[1]->CombatClipDrawToBuffer(
					(unsigned int)heroes[1]->isCaptain < 1 ? 610 : 103,
					(unsigned int)heroes[1]->isCaptain < 1 ? 148 : 0x87u,
					sCmbtHero[heroType[1]].frameIndex[heroAnimationType[1]][heroAnimationFrameCount[1]],
					(SLimitData*)&(heroBounds[1]),
					1,
					0,
					0,
					0);
				heroFlagIcon[1]->CombatClipDrawToBuffer(
					610,
					148,
					heroFlagIconIdx[1],
					(SLimitData*)&(heroFlagBounds[1]),
					1,
					0,
					0,
					0);
			}
		if(j == 2 && heroes[0])
			{
			int third_arg = sCmbtHero[heroType[0]].frameIndex[heroAnimationType[0]][heroAnimationFrameCount[0]];
			heroIcon[0]->CombatClipDrawToBuffer(
				30,
				183,
				third_arg,
				(SLimitData*)(&heroBounds[0]),
				//(SLimitData*)&heroBounds,
				0,
				0,
				0,
				0);
			heroFlagIcon[0]->CombatClipDrawToBuffer(
				30,
				183,
				heroFlagIconIdx[0],
				(SLimitData*)(&heroFlagBounds[0]),
				0,
				0,
				0,
				0);
			}
		colStart = 1;
		colBound = 12;
		deltaX = 1;
		if(isCastleBattle && j >= 5)
			{
			colStart = 11;
			colBound = 0;
			deltaX = -1;
			}
		if(isCastleBattle && j == 7)
			combatScreenIcons[3]->CombatClipDrawToBuffer(
				22,
				390,
				probablyCatapultImgIdx[0],
				(SLimitData*)&catapultBounds,
				0,
				0,
				0,
				0);
		if(isCastleBattle && j == 4 && drawBridgePosition != 4)
			combatScreenIcons[5]->CombatClipDrawToBuffer(
				0,
				0,
				drawBridgePosition + 21,
				(SLimitData*)&drawbridgeBounds,
				0,
				0,
				0,
				0);
		if(isCastleBattle && j == 5 && !drawBridgePosition)
			combatScreenIcons[5]->CombatClipDrawToBuffer(0, 0, 25, (SLimitData*)&field_F303, 0, 0, 0, 0);
		if(isCastleBattle && j == 6)
			combatScreenIcons[5]->CombatClipDrawToBuffer(
				0,
				0,
				(unsigned int)ballistaDestroyed < 1 ? 20 : 26,
				(SLimitData*)&ballistaBounds,
				0,
				0,
				0,
				0);
		v21 = 0;
		if(isCastleBattle && wallStatus[3] != 2 && wallStatus[3] != 6)
			{
			v21 = 1;
			for(l = 0; l < 4; ++l)
				{
				(&combatGrid[114])->DrawOccupant(l, 0);
				(&combatGrid[115])->DrawOccupant(l, 0);
				}
			}
		for(k = colStart; k != colBound; k += deltaX)
			(&(combatGrid[13 * j]) + k)->DrawLowerDeadOccupants();
		for(k = colStart; k != colBound; k += deltaX)
			(&(combatGrid[13 * j]) + k)->DrawUpperDeadOccupant();
		for(l = 0; l < 4; ++l)
			{
			if(l == 1)
				{
				for(k = colStart; k != colBound; k += deltaX)
					{
					if(combatGrid[k + 13 * j].combatObjIdx != -1)
						(&(combatGrid[13 * j]) + k)->DrawObstacle();
					}
				}
			for(k = colStart; k != colBound; k += deltaX)
				{
				v18[0][0].x = 443;
				v18[0][0].y = 153;
				v18[0][1].x = 399;
				v18[0][1].y = 237;
				v18[0][2].x = 399;
				v18[0][2].y = 321;
				v18[0][3].x = 443;
				v18[0][3].y = 405;
				v18[1][0].x = 443;
				v18[1][0].y = 153;
				v18[1][1].x = 399;
				v18[1][1].y = 237;
				v18[1][2].x = 399;
				v18[1][2].y = 321;
				v18[1][3].x = 443;
				v18[1][3].y = 405;
				v18[2][0].x = 443;
				v18[2][0].y = 153;
				v18[2][1].x = 399;
				v18[2][1].y = 237;
				v18[2][2].x = 399;
				v18[2][2].y = 321;
				v18[2][3].x = 443;
				v18[2][3].y = 405;
				v18[3][0].x = 443;
				v18[3][0].y = 153;
				v18[3][1].x = 399;
				v18[3][1].y = 237;
				v18[3][2].x = 399;
				v18[3][2].y = 321;
				v18[3][3].x = 443;
				v18[3][3].y = 405;
				v18[4][0].x = 443;
				v18[4][0].y = 153;
				v18[4][1].x = 399;
				v18[4][1].y = 237;
				v18[4][2].x = 399;
				v18[4][2].y = 321;
				v18[4][3].x = 443;
				v18[4][3].y = 405;
				v18[5][0].x = 443;
				v18[5][0].y = 153;
				v18[5][1].x = 399;
				v18[5][1].y = 237;
				v18[5][2].x = 399;
				v18[5][2].y = 321;
				v18[5][3].x = 443;
				v18[5][3].y = 405;
				v17[0] = 0;
				v17[1] = 4;
				v17[2] = 8;
				v17[3] = 23;
				v17[4] = 27;
				v17[5] = 35;
				v17[6] = 31;
				if(isCastleBattle && !l)
					{
					imageIdx = 0;
					offX = 0;
					offY = 0;
					switch(k + 13 * j)
						{
						case 9:
							imageIdx = v17[wallStatus[0]] + 5;
							break;
						case 34:
							imageIdx = v17[wallStatus[1]] + 6;
							break;
						case 86:
							imageIdx = v17[wallStatus[2]] + 7;
							break;
						case 113:
							imageIdx = v17[wallStatus[3]] + 8;
							break;
						case 22:
							imageIdx = turretStatus[0] + 17;
							offX = *(DWORD *)v18[castles[1]->factionID] & 0xFFFF;
							offY = v18[castles[1]->factionID][0].y;
							break;
						case 47:
							imageIdx = turretStatus[1] + 17;
							offX = v18[castles[1]->factionID][1].x;
							offY = v18[castles[1]->factionID][1].y;
							break;
						case 73:
							imageIdx = turretStatus[2] + 17;
							offX = v18[castles[1]->factionID][2].x;
							offY = v18[castles[1]->factionID][2].y;
							break;
						case 100:
							imageIdx = turretStatus[3] + 17;
							offX = v18[castles[1]->factionID][3].x;
							offY = v18[castles[1]->factionID][3].y;
							break;
						case 59:
							if(drawBridgePosition != 3)
								imageIdx = 4;
							break;
						default:
							break;
						}
					if(imageIdx)
						combatScreenIcons[5]->CombatClipDrawToBuffer(
							offX,
							offY,
							imageIdx,
							(SLimitData*)((char *)&combatGrid[13 * j].drawingBounds + 98 * k),
							0,
							0,
							0,
							0);
					}
				if(!v21 || k + 13 * j != 114 && k + 13 * j != 115)
					(&combatGrid[13 * j] + k)->DrawOccupant(l, 0);
				}
			}
		if(isCastleBattle
		   && BYTE1(castles[1]->buildingsBuiltFlags) & 0x10
		   && (j != 4 || drawBridgePosition == 4))
			{
			if(moatCell[j] != giWalkingTo
			   && moatCell[j] != giWalkingTo2
			   && moatCell[j] != giWalkingFrom
			   && moatCell[j] != giWalkingFrom2)
				{
				if(combatGrid[moatCell[j]].unitOwner != -1)
					goto LABEL_150;
				}
			else
				{
				if(abs(giWalkingTo - giWalkingFrom) <= 1)
					goto LABEL_150;
				v8 = giWalkingFrom / 13;
				if(giWalkingFrom / 13 <= giWalkingTo / 13)
					v8 = giWalkingTo / 13;
				if(v8 == j)
					{
					if(gpCombatManager->drawBridgePosition == 4 || giWalkingTo / 13 != 4 && giWalkingFrom / 13 != 4)
						{
						v10 = giWalkingFrom;
						if(giWalkingFrom <= giWalkingTo)
							v10 = giWalkingTo;
						v9 = giWalkingYMod + combatGrid[giWalkingFrom].occupyingCreatureBottomY - 9;
						IconToBitmap(
							combatScreenIcons[14],
							gpWindowManager->screenBuffer,
							0,
							0,
							0,
							1,
							0,
							v9,
							0x280u,
							combatGrid[v10].occupyingCreatureBottomY + 5 - v9 + 1,
							0);
						}
					else if((giWalkingTo / 13 != 4 || giWalkingFrom / 13 != 3) && (giWalkingTo / 13 != 3 || giWalkingFrom / 13 != 4))
						{
						if(giWalkingFrom <= giWalkingTo)
							{
							if(moatCell[j] == giWalkingTo || moatCell[j] == giWalkingTo2)
								{
							LABEL_150:
								combatScreenIcons[13]->CombatClipDrawToBuffer(
									0,
									0,
									j,
									(SLimitData*)&moatPartBounds[j],
									0,
									0,
									0,
									0);
								((hexcell *)&field_49F[98 * moatCell[j] + 19])->DrawOccupant(100, 1);
								(&combatGrid[moatCell[j]])->DrawOccupant(100, 1);
								(&combatGrid[moatCell[j] + 1])->DrawOccupant(100, 1);
								goto LABEL_151;
								}
							}
						else if(moatCell[j] == giWalkingFrom || moatCell[j] == giWalkingFrom2)
							{
							goto LABEL_150;
							}
						}
					}
				}
			}
	LABEL_151:
		v19 = 0;
		}

	//FIXME
	//if(*(_DWORD *)&combatArmyInfoLevel > 0 && *(_DWORD *)&_15[100] != -1)
	//	{
	//	DrawSmallView(0, 0);
	//	DrawSmallView(1, 0);
	//	}
	gpMouseManager->couldBeShowMouse = 1;
	PollSound();
	if(a3 || a4)
		{
		gbLimitToExtent = 0;
		gbComputeExtent = 0;
		if(waitUntilItIsTime)
			DelayTil(&glTimers);
		glTimers = (signed __int64)((double)KBTickCount() + (double)delay * gfCombatSpeedMod[giCombatSpeed]);
		gbFullCombatScreenDrawn = 0;
		if(redrawAll == 1)
			{
			giMaxExtentX += 160;
			if(giMaxExtentY > 442 + 160)
				giMaxExtentY = 442 + 160;
			gbEnlargeScreenBlit = 0;
			gpWindowManager->UpdateScreenRegion(
				giMinExtentX,
				giMinExtentY,
				giMaxExtentX - giMinExtentX + 1,
				giMaxExtentY - giMinExtentY + 1);
			gbEnlargeScreenBlit = 1;
			}
		}
	else if(redrawAll == 1)
		{
		if(waitUntilItIsTime)
			DelayTil(&glTimers);
		gbFullCombatScreenDrawn = 1;
		glTimers = (signed __int64)((double)KBTickCount() + (double)delay * gfCombatSpeedMod[giCombatSpeed]);
		UpdateCombatArea();
		}
LABEL_168:
	gpMouseManager->couldBeShowMouse = 1;
	PollSound();
	}