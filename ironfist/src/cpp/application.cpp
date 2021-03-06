#include "base.h"
#include "game/game.h"

enum MENU_BUTTON
	{
	MENU_BUTTON_640X480 = 0x9C45,
	MENU_BUTTON_800X600 = 0x9C46,
	MENU_BUTTON_1024X768 = 0x9C47,
	MENU_BUTTON_1280X1024 = 0x9C48,
	MENU_BUTTON_800X480 = 0x9C49,
	MENU_BUTTON_2X600 = 0x9C4a,
	MENU_BUTTON_1280X768 = 0x9C4b,
	MENU_BUTTON_4X1024 = 0x9C4c,
	MENU_BUTTON_FULLSCREEN = 0x9C4d,
	MENU_BUTTON_MANUAL = 0x9C74,
	MENU_BUTTON_ABOUT = 0x9C75,
	MENU_BUTTON_PEASANTS = 0xA028,
	MENU_BUTTON_ARCHERS = 0xA029,
	MENU_BUTTON_RANGES = 0xA02A,
	MENU_BUTTON_PIKEMEN = 0xA02B,
	MENU_BUTTON_VETERAN_PIKEMEN = 0xA02C,
	MENU_BUTTON_SWORDSMEN = 0xA02D,
	MENU_BUTTON_VETERAN_SWORDSMEN = 0xA02E,
	MENU_BUTTON_CAVALRIES = 0xA02F,
	MENU_BUTTON_CHAMPIONS = 0xA030,
	MENU_BUTTON_PALADINS = 0xA031,
	MENU_BUTTON_CRUSADERS = 0xA032,
	MENU_BUTTON_GOBLINS = 0xA033,
	MENU_BUTTON_ORCS = 0xA034,
	MENU_BUTTON_ORC_CHIEFS = 0xA035,
	MENU_BUTTON_WOLVES = 0xA036,
	MENU_BUTTON_OGRES = 0xA037,
	MENU_BUTTON_OGRE_LORDS = 0xA038,
	MENU_BUTTON_TROLLS = 0xA039,
	MENU_BUTTON_WAR_TROLLS = 0xA03A,
	MENU_BUTTON_CYCLOPES = 0xA03B,
	MENU_BUTTON_SPRITES = 0xA03C,
	MENU_BUTTON_DWARVES = 0xA03D,
	MENU_BUTTON_BATTLE_DWARVES = 0xA03E,
	MENU_BUTTON_ELVES = 0xA03F,
	MENU_BUTTON_GRAND_ELVES = 0xA040,
	MENU_BUTTON_DRUIDS = 0xA041,
	MENU_BUTTON_GREATER_DRUIDS = 0xA042,
	MENU_BUTTON_UNICORNS = 0xA043,
	MENU_BUTTON_PHOENIXES = 0xA044,
	MENU_BUTTON_CENTAURS = 0xA045,
	MENU_BUTTON_GARGOYLES = 0xA046,
	MENU_BUTTON_GRIFFINS = 0xA047,
	MENU_BUTTON_MINOTAURS = 0xA048,
	MENU_BUTTON_MINOTAUR_KINDS = 0xA049,
	MENU_BUTTON_HYDRAS = 0xA04A,
	MENU_BUTTON_GREEN_DRAGONS = 0xA04B,
	MENU_BUTTON_RED_DRAGONS = 0xA04C,
	MENU_BUTTON_BLACK_DRAGONS = 0xA04D,
	MENU_BUTTON_HALFLINGS = 0xA04E,
	MENU_BUTTON_BOARDS = 0xA04F,
	MENU_BUTTON_IRON_GOLEMS = 0xA050,
	MENU_BUTTON_STEEL_GOLEMS = 0xA051,
	MENU_BUTTON_ROCS = 0xA052,
	MENU_BUTTON_MAGI = 0xA053,
	MENU_BUTTON_ARCHMAGI = 0xA054,
	MENU_BUTTON_GIANTS = 0xA055,
	MENU_BUTTON_TITANS = 0xA056,
	MENU_BUTTON_SKELETONS = 0xA057,
	MENU_BUTTON_ZOMBIES = 0xA058,
	MENU_BUTTON_MUTANT_ZOMBIES = 0xA059,
	MENU_BUTTON_MUMMIES = 0xA05A,
	MENU_BUTTON_ROYAL_MUMMIES = 0xA05B,
	MENU_BUTTON_VAMPIRES = 0xA05C,
	MENU_BUTTON_VAMPIRE_LORDS = 0xA05D,
	MENU_BUTTON_LICHS = 0xA05E,
	MENU_BUTTON_POWER_LICHES = 0xA05F,
	MENU_BUTTON_BONE_DRAGONS = 0xA060,
	MENU_BUTTON_ROGUES = 0xA061,
	MENU_BUTTON_NOMADS = 0xA062,
	MENU_BUTTON_GHOSTS = 0xA063,
	MENU_BUTTON_GENIES = 0xA064,
	MENU_BUTTON_MEDUSAS = 0xA065,
	MENU_BUTTON_EARTH_ELEMENTALS = 0xA066,
	MENU_BUTTON_AIR_ELEMENTALS = 0xA067,
	MENU_BUTTON_FIRE_ELEMENTALS = 0xA068,
	MENU_BUTTON_WATER_ELEMENTALS = 0xA069,
	MENU_BUTTON_QUIT = 0xA0B4,
	MENU_BUTTON_VIEW_ENTIRE_MAP = 0xA0B5,
	MENU_BUTTON_EXTRA_HERO_MOBILITY = 0xA0B6,
	MENU_BUTTON_FREE_SPELLS = 0xA0B7,
	MENU_BUTTON_FREE_RESOURCES = 0xA0B8,
	MENU_BUTTON_NO_PATHFINDING = 0xA410,
	MENU_BUTTON_BASIC_PATHFINDING = 0xA411,
	MENU_BUTTON_ADVANCED_PATHFINDING = 0xA412,
	MENU_BUTTON_EXPERT_PATHFINDING = 0xA413,
	MENU_BUTTON_NO_ARCHERY = 0xA414,
	MENU_BUTTON_BASIC_ARCHERY = 0xA415,
	MENU_BUTTON_ADVANCED_ARCHERY = 0xA416,
	MENU_BUTTON_EXPERT_ARCHERY = 0xA417,
	MENU_BUTTON_NO_LOGISTICS = 0xA418,
	MENU_BUTTON_BASIC_LOGISTICS = 0xA419,
	MENU_BUTTON_ADVANCED_LOGISTICS = 0xA41A,
	MENU_BUTTON_EXPERT_LOGISTICS = 0xA41B,
	MENU_BUTTON_NO_SCOUTING = 0xA41C,
	MENU_BUTTON_BASIC_SCOUTING = 0xA41D,
	MENU_BUTTON_ADVANCED_SCOUTING = 0xA41E,
	MENU_BUTTON_EXPERT_SCOUTING = 0xA41F,
	MENU_BUTTON_NO_DIPLOMACY = 0xA420,
	MENU_BUTTON_BASIC_DIPLOMACY = 0xA421,
	MENU_BUTTON_ADVANCED_DIPLOMACY = 0xA422,
	MENU_BUTTON_EXPERT_DIPLOMACY = 0xA423,
	MENU_BUTTON_NO_NAVIGATION = 0xA424,
	MENU_BUTTON_BASIC_NAVIGATION = 0xA425,
	MENU_BUTTON_ADVANCED_NAVIGATION = 0xA426,
	MENU_BUTTON_EXPERT_NAVIGATION = 0xA427,
	MENU_BUTTON_NO_LEADERSHIP = 0xA428,
	MENU_BUTTON_BASIC_LEADERSHIP = 0xA429,
	MENU_BUTTON_ADVANCED_LEADERSHIP = 0xA42A,
	MENU_BUTTON_EXPERT_LEADERSHIP = 0xA42B,
	MENU_BUTTON_NO_WISDOM = 0xA42C,
	MENU_BUTTON_BASIC_WISDOM = 0xA42D,
	MENU_BUTTON_ADVANCED_WISDOM = 0xA42E,
	MENU_BUTTON_EXPERT_WISDOM = 0xA42F,
	MENU_BUTTON_NO_MYSTICISM = 0xA430,
	MENU_BUTTON_BASIC_MYSTICISM = 0xA431,
	MENU_BUTTON_ADVANCED_MYSTICISM = 0xA432,
	MENU_BUTTON_EXPERT_MYSTICISM = 0xA433,
	MENU_BUTTON_NO_LUCK = 0xA434,
	MENU_BUTTON_BASIC_LUCK = 0xA435,
	MENU_BUTTON_ADVANCED_LUCK = 0xA436,
	MENU_BUTTON_EXPERT_LUCK = 0xA437,
	MENU_BUTTON_NO_BALLISTICS = 0xA438,
	MENU_BUTTON_BASIC_BALLISTICS = 0xA439,
	MENU_BUTTON_ADVANCED_BALLISTICS = 0xA43A,
	MENU_BUTTON_EXPERT_BALLISTICS = 0xA43B,
	MENU_BUTTON_NO_EAGLE_EYES = 0xA43C,
	MENU_BUTTON_BASIC_EAGLE_EYES = 0xA43D,
	MENU_BUTTON_ADVANCED_EAGLE_EYES = 0xA43E,
	MENU_BUTTON_EXPERT_EAGLE_EYES = 0xA43F,
	MENU_BUTTON_NO_NECROMANCY = 0xA440,
	MENU_BUTTON_BASIC_NECROMANCY = 0xA441,
	MENU_BUTTON_ADVANCED_NECROMANCY = 0xA442,
	MENU_BUTTON_EXPERT_NECROMANCY = 0xA443,
	MENU_BUTTON_NO_ESTATES = 0xA444,
	MENU_BUTTON_BASIC_ESTATES = 0xA445,
	MENU_BUTTON_ADVANCED_ESTATES = 0xA446,
	MENU_BUTTON_EXPERT_ESTATES = 0xA447,
	MENU_BUTTON_BUILD_MAGE_GUILD = 0xA7F8,
	MENU_BUTTON_BUILD_THIEVES_GUILD = 0xA7F9,
	MENU_BUTTON_BUILD_TAVERN = 0xA7FA,
	MENU_BUTTON_BUILD_DOCK = 0xA7FB,
	MENU_BUTTON_BUILD_WELL = 0xA7FC,
	MENU_BUTTON_BUILD_TENT = 0xA7FD,
	MENU_BUTTON_BUILD_CASTLE = 0xA7FE,
	MENU_BUTTON_BUILD_STATUE = 0xA7FF,
	MENU_BUTTON_BUILD_LEFT_TURRET = 0xA800,
	MENU_BUTTON_BUILD_RIGHT_TURRET = 0xA801,
	MENU_BUTTON_BUILD_MARKET = 0xA802,
	MENU_BUTTON_BUILD_1ST_LEVEL_GROWER = 0xA803,
	MENU_BUTTON_BUILD_MOAT = 0xA804,
	MENU_BUTTON_BUILD_TOWN_SPECIFIC_BUILDING = 0xA805,
	MENU_BUTTON_BUILD_CAPTAINS_QUARTERS = 0xA807,
	MENU_BUTTON_BUILD_DWELLING_1 = 0xA80B,
	MENU_BUTTON_BUILD_DWELLING_2 = 0xA80C,
	MENU_BUTTON_BUILD_DWELLING_3 = 0xA80D,
	MENU_BUTTON_BUILD_DWELLING_4 = 0xA80E,
	MENU_BUTTON_BUILD_DWELLING_5 = 0xA80F,
	MENU_BUTTON_BUILD_DWELLING_6 = 0xA810,
	MENU_BUTTON_BUILD_DWELLING_2_UPGRADE = 0xA811,
	MENU_BUTTON_BUILD_DWELLING_3_UPGRADE = 0xA812,
	MENU_BUTTON_BUILD_DWELLING_4_UPDGRADE = 0xA813,
	MENU_BUTTON_BUILD_DWELLING_5_UPGRADE = 0xA814,
	MENU_BUTTON_BUILD_DWELLING_6_UPGRADE = 0xA815,
	MENU_BUTTON_BUILD_DWELLING_6_UPGRADE_2 = 0xA816,
	MENU_BUTTON_BUILD_ALL_BUILDINGS = 0xA85C,
	};

extern void* hInstApp;
//extern HWND hwndApp;
extern void __fastcall ResizeWindow(int, int, int, int);
extern int __fastcall HandleAppSpecificMenuCommands(int);
extern int __stdcall AppAbout(void *, unsigned int, unsigned int, long);

long __fastcall AppCommand(void* this_ptr, unsigned int edx0, unsigned int a2, long a3)
	{
	signed int result; // eax@9

	switch(a2)
		{
		case MENU_BUTTON_ABOUT:
			DialogBoxParamA((HINSTANCE)hInstApp, "HEROES", (HWND)this_ptr, (DLGPROC)AppAbout, 0);
			goto LABEL_11;
		case MENU_BUTTON_MANUAL:
			WinHelpA((HWND)hwndApp, ".\\HELP\\HEROES2.HLP", 0xBu, 0);
			goto LABEL_11;
		case MENU_BUTTON_640X480:
			ResizeWindow(-1, -1, 0x280u, 0x1E0u);
			goto LABEL_11;
		case MENU_BUTTON_800X600:
			ResizeWindow(-1, -1, 0x320u, 0x258u);
			goto LABEL_11;
		case MENU_BUTTON_1024X768:
			ResizeWindow(-1, -1, 0x400u, 0x300u);
			goto LABEL_11;
		case MENU_BUTTON_1280X1024:
			ResizeWindow(-1, -1, 0x500u, 0x400u);
			goto LABEL_11;
		//widescreen:
		case MENU_BUTTON_800X480:
			ResizeWindow(-1, -1, 0x320u, 0x1E0u);
			goto LABEL_11;
		case MENU_BUTTON_1280X768:
			ResizeWindow(-1, -1, 0x500u, 0x300u);
			goto LABEL_11;
		//case MENU_BUTTON_FULLSCREEN:
		//	SetFullScreenStatus((void *)(1 - *(&bMenu + 7 * giCurExe + 5)));
		LABEL_11:
			result = 0;
			break;
		default:
			result = HandleAppSpecificMenuCommands(a2);
			break;
		}
	return result;
	}

extern void __fastcall UpdateDfltMenu_orig(void*);

void __fastcall UpdateDfltMenu(void* hMenua)
	{
	return UpdateDfltMenu_orig(hMenua);

	//HMENU hMenu; // [sp+Ch] [bp-Ch]@1

	//hMenu = hMenua;
	//if(*(&bMenu + 7 * giCurExe))
	//	{
	//	if(giMainVideoModeWidth <= 640)
	//		EnableMenuItem(hMenua, MENU_BUTTON_640X480, MF_GRAYED);
	//	if(giMainVideoModeWidth <= 800)
	//		EnableMenuItem(hMenu, MENU_BUTTON_800X600, MF_GRAYED);
	//	if(giMainVideoModeWidth <= 1024)
	//		EnableMenuItem(hMenu, MENU_BUTTON_1024X768, MF_GRAYED);
	//	if(giMainVideoModeWidth <= 1280)
	//		EnableMenuItem(hMenu, MENU_BUTTON_1280X1024, MF_GRAYED);
	//	if(!gbDDrawAttached)
	//		EnableMenuItem(hMenu, MENU_BUTTON_FULLSCREEN, MF_GRAYED);
	//	}
	}