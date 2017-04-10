#include "manager.h"
#include "game/game.h"
#include "resource/resources.h"
#include "resource/resourcemanager.h"
#include "sound\/sound.h"
#include "combat/combat.h"

#include <cassert>
#include <string>

template<int actual, int expected> struct check_size
	{
	static_assert(actual == expected, "size mismatch");
	};

void check_game_structure_sizes()
	{
	check_size<sizeof(inputManager), 2154> inputManager_size;
	check_size<sizeof(executive), 16> executive_size;
	check_size<sizeof(mouseManager), 138> mouseManager_size;
	check_size<sizeof(heroWindowManager), 98> heroWindowManager_size;
	//check_size<sizeof(resourceManager), 162> resourceManager_size;
	check_size<sizeof(soundManager), 1714> soundManager_size;
	//check_size<sizeof(highScoreManager), 99> baseManager_size;
	check_size<sizeof(game), 26127> game_size;
	check_size<sizeof(advManager), 894> advManager_size;
	check_size<sizeof(combatManager), 63607> combatManager_size;
	check_size<sizeof(townManager), 378> townManager_size;
	check_size<sizeof(searchArray), 9496> searchArray_size;
	check_size<sizeof(armyGroup), 15> armyGroup_size;
	check_size<sizeof(palette), 20> palette_size;
	}

void check_game_structure_field_offsets()
	{
	static_assert(offsetof(game, field_6395) == 0x6395, "game->field_6395 not at offset 0x6395");
	static_assert(offsetof(advManager, field_37A) == 0x37A, "advManager->field_37A not at offset 0x37A");

	}

//hero *j; // [sp+Ch] [bp-4Ch]@26
//signed int v1; // [sp+10h] [bp-48h]@26
//town *i; // [sp+14h] [bp-44h]@23
//signed int v3; // [sp+18h] [bp-40h]@23
//palette *v4; // [sp+1Ch] [bp-3Ch]@49
//armyGroup *v5; // [sp+20h] [bp-38h]@46
//void *v6; // [sp+24h] [bp-34h]@43
//searchArray *v7; // [sp+28h] [bp-30h]@40
//townManager *v8; // [sp+2Ch] [bp-2Ch]@37
//combatManager *ecx0; // [sp+30h] [bp-28h]@34
//advManager *v10; // [sp+34h] [bp-24h]@31
//game *v11; // [sp+38h] [bp-20h]@22
//baseManager *v12; // [sp+3Ch] [bp-1Ch]@19
//soundManager *v13; // [sp+40h] [bp-18h]@16
//resourceManager *this; // [sp+44h] [bp-14h]@13
//heroWindowManager *v2; // [sp+48h] [bp-10h]@10
//mouseManager *v16; // [sp+4Ch] [bp-Ch]@7
//int v17; // [sp+50h] [bp-8h]@4
//executive *v18; // [sp+54h] [bp-4h]@1
//
//v18 = (executive *)operator new(16);
//if (v18)
//gpExec = executive::executive(v18);
//else
//gpExec = 0;
//v17 = (int)operator new(2154);
//if (v17)
//gpInputManager = inputManager::inputManager(v17);
//else
//gpInputManager = 0;
//v16 = (mouseManager *)operator new(138);
//if (v16)
//gpMouseManager = mouseManager::mouseManager(v16);
//else
//gpMouseManager = 0;
//v2 = (heroWindowManager *)operator new(98);
//if (v2)
//gpWindowManager = heroWindowManager::heroWindowManager(v2);
//else
//gpWindowManager = 0;
//this = (resourceManager *)operator new(162);
//if (this)
//gpResourceManager = resourceManager::resourceManager(this);
//else
//gpResourceManager = 0;
//v13 = (soundManager *)operator new(1714);
//if (v13)
//gpSoundManager = (int)soundManager::soundManager(v13);
//else
//gpSoundManager = 0;
//v12 = (baseManager *)operator new(99);
//if (v12)
//gpHighScoreManager = highScoreManager::highScoreManager(v12);
//else
//gpHighScoreManager = 0;
//v11 = (game *)operator new(26127);
//if (v11)
//{
//	fullMap::fullMap(&v11->map);
//	v3 = 72;
//	for (i = v11->castles; ; ++i)
//	{
//		--v3;
//		if (v3 < 0)
//			break;
//		town::town(i);
//	}
//	v1 = 54;
//	for (j = v11->heroes; ; ++j)
//	{
//		--v1;
//		if (v1 < 0)
//			break;
//		hero::hero(j);
//	}
//	gpGame = v11;
//}
//else
//{
//	gpGame = 0;
//}
//v10 = (advManager *)operator new(894);
//if (v10)
//gpAdvManager = advManager::advManager(v10);
//else
//gpAdvManager = 0;
//ecx0 = (combatManager *)operator new(63607);
//if (ecx0)
//gpCombatManager = combatManager::combatManager(ecx0);
//else
//gpCombatManager = 0;
//v8 = (townManager *)operator new(378);
//if (v8)
//gpTownManager = townManager::townManager(v8);
//else
//gpTownManager = 0;
//v7 = (searchArray *)operator new(9496);
//if (v7)
//gpSearchArray = searchArray::searchArray(v7);
//else
//gpSearchArray = 0;
//v6 = operator new(1);
//if (v6)
//gpPhilAI = (int)philAI::philAI(v6);
//else
//gpPhilAI = 0;
//v5 = (armyGroup *)operator new(15);
//if (v5)
//gpMonGroup = armyGroup::armyGroup(v5);
//else
//gpMonGroup = 0;
//v4 = (palette *)operator new(20);
//if (v4)
//gpBufferPalette = palette::palette(v4);
//else
//gpBufferPalette = 0;