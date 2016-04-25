#include "base.h"
#include "game/game.h"
#include "spell/spells.h"
#include "combat/creatures.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"

/*  143 */
#pragma pack(push, 1)
struct GUIMessage
	{
	INPUT_EVENT_CODE eventCode;
	int messageType;
	int fieldID;
	int inputTypeBitmask;
	int altXCoord;
	int altYCoord;
	void *payload;
	};
#pragma pack(pop)

#pragma pack(push, 1)
union Event
	{
	tag_message inputEvt;
	GUIMessage guiMsg;
	};
#pragma pack(pop)

extern void __fastcall QuickViewWait(void);

void advManager::QuickInfo(int a2, int a3)
	{
	char *v3; // ST28_4@74
	char *v4; // eax@74
	char *v5; // ST28_4@80
	char *v6; // eax@80
	__int16 v7; // ax@83
	advManager *v9; // [sp+18h] [bp-1F4h]@1
	heroWindow *this_a; // [sp+24h] [bp-1E8h]@12
	bool v11; // [sp+2Ch] [bp-1E0h]@68
	signed int v12; // [sp+3Ch] [bp-1D0h]@89
	signed int v13; // [sp+3Ch] [bp-1D0h]@125
	Event evt; // [sp+40h] [bp-1CCh]@154
	char a2a; // [sp+5Ch] [bp-1B0h]@74
	char a1[200]; // [sp+124h] [bp-E8h]@151
	hero *curHero; // [sp+1ECh] [bp-20h]@1
	int yOff; // [sp+1F0h] [bp-1Ch]@8
	int xOff; // [sp+1F4h] [bp-18h]@4
	heroWindow *window; // [sp+1F8h] [bp-14h]@13
	int v21; // [sp+1FCh] [bp-10h]@87
	mapCell *map_cell; // [sp+200h] [bp-Ch]@1
	int v23; // [sp+204h] [bp-8h]@17
	int v24; // [sp+208h] [bp-4h]@87

	extern char* adventureMapLocations[];
	//char* adventureMapLocations[5000];

	
	int WIDESCREEN_ADDITIONAL_WIDTH = 160;
	int ADV_DRAW_WIDTH = 448 + WIDESCREEN_ADDITIONAL_WIDTH;
	int ADV_DRAW_TOTAL_WIDTH = 480 + WIDESCREEN_ADDITIONAL_WIDTH;

	v9 = this;
	map_cell = 0;
	curHero = 0;
	if(gpCurPlayer->curHeroIdx == -1)
		curHero = 0;
	else
		curHero = &gpGame->heroes[gpCurPlayer->curHeroIdx];
	xOff = 32 * a2 - 57;
	if(xOff < 30)
		xOff = 30;
	//if(xOff + 160 > 464)
	if(xOff + 160 > ADV_DRAW_WIDTH + 16)
		xOff = 304 + WIDESCREEN_ADDITIONAL_WIDTH;
	yOff = 32 * a3 - 25;
	if(yOff < 16)
		yOff = 16;
	if(yOff + 96 > 448)
		yOff = 352;
	//this_a = (heroWindow *)operator new(68);
	//if(this_a)
	//	window = heroWindow::heroWindow(this_a, xOff, yOff, "qwikinfo.bin");
	window = new heroWindow(xOff, yOff, "qwikinfo.bin");
	//else
	//	window = 0;
	if(!window)
		MemError();
	v23 = 0;
	if(a2 + v9->viewX >= 0 && a2 + v9->viewX < MAP_WIDTH && a3 + v9->viewY >= 0 && a3 + v9->viewY < MAP_HEIGHT)
		{
		map_cell = GetCell(a2 + v9->viewX, a3 + v9->viewY);
		if((unsigned __int8)*(&mapRevealed[a2] + v9->viewX + MAP_WIDTH * (a3 + v9->viewY)) & (unsigned __int8)giCurPlayerBit)
			{
			switch(map_cell->objType & 0x7F)
				{
				//case LOCATION_ARTIFACT:
				//	sprintf(gText, "%s", "Artifact");
				//	break;
				//case LOCATION_OBELISK:
				//	if(!(map_cell->objType & 0x80))
				//		goto LABEL_145;
				//	sprintf(
				//		gText,
				//		"%s\n\n%s",
				//		(&adventureMapLocations)[4 * (map_cell->objType & 0x7F)],
				//		&aAlreadyVisit_0[("(not visited)" - "(already visited)") & (((gpGame->boatBuilt[
				//			//(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5)
				//			map_cell->field_4_1
				//																	  + 47] & (1 << giCurPlayer)) != 0)
				//																	- 1)]);
				//	break;
				//case LOCATION_GAZEBO:
				//	if(!curHero || !(map_cell->objType & 0x80))
				//		goto LABEL_145;
				//	sprintf(
				//		gText,
				//		"%s\n\n%s",
				//		(&adventureMapLocations)[4 * (map_cell->objType & 0x7F)],
				//		&aAlreadyVisit_1[("(not visited)" - "(already visited)") & (((
				//			(1 <<
				//			 //((map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 3) & 0x1F)
				//			 map_cell->extraInfo
				//				) 
				//																	  & curHero->gazeboesVisited) != 0)
				//																	- 1)]);
				//	break;
				//case LOCATION_FORT:
				//	if(!curHero || !(map_cell->objType & 0x80))
				//		goto LABEL_145;
				//	sprintf(
				//		gText,
				//		"%s\n\n%s",
				//		(&adventureMapLocations)[4 * (map_cell->objType & 0x7F)],
				//		&aAlreadyVisit_2[("(not visited)" - "(already visited)") & ((((1 << ((map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 3) & 0x1F)) & curHero->fortsVisited) != 0)
				//																	- 1)]);
				//	break;
				//case LOCATION_WITCH_DOCTORS_HUT:
				//	if(!curHero || !(map_cell->objType & 0x80))
				//		goto LABEL_145;
				//	sprintf(
				//		gText,
				//		"%s\n\n%s",
				//		(&adventureMapLocations)[4 * (map_cell->objType & 0x7F)],
				//		&aAlreadyVisit_3[("(not visited)" - "(already visited)") & ((((1 << ((map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 3) & 0x1F)) & curHero->witchDoctorHutsVisited) != 0)
				//																	- 1)]);
				//	break;
				//case LOCATION_MERCENARY_CAMP:
				//	if(!curHero || !(map_cell->objType & 0x80))
				//		goto LABEL_145;
				//	sprintf(
				//		gText,
				//		"%s\n\n%s",
				//		(&adventureMapLocations)[4 * (map_cell->objType & 0x7F)],
				//		&aAlreadyVisit_4[("(not visited)" - "(already visited)") & ((((1 << ((map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 3) & 0x1F)) & curHero->mercenaryCampsVisited) != 0)
				//																	- 1)]);
				//	break;
				//case LOCATION_STANDING_STONES:
				//	if(!curHero || !(map_cell->objType & 0x80))
				//		goto LABEL_145;
				//	sprintf(
				//		gText,
				//		"%s\n\n%s",
				//		(&adventureMapLocations)[4 * (map_cell->objType & 0x7F)],
				//		&aAlreadyVisit_5[("(not visited)" - "(already visited)") & ((((1 << ((map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 3) & 0x1F)) & curHero->standingStonesVisited) != 0)
				//																	- 1)]);
				//	break;
				//case LOCATION_TREE_OF_KNOWLEDGE:
				//	if(!curHero || !(map_cell->objType & 0x80))
				//		goto LABEL_145;
				//	sprintf(
				//		gText,
				//		"%s\n\n%s",
				//		(&adventureMapLocations)[4 * (map_cell->objType & 0x7F)],
				//		&aAlreadyVisit_6[("(not visited)" - "(already visited)") & ((((1 << ((map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 3) & 0x1F)) & curHero->treesOfKnowledgeVisited) != 0)
				//																	- 1)]);
				//	break;
				//case LOCATION_XANADU:
				//	if(!curHero || !(map_cell->objType & 0x80))
				//		goto LABEL_145;
				//	sprintf(
				//		gText,
				//		"%s\n\n%s",
				//		(&adventureMapLocations)[4 * (map_cell->objType & 0x7F)],
				//		&aAlreadyVisit_7[("(not visited)" - "(already visited)") & ((((1 << ((map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 3) & 0x1F)) & curHero->xanadusVisited) != 0)
				//																	- 1)]);
				//	break;
				case LOCATION_BUOY:
					v23 = 2;
					goto LABEL_145;
				case LOCATION_FOUNTAIN:
					v23 = 4;
					goto LABEL_145;
				case LOCATION_OASIS:
					v23 = 8;
					goto LABEL_145;
				case LOCATION_FAERIE_RING:
					v23 = 16;
					goto LABEL_145;
				case LOCATION_TEMPLE:
					v23 = 256;
					goto LABEL_145;
				case LOCATION_WATERING_HOLE:
					v23 = 512;
					goto LABEL_145;
				case LOCATION_MAGIC_WELL:
					v23 = 4096;
					goto LABEL_145;
				case LOCATION_IDOL:
					v23 = 8192;
					goto LABEL_145;
				//case 0:
				//case LOCATION_EVENT:
				//case LOCATION_ARMY_CAMP | LOCATION_SKELETON:
				//case LOCATION_WINDMILL | LOCATION_SKELETON:
				//case LOCATION_NOTHING_SPECIAL | LOCATION_ALCHEMIST_LAB:
				//	v11 = map_cell->objectIndex != 255
				//		&& (((unsigned __int8)map_cell->bitfield_1_hasObject_1_isRoad_6_objTileset >> 2) & 0x3F) != 47
				//		|| map_cell->overlayIndex != 255;
				//	sprintf(
				//		gText,
				//		"%s\n%s",
				//		terrainNames[(unsigned __int8)giGroundToTerrain[map_cell->groundIndex]],
				//		&aNoDigging[("(digging ok)" - "(no digging)") & ((v11 != 0) - 1)]);
				//	break;
				//case LOCATION_ABANDONED_MINE:
				//	sprintf(gText, "%s", (&adventureMapLocations)[4 * (map_cell->objType & 0x7F)]);
				//	goto LABEL_74;
				//case LOCATION_MINE:
				//	if(gpGame->mines[(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5)].guardianType == -1)
				//		{
				//		sprintf(
				//			gText,
				//			"%s %s",
				//			gResourceNames[gpGame->mines[(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5)].type],
				//			"Mine");
				//		}
				//	else
				//		{
				//		sprintf(
				//			gText,
				//			"%s %s",
				//			gResourceNames[gpGame->mines[(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5)].type],
				//			"Mine");
				//	LABEL_74:
				//		v3 = gArmyNamesPlural[gpGame->mines[(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5)].guardianType];
				//		v4 = advManager::GetArmySizeName(
				//			gpGame->mines[(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5)].guadianQty,
				//			2);
				//		sprintf(&a2a, "\n\nguarded by %s %s", v4, v3);
				//		strcat(gText, &a2a);
				//		}
				//	break;
				//case LOCATION_RESOURCE:
				//	sprintf(gText, "%s", *(char **)((char *)gResourceNames + 2 * (map_cell->objectIndex & 0xFE)));
				//	break;
				//case LOCATION_ARMY_CAMP:
				//	if(advManager::IsCrystalBallInEffect(a2 + v9->viewX, a3 + v9->viewY, 8))
				//		{
				//		sprintf(
				//			gText,
				//			"%d %s",
				//			(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5),
				//			gArmyNamesPlural[map_cell->objectIndex]);
				//		}
				//	else
				//		{
				//		v5 = gArmyNamesPlural[map_cell->objectIndex];
				//		v6 = advManager::GetArmySizeName(
				//			(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5),
				//			1);
				//		sprintf(gText, "%s %s", v6, v5);
				//		}
				//	break;
				//case LOCATION_BARRIER:
				//case LOCATION_TRAVELLER_TENT:
				//	if(map_cell->objType & 0x80)
				//		{
				//		v7 = map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 3;
				//		sprintf(gText, (&adventureMapLocations)[4 * (map_cell->objType & 0x7F)], xBarrierColor[v7 & 7]);
				//		gText[0] = toupper(gText[0]);
				//		}
				//	else
				//		{
				//		sprintf(gText, "%s", terrainNames[(unsigned __int8)giGroundToTerrain[map_cell->groundIndex]]);
				//		}
				//	break;
				//case LOCATION_ALCHEMIST_TOWER:
				//	if(map_cell->objectIndex == 255)
				//		{
				//		v21 = map_cell->overlayIndex;
				//		v24 = ((unsigned __int8)map_cell->field__1_hasOverlay_1_hasLateOverlay_6_overlayTileset >> 2) & 0x3F;
				//		}
				//	else
				//		{
				//		v21 = map_cell->objectIndex;
				//		v24 = ((unsigned __int8)map_cell->bitfield_1_hasObject_1_isRoad_6_objTileset >> 2) & 0x3F;
				//		}
				//	v12 = -1;
				//	if(v24 == 61)
				//		{
				//		if(v21 >= 0)
				//			{
				//			if(v21 >= 4)
				//				{
				//				if(v21 < 72)
				//					{
				//					v12 = 1;
				//					v23 = 4194304;
				//					}
				//				}
				//			else
				//				{
				//				v12 = 0;
				//				}
				//			}
				//		}
				//	else if(v24 == 62)
				//		{
				//		if(v21 >= 0)
				//			{
				//			if(v21 >= 5)
				//				{
				//				if(v21 >= 10)
				//					{
				//					if(v21 >= 47)
				//						{
				//						if(v21 < 111)
				//							{
				//							v12 = 6;
				//							v23 = 2097152;
				//							}
				//						}
				//					else
				//						{
				//						v12 = 5;
				//						v23 = 1048576;
				//						}
				//					}
				//				else
				//					{
				//					v12 = -1;
				//					}
				//				}
				//			else
				//				{
				//				v12 = 4;
				//				v23 = 8388608;
				//				}
				//			}
				//		}
				//	else if(v24 == 63 && v21 >= 0)
				//		{
				//		if(v21 >= 32)
				//			{
				//			if(v21 < 59)
				//				v12 = 3;
				//			}
				//		else
				//			{
				//			v12 = 2;
				//			}
				//		}
				//	if(v12 == -1)
				//		sprintf(gText, "Unknown");
				//	else
				//		sprintf(gText, (&off_4F7220)[4 * v12]);
				//	if(curHero && v23)
				//		{
				//		strcat(gText, "\n\n");
				//		strcat(
				//			gText,
				//			&aAlreadyVisit_8[("(not visited)" - "(already visited)") & (((curHero->flags & v23) != 0) - 1)]);
				//		}
				//	break;
				//case LOCATION_EXPANSION_DWELLING:
				//	if(map_cell->overlayIndex == 255)
				//		{
				//		v21 = map_cell->objectIndex;
				//		v24 = ((unsigned __int8)map_cell->bitfield_1_hasObject_1_isRoad_6_objTileset >> 2) & 0x3F;
				//		}
				//	else
				//		{
				//		v21 = map_cell->overlayIndex;
				//		v24 = ((unsigned __int8)map_cell->field__1_hasOverlay_1_hasLateOverlay_6_overlayTileset >> 2) & 0x3F;
				//		}
				//	v13 = -1;
				//	if(v24 == 61 && v21 >= 72)
				//		{
				//		if(v21 >= 78)
				//			{
				//			if(v21 >= 112)
				//				{
				//				if(v21 >= 120)
				//					{
				//					if(v21 >= 129)
				//						{
				//						if(v21 < 137)
				//							v13 = 4;
				//						}
				//					else
				//						{
				//						v13 = 3;
				//						}
				//					}
				//				else
				//					{
				//					v13 = 2;
				//					}
				//				}
				//			else
				//				{
				//				v13 = 1;
				//				}
				//			}
				//		else
				//			{
				//			v13 = 0;
				//			}
				//		}
				//	if(v13 == -1)
				//		sprintf(gText, "Unknown");
				//	else
				//		sprintf(gText, (&off_4F7240)[4 * v13]);
				//	break;
				//case LOCATION_ROCK:
				//	if((((unsigned __int8)map_cell->bitfield_1_hasObject_1_isRoad_6_objTileset >> 2) & 0x3F) != 62)
				//		goto LABEL_145;
				//	sprintf(gText, "Reefs");
				//	break;
				case LOCATION_SHRINE_FIRST:
				case LOCATION_SHRINE_SECOND_ORDER:
				case LOCATION_SHRINE_THIRD_ORDER:
					{
					Spell spell_id = (Spell)(map_cell->extraInfo - 1);
					if(curHero)
						{						
						sprintf(gText, "%s\n%s%s%s%s", adventureMapLocations[map_cell->objType & 0x7F],
								"Learn {", gSpellNames[spell_id], "}",
								curHero->HasSpell(spell_id) ? "\n(Already Known)" : "");
						}
					else
						{ //no hero selected
						sprintf(gText, "%s\n%s%s%s", adventureMapLocations[map_cell->objType & 0x7F],
								"Learn {", gSpellNames[spell_id], "}");
						}
					}
					break;

				default:
					LABEL_145:
						if(v23 && curHero)
							sprintf(
								gText,
								"%s\n\n%s",
								adventureMapLocations[map_cell->objType & 0x7F],
								//&aAlreadyVisited[("(not visited)" - "(already visited)") & (((curHero->flags & v23) != 0) - 1)]
								v23 ? ((curHero->flags & v23) ? "already visited" : "not visited") : ""
								);
						else
							sprintf(gText, "%s", adventureMapLocations[map_cell->objType & 0x7F]);
						break;
				}
			}
		else
			{
			sprintf(gText, "%s", "Uncharted Territory");
			}
		}
	else
		{
		sprintf(gText, "%s", "Border");
		}
	
	//sprintf(gText, "%s", "ToDo");
	strcpy(a1, gText);
	if(giDebugLevel > 0 && map_cell)
		sprintf(
			gText,
			"gi%d obtile%d obi%d ot%d ei%d bl%d %s X%d Y%d",
			map_cell->groundIndex,
			//((unsigned __int8)map_cell->bitfield_1_hasObject_1_isRoad_6_objTileset >> 2) & 0x3F,
			map_cell->objTileset,
			map_cell->objectIndex,
			map_cell->objType,
			//(unsigned __int8)((unsigned __int8)(map_cell->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5),
			map_cell->extraInfo,
			map_cell->displayFlags & 8,
			a1,
			a2 + v9->viewX,
			a3 + v9->viewY);
	/*mov  dword ptr[ebp + evt], 200h
	mov  dword ptr[ebp + evt + 4], 3
	mov  dword ptr[ebp + evt + 8], 1
	mov  dword ptr[ebp + evt + 18h], offset ? gText@@3PADA*/
	evt.inputEvt.eventCode = INPUT_GUI_MESSAGE_CODE;
	evt.inputEvt.xCoordOrKeycode = 3;
	evt.inputEvt.yCoordOrFieldID = 1;
	evt.inputEvt.payload = gText;
	window->BroadcastMessage(evt.inputEvt);
	gpWindowManager->AddWindow(window, -1, 1);
	QuickViewWait();
	gpWindowManager->RemoveWindow(window);
	//return operator delete(window);
	delete window;
	}