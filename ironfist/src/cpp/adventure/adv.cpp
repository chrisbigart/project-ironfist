#include "adventure/adv.h"
#include "adventure/map.h"
#include "game/game.h"
#include "scripting/hook.h"
#include "sound/sound.h"

#include <iostream>

void advManager::UpdBottomView(int a1, int a2, int a3)
	{
	UpdBottomView_orig(a1, a2, a3);
	//widget* w = adventureScreen->firstWidget;
	//while(w)
	//	{
	//	std::cout << "widget(" << w->offsetX << ", " << w->offsetY << ")\n";
	//	if(w->offsetX >= 480 && w->offsetX < 640)
	//		w->offsetX += 160;

	//	w->Draw();
	//	w = w->nextInLinkedList;
	//	}
	//this->adventureScreen->DrawWindow(0, 2000, 2200);
	}

int advManager::ProcessDeSelect(struct tag_message *GUIMessage_evt, int *a3, class mapCell * *a4)
	{
	/*
	switch(evt->fieldID)
		{
		...
		case 4:
			if(!playerData::HasMobileHero(gpCurPlayer)
			   || (NormalDialog(
				   "One or more heroes may still move, are you sure you want to end your turn?",
				   2,
				   -1,
				   -1,
				   -1,
				   0,
				   -1,
				   0,
				   -1,
				   0),
				   gpWindowManager->buttonPressedCode != 30726))
				game::NextPlayer(gpGame);
			break;
		...
		}
	*/
	//todo: check prefs to see if this option is enabled or not
	//if(GUIMessage_evt->yCoordOrFieldID == 4)
	//	{
	//	//int code = 7;
	//	//this->field_36 = code;
	//	//*(_DWORD *)a4 = advManager::DoAdvCommand(this);
	//	//*a4 = DoAdvCommand();

	//	/*extern int TrigX;
	//	int trigx = TrigX;
	//	int trigy = *((int*)&TrigX + 1);
	//	hero* hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
	//	mapCell* cell = GetCell(trigx, trigy);
	//	unsigned int pre_objType = cell->objType;
	//	unsigned int pre_extraInfo = cell->extraInfo;
	//	gpGame->RestoreCell(hro->x, hro->y, hro->occupiedObjType, hro->occupiedObjVal, 0, 99);
	//	DoEvent(cell, trigx, trigy);
	//	cell->objType = pre_objType;
	//	cell->extraInfo = pre_extraInfo;*/
	//	//gpGame->NextPlayer();

	//	/* //i doubt this is needed but it can be added in if it causes an issue
	//	if(if(GUIMessage_evt->yCoordOrFieldID == 4)
	//	   ->fieldID >= 2000 && if(GUIMessage_evt->yCoordOrFieldID == 4)
	//	   ->fieldID <= 2200)
	//		{
	//		if(giBottomViewOverride == 2)
	//			{
	//			giBottomViewOverride = 1;
	//			}
	//		else if(giBottomViewOverride)
	//			{
	//			giBottomViewOverride = 0;
	//			}
	//		else if(iCurBottomView == 2)
	//			{
	//			giBottomViewOverride = 1;
	//			}
	//		else
	//			{
	//			giBottomViewOverride = 2;
	//			}
	//		giBottomViewOverrideEndTime = KBTickCount() + 3000;
	//		advManager::UpdBottomView(1, 1, 1);
	//		}
	//	*/
	//	return 1;
	//	}
	return ProcessDeSelect_orig(GUIMessage_evt, a3, a4);
	}

extern int gbHeroMoving;

void advManager::SetTownContext(int a2)
	{
	advManager *result; // eax@12
	int v4; // [sp+10h] [bp-Ch]@1
	int v5; // [sp+10h] [bp-Ch]@10
	signed int i; // [sp+14h] [bp-8h]@1
	char *v7; // [sp+18h] [bp-4h]@1

	DeactivateCurrHero();

	//mov  al, byte ptr[ebp + arg_0]
	//mov  ecx, ? gpCurPlayer@@3PAVplayerData@@A
	//mov	[ecx + 45h], al
	//LOBYTE(gpCurPlayer->field_45) = a2;
	*(char*)&gpCurPlayer->field_45 = (char)(a2 & 0xff);
	v7 = (char *)&gpGame->castles[LOBYTE(gpCurPlayer->field_45)];

	int viewx_diff = 7;
	//if(widescreen)
	viewx_diff = 10;
	this->viewX = gpGame->castles[LOBYTE(gpCurPlayer->field_45)].x - viewx_diff;
	this->viewY = (unsigned __int8)v7[5] - 7;
	v4 = 0;
	for(i = 0; gpCurPlayer->numCastles > i; ++i)
		{
		if(gpCurPlayer->castlesOwned[i] == a2)
			v4 = i;
		}
	if((signed char)HIBYTE(gpCurPlayer->field_45) <= v4)
		{
		if(HIBYTE(gpCurPlayer->field_45) + 3 < v4)
			//HIBYTE(gpCurPlayer->field_45) = v4 - 3;
			gpCurPlayer->field_45 = (gpCurPlayer->field_45 & 0x00ff) & ((v4 - 3) << 8);
		}
	else
		{
		//HIBYTE(gpCurPlayer->field_45) = v4;
		gpCurPlayer->field_45 = (gpCurPlayer->field_45 & 0x00ff) & (v4 << 8);
		}
	//this->viewX -= 2;
	UpdateHeroLocators(1, 1);
	UpdateTownLocators(1, 1);
	HideRoute(0, 0, 1);
	UpdBottomView(1, 1, 1);
	UpdateRadar(1, 0);
	CompleteDraw(this->viewX, this->viewY, 0, 1);
	UpdateScreen(0, 0);
	SetEnvironmentOrigin(this->viewX + 10, this->viewY + 7, 1);
	v5 = (unsigned __int8)giGroundToTerrain[GetCell((unsigned __int8)v7[4], (unsigned __int8)v7[5])->groundIndex];
	if(this->currentTerrain != v5)
		{
		this->currentTerrain = v5;
		gpSoundManager->SwitchAmbientMusic(
			(unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
		}
	gpInputManager->ForceMouseMove();
	result = this;
	this->xOff = 0;
	///return result;
	//SetTownContext_orig(town_id);
	//if(widescreen)
	//viewX += 3;
	}

void advManager::SetHeroContext(int heroIdx, int a3)
	{

	//this = dword ptr - 20
	//var_10 = dword ptr - 16
	//heroOwnedIdx = dword ptr - 12
	//var_8 = dword ptr - 8
	//var_4 = dword ptr - 4
	//heroIdx = dword ptr 8
	//arg_4 = dword ptr 12

	mapCell *v4; // [sp+10h] [bp-10h]@5
	int heroOwnedIdx; // [sp+14h] [bp-Ch]@5
	int heroOwnedIdxa; // [sp+14h] [bp-Ch]@18
	signed int i; // [sp+18h] [bp-8h]@5
	hero *hro; // [sp+1Ch] [bp-4h]@2

	typedef unsigned long long QWORD;

	if(heroIdx != -1)
		{
		DeactivateCurrTown();
		HideRoute(0, 0, 1);
		DeactivateCurrHero();
		this->heroMobilized = 1;
		gpCurPlayer->curHeroIdx = heroIdx;
		hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
		int viewx_diff = 7;
		//if(widescreen)
		//	viewx_diff = 10;

		this->viewX = gpGame->heroes[gpCurPlayer->curHeroIdx].x - viewx_diff;
		this->viewY = hro->y - 7;
		this->field_29A = 7;
		this->field_292 = this->field_29A;
		this->field_29E = -1;
		this->field_296 = this->field_29E;
		if(hro->flags & HERO_AT_SEA)
			this->field_27A = 6;
		else
			this->field_27A = hro->factionID;
		this->field_27E = HIBYTE(hro->field_2B);
		this->field_282 = GetCursorBaseFrame(this->field_27E);
		v4 = GetCell(hro->x, hro->y);
		v4->displayFlags |= 0x40u;
		gpGame->RestoreCell(hro->x, hro->y, hro->occupiedObjType, hro->occupiedObjVal, 0, 4);
		heroOwnedIdx = 0;
		for(i = 0; gpCurPlayer->numHeroes > i; ++i)
			{
			if(gpCurPlayer->heroesOwned[i] == heroIdx)
				heroOwnedIdx = i;
			}
		if(gpCurPlayer->field_3 <= heroOwnedIdx)
			{
			if(gpCurPlayer->field_3 + 3 < heroOwnedIdx)
				gpCurPlayer->field_3 = heroOwnedIdx - 3;
			}
		else
			{
			gpCurPlayer->field_3 = heroOwnedIdx;
			}
		//this->viewX -= 2;
		UpdateHeroLocators(1, 1);
		UpdateTownLocators(1, 1);
		if(!a3 && (this->ready == 1 || gbThisNetHumanPlayer[giCurPlayer]))
			{
			Reseed(0, 0);
				/*
				mov  eax, [ebp + var_4]
				mov  eax, [eax + 25h]
				push  eax
				mov  eax, [ebp + var_4]
				mov  eax, [eax + 21h]
				push  eax
				mov  ecx, [ebp + this]
				call ? SeedTo@advManager@@QAEXHH@Z
				*/
			SeedTo(*(DWORD *)&hro->field_21, *(DWORD *)&hro->field_25);
			ShowRoute(0, 0, 1);
			}
		UpdBottomView(1, 1, 1);
		this->field_272 = 1;
		UpdateRadar(1, 0);
		CompleteDraw(this->viewX, this->viewY, 0, 1);
		UpdateScreen(0, 0);
		SetEnvironmentOrigin(this->viewX + 7, this->viewY + 7, 1);
		heroOwnedIdxa = (unsigned __int8)giGroundToTerrain[v4->groundIndex];
		if(this->currentTerrain != heroOwnedIdxa)
			{
			this->currentTerrain = heroOwnedIdxa;
			gpSoundManager->SwitchAmbientMusic(
				(unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
			}
		if(!gbHeroMoving)
			{
			gpInputManager->ForceMouseMove();
			this->xOff = 0;
			}
		}
	//SetHeroContext_orig(a1, a2);
	//if(widescreen)
	//viewX += 3;
	}

int advManager::Open(int idx) {
	int res = this->Open_orig(idx);
	if(gpGame->day == 1 && gpGame->week == 1 && gpGame->month == 1) {
		//The NEW_DAY event is triggered after game::PerDay, but that is not called
		//before the first day
		//
		//The correct place to put this is wherever the start-of-map events fire
		//This kinda works, but will also fire after exiting the town screen or
		//combat on the first day
		ScriptSignal(SCRIPT_EVT_MAP_START, "");
		ScriptSignal(SCRIPT_EVT_NEW_DAY, "");
	}
	return res;
}
//
//void game::ShareVision(int sourcePlayer, int destPlayer) {
//    this->sharePlayerVision[sourcePlayer][destPlayer] = 1;
//    this->PropagateVision();
//}
//
//void game::PropagateVision() {
//    for (int p1 = 0; p1 < NUM_PLAYERS; p1++) {
//        for (int p2 = 0; p2 < NUM_PLAYERS; p2++) {
//            if (this->sharePlayerVision[p1][p2]) {
//                for (int i = 0; i < MAP_HEIGHT; i++) {
//                    for (int j = 0; j < MAP_WIDTH; j++) {
//                        if (MapCellVisible(j, i, p1)) {
//                            RevealMapCell(j, i, p2);
//                        }
//                    }
//                }
//            }
//        }
//    }
//}

void game::SetVisibility(int x, int y, int player, int radius) {
    this->SetVisibility_orig(x, y, player, radius);

    //for (int i = 0; i < NUM_PLAYERS; i++) {
    //    if (this->sharePlayerVision[player][i]) {
    //        // Would take more work to be transitive without infinite recursion
    //        this->SetVisibility_orig(x, y, i, radius);
    //    }
    //}
}

void game::MakeAllWaterVisible(int player) {
    this->MakeAllWaterVisible_orig(player);

    //for (int i = 0; i < NUM_PLAYERS; i++) {
    //    if (this->sharePlayerVision[player][i]) {
    //        // Would take more work to be transitive without infinite recursion
    //        this->MakeAllWaterVisible_orig(i);
    //    }
    //}
}