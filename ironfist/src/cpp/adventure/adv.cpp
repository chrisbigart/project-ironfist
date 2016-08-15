#include "adventure/adv.h"
#include "adventure/map.h"
#include "combat/speed.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "scripting/hook.h"
#include "prefs.h"
#include "combat/creatures.h"

const int BUTTON_CODE_OKAY = 30725;
const int BUTTON_CODE_CANCEL = 30726;

static const int END_TURN_BUTTON = 4;

int advManager::ProcessDeSelect(tag_message *evt, int *n, mapCell **cells) {
  extern int giBottomViewOverride;
  extern int iCurBottomView;
  extern int giBottomViewOverrideEndTime;

  if (evt->yCoordOrFieldID == END_TURN_BUTTON) {
    int hero_reminder_pref = read_pref<DWORD>("Show Hero Movement Reminder");
    //default is true, but read_pref() returns -1 if the value is not set
    bool show_hero_movement_reminder = hero_reminder_pref != 0;

    if (gpCurPlayer->HasMobileHero()) {
      if (!show_hero_movement_reminder) {
        gpGame->NextPlayer();
      } else { //if the movement reminder is on, ask player if he/she really wants to end turn
        NormalDialog("One or more heroes may still move, are you sure you want to end your turn?",
          2, -1, -1, -1, 0, -1, 0, -1, 0);

        if (gpWindowManager->buttonPressedCode != BUTTON_CODE_CANCEL)
          gpGame->NextPlayer();
      }
    } else { //there are no heroes with movement points left, end turn
      gpGame->NextPlayer();
    }

    // This is taken out of the original ProcessDeSelect. Exact purpose is unknown; could quite
    // possible be removed
    if (evt->yCoordOrFieldID >= 2000
      && evt->yCoordOrFieldID <= 2200) {
      if (giBottomViewOverride == 2) {
        giBottomViewOverride = 1;
      } else if (giBottomViewOverride) {
        giBottomViewOverride = 0;
      } else if (iCurBottomView == 2) {
        giBottomViewOverride = 1;
      } else {
        giBottomViewOverride = 2;
      }

      giBottomViewOverrideEndTime = KBTickCount() + 3000;
      UpdBottomView(1, 1, 1);
  
    }

    return 1;
  } else {
    return ProcessDeSelect_orig(evt, n, cells);
  }

}


int advManager::Open(int idx) {
  int res = this->Open_orig(idx);
  if (gpGame->day == 1 && gpGame->week == 1 && gpGame->month == 1) {
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

void game::ShareVision(int sourcePlayer, int destPlayer) {
  this->sharePlayerVision[sourcePlayer][destPlayer] = 1;
  this->PropagateVision();
}

void game::PropagateVision() {
  for (int p1 = 0; p1 < NUM_PLAYERS; p1++) {
    for (int p2 = 0; p2 < NUM_PLAYERS; p2++) {
      if (this->sharePlayerVision[p1][p2]) {
        for (int i = 0; i < MAP_HEIGHT; i++) {
          for (int j = 0; j < MAP_WIDTH; j++) {
            if (MapCellVisible(j, i, p1)) {
              RevealMapCell(j, i, p2);
            }
          }
        }
      }
    }
  }
}

void game::SetVisibility(int x, int y, int player, int radius) {
  return this->SetVisibility_orig(x, y, player, radius);

  for (int i = 0; i < NUM_PLAYERS; i++) {
    if (this->sharePlayerVision[player][i]) {
      // Would take more work to be transitive without infinite recursion
      this->SetVisibility_orig(x, y, i, radius);
    }
  }
}

void game::MakeAllWaterVisible(int player) {
  this->MakeAllWaterVisible_orig(player);

  for (int i = 0; i < NUM_PLAYERS; i++) {
    if (this->sharePlayerVision[player][i]) {
      // Would take more work to be transitive without infinite recursion
      this->MakeAllWaterVisible_orig(i);
    }
  }
}

class philAI
	{
	public: int __thiscall philAI::FightValueOfStack(class armyGroup *, class hero *, int, int, int, int);
	};

class philAI* gpPhilAI;

extern DWORD gbInCampaign;
extern DWORD xIsPlayingExpansionCampaign;


class ExpCampaign
	{
	public: signed char __thiscall ExpCampaign::HasAward(int);
	};
extern class ExpCampaign* xCampaign;

extern char ** gEventText;

//heroWindow *__thiscall advManager::PlayerMonsterInteract(void *this, mapCell *cell, mapCell *a5, hero *hero, heroWindow *shouldDeleteWindow, __int64 a6, int a8, __int64 a9)
void advManager::PlayerMonsterInteract(mapCell* cell, mapCell* a5, hero* hero, int* shouldDeleteWindow, int a6, int a7, int a8, int a9, int a10)
	{
	heroWindow *result; // eax@20
	void *thisa; // [sp+14h] [bp-14Ch]@1
	char v10; // [sp+18h] [bp-148h]@69
	int quantity; // [sp+144h] [bp-1Ch]@57
	signed int img1Arg; // [sp+148h] [bp-18h]@63
	int willJoin; // [sp+14Ch] [bp-14h]@1
	float v14; // [sp+150h] [bp-10h]@1
	int creat; // [sp+154h] [bp-Ch]@1
	heroWindow *v16; // [sp+158h] [bp-8h]@78
	int qty; // [sp+15Ch] [bp-4h]@1

	gpMouseManager->ShowColorPointer();
	creat = cell->objectIndex;
	willJoin = cell->extraInfo & 0x1000; //((unsigned __int8)(cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5) & 0;
	qty = cell->extraInfo & 0x0fff; // (unsigned __int8)((unsigned __int8)(cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5);
	
	v14 = (double)gpPhilAI->FightValueOfStack(&hero->army, hero, 0, 0, 0, 0)
		/ (double)(qty * gMonsterDatabase[creat].fight_value);
	if(gbInCampaign
	   && (gpGame->hasDwarfAlliance && (creat == CREATURE_DWARF || creat == CREATURE_BATTLE_DWARF)
		   || gpGame->isDwarfbane && (creat == CREATURE_OGRE || creat == CREATURE_OGRE_LORD)
		   || gpGame->hasDragonAlliance
		   && (creat == CREATURE_GREEN_DRAGON || creat == CREATURE_RED_DRAGON || creat == CREATURE_BLACK_DRAGON)))
		{
		if(hero->army.CanJoin(creat))
			{
			if(creat != CREATURE_DWARF && creat != CREATURE_BATTLE_DWARF)
				{
				if(creat != CREATURE_OGRE && creat != CREATURE_OGRE_LORD)
					NormalDialog(
						"The dragons, snarling and growling, agree to join forces with you, their 'Ally'.",
						1,
						-1,
						-1,
						-1,
						0,
						-1,
						0,
						-1,
						0);
				else
					NormalDialog(
						"The ogres recognize you as the Dwarfbane and lumber over to join you.",
						1,
						-1,
						-1,
						-1,
						0,
						-1,
						0,
						-1,
						0);
				}
			else
				{
				NormalDialog("The dwarves recognize their allies and gladly join your forces.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
				}
			hero->army.Add(creat, qty, -1);
			*shouldDeleteWindow = 1;
			}
		else
			{
			if(creat != CREATURE_DWARF && creat != CREATURE_BATTLE_DWARF)
				{
				if(creat != CREATURE_OGRE && creat != CREATURE_OGRE_LORD)
					NormalDialog(
						"The dragons see you and call out.  \"Our alliance with Archibald compels us to join you.  Unfortunately you have no room.  A pity!\"  They quickly scatter.",
						1,
						-1,
						-1,
						-1,
						0,
						-1,
						0,
						-1,
						0);
				else
					NormalDialog(
						"The ogres give you a grunt of recognition, \"Archibald's allies may pass.\"",
						1,
						-1,
						-1,
						-1,
						0,
						-1,
						0,
						-1,
						0);
				}
			else
				{
				NormalDialog(
					"The dwarves hail you, \"Any friend of Roland is a friend of ours.  You may pass.\"",
					1,
					-1,
					-1,
					-1,
					0,
					-1,
					0,
					-1,
					0);
				}
			*shouldDeleteWindow = 1;
			}
		return;
		}
	if(gbInCampaign && gpGame->field_85 && (creat == CREATURE_DWARF || creat == CREATURE_BATTLE_DWARF))
		{
		NormalDialog("\"The Dwarfbane!!!!, run for your lives.\"", 1, -1, -1, -1, 0, -1, 0, -1, 0);
		*shouldDeleteWindow = 1;
		return;
		}
	if(xIsPlayingExpansionCampaign && xCampaign->HasAward(0) && (creat == 23 || creat == 24))
		{
		*shouldDeleteWindow = 1;
		if(hero->army.CanJoin(creat))
			{
			NormalDialog(
				"As you approach the group of elves, their leader calls them all to attention.  He shouts to them, \"Who of you is brave enough to join this fearless ally of ours?\"  The group explodes with cheers as they run to join your ranks.",
				1,
				-1,
				-1,
				-1,
				0,
				-1,
				0,
				-1,
				0);
			hero->army.Add(creat, qty, -1);
			}
		else
			{
			 NormalDialog(
				"The elves stand at attention as you approach.  Their leader calls to you and says, \"Let us not impede your progress, ally!  Move on, and may victory be yours.\"",
				1,
				-1,
				-1,
				-1,
				0,
				-1,
				0,
				-1,
				0);
			}
		return;
		}
/*
	CREATURE_GHOST = 59,
		CREATURE_GENIE = 60,
		CREATURE_MEDUSA = 61,
		CREATURE_EARTH_ELEMENTAL = 62,
		CREATURE_AIR_ELEMENTAL = 63,
		CREATURE_FIRE_ELEMENTAL = 64,
		CREATURE_WATER_ELEMENTAL = 65,
		CREATURE_RANDMON_ANY = 66,*/
	if(!(hero->army.CanJoin(creat))
	   || v14 <= 2.0
	   || hero->HasArtifact(70)
	   || creat == CREATURE_GHOST
	   || creat == CREATURE_EARTH_ELEMENTAL
	   || creat == CREATURE_AIR_ELEMENTAL
	   || creat == CREATURE_FIRE_ELEMENTAL
	   || creat == CREATURE_WATER_ELEMENTAL)
		goto LABEL_86;
	if(willJoin)
		{
		sprintf(gText, gEventText[66], gArmyNamesPlural[creat]);
		EventWindow(-1, 2, gText, -1, 0, -1, 0, -1);
		if(gpWindowManager->buttonPressedCode == 30725)
			{
			hero->army.Add(creat, qty, -1);
			*shouldDeleteWindow = 1;
			return;
			}
		EventWindow(67, 1, byte_518974, -1, 0, -1, 0, -1);
		goto LABEL_78;
		}
	if(!hero->secondarySkillLevel[4])
		{
	LABEL_86:
		if(v14 <= 5.0)
			goto LABEL_78;
	LABEL_76:
		sprintf(
			gText,
			"The %s, awed by the power of your forces, begin to scatter.  Do you wish to pursue and engage them?",
			gArmyNamesPlural[creat]);
		advManager::EventWindow(-1, 2, gText, -1, 0, -1, 0, -1);
		if(gpWindowManager->buttonPressedCode != 30725)
			{
			result = shouldDeleteWindow;
			*shouldDeleteWindow = 1;
			return result;
			}
		goto LABEL_78;
		}
	if(hero->secondarySkillLevel[4] == 3)
		{
		quantity = qty;
		}
	else if(hero->secondarySkillLevel[4] == 2)
		{
		quantity = qty / 2;
		}
	else
		{
		quantity = qty / 4;
		}
	if(!quantity)
		quantity = 1;
	img1Arg = qty * gMonsterDatabase[creat].cost;
	if(gpGame->players[hero->ownerIdx].resources[6] >= img1Arg)
		{
		if(qty == 1)
			{
			sprintf(
				gText,
				"The %s is swayed by your diplomatic tongue, and offers to join your army for the sum of %d gold.  Do you accept?",
				gArmyNames[creat],
				img1Arg);
			}
		else
			{
			sprintf(gText, "The creatures are swayed by your diplomatic tongue, and make you an offer:\n\n");
			if(qty == quantity)
				sprintf(
					&v10,
					"All %d of the %s will join your army for the sum of %d gold.  Do you accept?",
					qty,
					gArmyNamesPlural[creat],
					img1Arg);
			else
				sprintf(
					&v10,
					"%d of the %d %s will join your army, and the rest will leave you alone, for the sum of %d gold.  Do you accept?",
					quantity,
					qty,
					gArmyNamesPlural[creat],
					img1Arg);
			strcat(gText, &v10);
			}
		NormalDialog(gText, 2, -1, -1, 6, img1Arg, -1, 0, -1, 0);
		if(gpWindowManager->buttonPressedCode == 30725)
			{
			armyGroup::Add(&hero->army, creat, quantity, -1);
			*shouldDeleteWindow = 1;
			result = (heroWindow *)img1Arg;
			gpGame->players[hero->ownerIdx].resources[6] -= img1Arg;
			return result;
			}
		advManager::EventWindow(67, 1, byte_518AFC, -1, 0, -1, 0, -1);
		goto LABEL_78;
		}
	if(v14 > 5.0)
		goto LABEL_76;
LABEL_78:
	result = (heroWindow *)advManager::CombatMonsterEvent(
		(advManager *)thisa,
		hero,
		creat,
		qty,
		a5,
		a6,
		SHIDWORD(a6),
		0,
		a9,
		SHIDWORD(a9),
		-1,
		0,
		0,
		-1,
		0,
		0);
	v16 = result;
	if(!result || v16 == (heroWindow *)-1)
		{
		result = shouldDeleteWindow;
		*shouldDeleteWindow = 1;
		}
	return result;
	}