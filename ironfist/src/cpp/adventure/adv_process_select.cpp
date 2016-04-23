#include "base.h"
#include "game/game.h"
#include "spell/spells.h"
#include "combat/creatures.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"

void __fastcall NormalDialog(char *, int, int, int, int, int, int, int, int, int);

int advManager::ProcessSelect(struct tag_message * evt, class mapCell * *a3)
	{
	//var_B8 = dword ptr - 184
	//var_B4 = dword ptr - 180
	//var_B0 = dword ptr - 176
	//var_AC = dword ptr - 172
	//var_A8 = dword ptr - 168
	//var_A4 = dword ptr - 164
	//var_A0 = dword ptr - 160
	//this = dword ptr - 156
	//var_98 = byte ptr - 152
	//a2 = -124
	//var_60 = dword ptr - 96
	//var_5C = dword ptr - 92
	//var_58 = dword ptr - 88
	//var_3C = dword ptr - 60
	//var_38 = dword ptr - 56 //52 == 0x38 //int v11; // [sp+8Ch] [bp-38h]@115
	//var_34 = dword ptr - 52 
	//var_30 = dword ptr - 48
	//var_1C = dword ptr - 28
	//var_18 = dword ptr - 24
	//heroIdx = dword ptr - 20
	//var_10 = dword ptr - 16
	//var_C = dword ptr - 12
	//var_8 = dword ptr - 8
	//var_4 = dword ptr - 4
	//arg_0 = dword ptr 8
	//arg_4 = dword ptr 12
	advManager *thisa; // [sp+28h] [bp-9Ch]@1
	char v5; // [sp+2Ch] [bp-98h]@120
	tag_message a2a; // [sp+48h] [bp-7Ch]@115
	bool v7; // [sp+64h] [bp-60h]@67
	hero *v8; // [sp+68h] [bp-5Ch]@67
	int v9; // [sp+6Ch] [bp-58h]@113
	float v10; // [sp+88h] [bp-3Ch]@98
	int v11; // [sp+8Ch] [bp-38h]@115 //var_38
	int v12; // [sp+90h] [bp-34h]@122
	int v13; // [sp+94h] [bp-30h]@126
	mapCell *cell; // [sp+A8h] [bp-1Ch]@31
	int v15; // [sp+ACh] [bp-18h]@1
	int objOrHeroIdx; // [sp+B0h] [bp-14h]@3
	int quickViewY; // [sp+B4h] [bp-10h]@1
	int v18; // [sp+B8h] [bp-Ch]@38
	int quickViewX; // [sp+BCh] [bp-8h]@1
	int v20; // [sp+C0h] [bp-4h]@2

	extern DWORD showRoute;

	thisa = (advManager *)this;
	v15 = 1;
	quickViewX = evt->altXCoord;
	quickViewY = evt->altYCoord;
	switch(evt->yCoordOrFieldID)
		{
		case 0x69:
		case 0x70:
		case 0x77:
		case 0x7E:
			v20 = (evt->yCoordOrFieldID - 105) / 7;
			if(gpCurPlayer->numHeroes > v20)
				{
				objOrHeroIdx = *(&gpCurPlayer->heroesOwned[v20] + gpCurPlayer->field_3);
				if(BYTE1(evt->inputTypeBitmask) & 2)
					{
					HeroQuickView(objOrHeroIdx, v20, -1, -1);
					}
				else if(gpCurPlayer->curHeroIdx == objOrHeroIdx)
					{
					*(DWORD *)(((int)this) + 54) = 2;
					DoAdvCommand();
					}
				else
					{
					HideRoute(1, 0, 1);
					SetHeroContext(objOrHeroIdx, 0);
					}
				}
			break;
		case 0x10:
		case 0x11:
		case 0x12:
		case 0x13:
			objOrHeroIdx = *(&gpCurPlayer->_3[evt->yCoordOrFieldID + 36] + HIBYTE(gpCurPlayer->field_45));
			if(BYTE1(evt->inputTypeBitmask) & 2)
				{
				TownQuickView(objOrHeroIdx, evt->yCoordOrFieldID - 16, -1, -1);
				}
			else
				{
				HideRoute(1, 0, 1);
				if(LOBYTE(gpCurPlayer->field_45) == objOrHeroIdx)
					{
					thisa->field_36 = 3;
					*a3 = DoAdvCommand();
					}
				else
					{
					SetTownContext(objOrHeroIdx);
					}
				}
			break;
		case 0x1A:
			DoHeroKnob();
			break;
		case 0x16:
			quickViewY -= 194;
			if(gpCurPlayer->numHeroes <= 4)
				{
				v20 = 0;
				}
			else
				{
				v20 = quickViewY / 92 / (gpCurPlayer->numHeroes - 3);
				if(gpCurPlayer->numHeroes - 4 < v20)
					v20 = gpCurPlayer->numHeroes - 4;
				}
			gpCurPlayer->field_3 = v20;
			UpdateHeroLocators(1, 1);
			break;
		case 0x1B:
			DoTownKnob();
			break;
		case 0x19:
			quickViewY -= 194;
			if(gpCurPlayer->numCastles <= 4)
				{
				v20 = 0;
				}
			else
				{
				v20 = quickViewY / 92 / (gpCurPlayer->numCastles - 3);
				if(gpCurPlayer->numCastles - 4 < v20)
					v20 = gpCurPlayer->numCastles - 4;
				}
			//HIBYTE(gpCurPlayer->field_45) = v20;
				/*mov  al, byte ptr[ebp + var_4]
				mov  ecx, ? gpCurPlayer@@3PAVplayerData@@A
				mov[ecx + 46h], al*/
			*(BYTE*)&gpCurPlayer->field_45 = (BYTE)v20;
			UpdateTownLocators(1, 1);
			break;
		case 0xA:
			/*
			if(!(unsigned __int8)(*(&mapRevealed[*(DWORD *)(this + 470)]
									+ *(DWORD *)(this + 486)
									+ MAP_WIDTH * (*(DWORD *)(this + 474) + *(DWORD *)(this + 490))) & giCurPlayerBit))
			mov  eax, [ebp + this]
			mov  eax, [eax + 1EAh]
			mov  ecx, [ebp + this]
			add  eax, [ecx + 1DAh]
			imul  eax, ? MAP_WIDTH@@3HA
			mov  ecx, [ebp + this]
			mov  ecx, [ecx + 1E6h]
			mov  edx, [ebp + this]
			add  ecx, [edx + 1D6h]
			add  eax, ecx
			mov  ecx, ? mapRevealed@@3PAEA
			xor  edx, edx
			mov  dl, [eax + ecx]
			xor eax, eax
			mov  al, ? giCurPlayerBit@@3EA
			test  eax, edx
			jnz  loc_445A39
			mov[ebp + var_18], 0*/
			if(!mapRevealed[viewX  + xOff + MAP_WIDTH * (viewY + yOff)] & giCurPlayerBit)
				v15 = 0;
			cell = GetCell(xOff + viewX, yOff + viewY);
				//*(DWORD *)(this + 470) + *(DWORD *)(this + 486),
				//*(DWORD *)(this + 474) + *(DWORD *)(this + 490));
			if(BYTE1(evt->inputTypeBitmask) & 2)
				{
				if(v15)
					{
					if(thisa->xOff == 7 && thisa->yOff == 7 && gpCurPlayer->curHeroIdx != -1 && thisa->heroMobilized)
						{
						objOrHeroIdx = LOCATION_HERO;
						v18 = gpCurPlayer->curHeroIdx;
						}
					else
						{
						objOrHeroIdx = cell->objType & 0x7F;
						v18 = (unsigned __int8)((unsigned __int8)(cell
																  ->extraInfo)
																  //  ->field_4_1 >> 3) & 0x1FFF
																  //->field_4_1_1_isShadow_1_13_extraInfo
																  //>> 8) >> -5
																	);
						}
					if(objOrHeroIdx == LOCATION_TOWN)
						{
						quickViewX = 32 * thisa->xOff - 89;
						if(quickViewX < 30)
							quickViewX = 30;
						if(quickViewX + 224 > 448)
							quickViewX = 224;
						quickViewY = 32 * thisa->yOff - 70;
						if(quickViewY < 16)
							quickViewY = 16;
						if(quickViewY + 186 > 464)
							quickViewY = 278;
						TownQuickView(v18, -1, quickViewX, quickViewY);
						}
					else if(objOrHeroIdx == LOCATION_HERO)
						{
						quickViewX = 32 * thisa->xOff - 73;
						if(quickViewX < 30)
							quickViewX = 30;
						if(quickViewX + 192 > 448)
							quickViewX = 256;
						quickViewY = 32 * thisa->yOff - 72;
						if(quickViewY < 16)
							quickViewY = 16;
						if(quickViewY + 190 > 464)
							quickViewY = 274;
						HeroQuickView(v18, -1, quickViewX, quickViewY);
						}
					else if((unsigned __int8)*(&mapRevealed[thisa->viewX] + thisa->xOff + MAP_WIDTH * (thisa->viewY + thisa->yOff)) & (unsigned __int8)giCurPlayerBit)
						{
						QuickInfo(thisa->xOff, thisa->yOff);
						}
					}
				else
					{
					QuickInfo(thisa->xOff, thisa->yOff);
					}
				}
			else if(v15)
				{
				v8 = 0;
				v7 = 0;
				if(gpCurPlayer->curHeroIdx != -1)
					{
					v8 = &gpGame->heroes[gpCurPlayer->curHeroIdx];
					v7 = gpGame->IsMobile(v8->idx);
					}
				if(v8)
					{
					if(thisa->xOff == 7 && thisa->yOff == 7 && gpCurPlayer->curHeroIdx != -1 && thisa->heroMobilized)
						{
						thisa->field_36 = 2;
						DoAdvCommand();
						}
					else if((!v7
							 || evt->inputTypeBitmask & 0xC
							 || *(DWORD *)&showRoute
							 && (*(DWORD *)&v8->field_21 != thisa->field_1EE || *(DWORD *)&v8->field_25 != thisa->field_1F2))
							&& *(&gpSearchArray->field_2414[MAP_WIDTH * thisa->field_1F2].field_4 + 9 * thisa->field_1EE) & 1)
						{
						*(DWORD *)&v8->field_21 = thisa->field_1EE;
						*(DWORD *)&v8->field_25 = thisa->field_1F2;
						ShowRoute(1, 1, 1);
						}
					else
						{
						*a3 = DoAdvCommand();
						}
					}
				else
					{
					objOrHeroIdx = cell->objType & 0x7F;
					v18 = (unsigned __int8)((unsigned __int8)(cell
															  ->extraInfo)
															  //  ->field_4_1 >> 3) & 0x1FFF
															//->field_4_1_1_isShadow_1_13_extraInfo
															//>> 8) >> -5
															);
					if(objOrHeroIdx == 42)
						{
						if(gpCurPlayer->curHeroIdx == v18)
							{
							thisa->field_36 = 2;
							DoAdvCommand();
							}
						else if(gpGame->heroes[v18].ownerIdx == giCurPlayer)
							{
							SetHeroContext(v18, 0);
							}
						}
					if(objOrHeroIdx == 35)
						{
						if(LOBYTE(gpCurPlayer->field_45) == v18)
							{
							thisa->field_36 = 3;
							*a3 = DoAdvCommand();
							}
						else if(gpGame->castles[v18].ownerIdx == giCurPlayer)
							{
							SetTownContext(v18);
							}
						}
					}
				}
			break;
		case 9:
			if(BYTE1(evt->inputTypeBitmask) & 2)
				{
				NormalDialog(
					"{World Map}\n\nA miniature view of the known world.  Left click to move viewing area.",
					4,
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
				DemobilizeCurrHero();
				switch(MAP_HEIGHT)
					{
					case 36:
						v10 = 4.0;
						break;
					case 72:
						v10 = 2.0;
						break;
					case 108:
						v10 = 1.3333;
						break;
					default:
						v10 = 1.0;
						break;
					}
				quickViewX = (signed __int64)((double)(quickViewX - 480) / v10);
				quickViewY = (signed __int64)((double)(quickViewY - 16) / v10);
				thisa->viewX = quickViewX - 7;
				thisa->viewY = quickViewY - 7;
				if(thisa->viewX < -7)
					thisa->viewX = -7;
				if(thisa->viewY < -7)
					thisa->viewY = -7;
				if(MAP_WIDTH - 8 < thisa->viewX)
					thisa->viewX = MAP_WIDTH - 8;
				if(MAP_HEIGHT - 8 < thisa->viewY)
					thisa->viewY = MAP_HEIGHT - 8;
				UpdateRadar(1, 0);
				CompleteDraw(0);
				UpdateScreen(0, 0);
				v9 = 0;
				while(v9 != 16)
					{
					Process1WindowsMessage();
					struct tag_message msg1 = gpInputManager->GetEvent();
					memcpy(&v9, &msg1, sizeof(tag_message));
					memcpy(&v11, &v9, 0x1Cu);
					while(v9 != 16 && v9)
						{
						if(v9 == 4)
							memcpy(&v11, &v9, 0x1Cu);
						Process1WindowsMessage();
						struct tag_message msg2 = gpInputManager->GetEvent();
						memcpy(&v9, &msg2, sizeof(tag_message));
						}
					if(v11 == 4)
						{
						if(v12 < 480)
							v12 = 480;
						if(v12 >= 624)
							v12 = 623;
						if(v13 < 16)
							v13 = 16;
						if(v13 >= 160)
							v13 = 159;
						//(*(void(__thiscall **)(mouseManager *))(LODWORD(gpMouseManager->vtable) + 8))(gpMouseManager);
						gpMouseManager->Main(reinterpret_cast<tag_message&>(v11));
						quickViewX = (signed __int64)((double)(v12 - 480) / v10);
						quickViewY = (signed __int64)((double)(v13 - 16) / v10);
						thisa->viewX = quickViewX - 7;
						thisa->viewY = quickViewY - 7;
						if(thisa->viewX < -7)
							thisa->viewX = -7;
						if(thisa->viewY < -7)
							thisa->viewY = -7;
						if(MAP_WIDTH - 8 < thisa->viewX)
							thisa->viewX = MAP_WIDTH - 8;
						if(MAP_HEIGHT - 8 < thisa->viewY)
							thisa->viewY = MAP_HEIGHT - 8;
						UpdateRadar(1, 0);
						CompleteDraw(0);
						UpdateScreen(0, 0);
						v11 = 0;
						}
					}
				}
			break;
		case 0xB:
		case 0xC:
		case 0xD:
		case 0xE:
		case 0xF:
		case 0x14:
		case 0x15:
		case 0x17:
		case 0x18:
		case 0x1C:
		case 0x1D:
		case 0x1E:
		case 0x1F:
		case 0x20:
		case 0x21:
		case 0x22:
		case 0x23:
		case 0x24:
		case 0x25:
		case 0x26:
		case 0x27:
		case 0x28:
		case 0x29:
		case 0x2A:
		case 0x2B:
		case 0x2C:
		case 0x2D:
		case 0x2E:
		case 0x2F:
		case 0x30:
		case 0x31:
		case 0x32:
		case 0x33:
		case 0x34:
		case 0x35:
		case 0x36:
		case 0x37:
		case 0x38:
		case 0x39:
		case 0x3A:
		case 0x3B:
		case 0x3C:
		case 0x3D:
		case 0x3E:
		case 0x3F:
		case 0x40:
		case 0x41:
		case 0x42:
		case 0x43:
		case 0x44:
		case 0x45:
		case 0x46:
		case 0x47:
		case 0x48:
		case 0x49:
		case 0x4A:
		case 0x4B:
		case 0x4C:
		case 0x4D:
		case 0x4E:
		case 0x4F:
		case 0x50:
		case 0x51:
		case 0x52:
		case 0x53:
		case 0x54:
		case 0x55:
		case 0x56:
		case 0x57:
		case 0x58:
		case 0x59:
		case 0x5A:
		case 0x5B:
		case 0x5C:
		case 0x5D:
		case 0x5E:
		case 0x5F:
		case 0x60:
		case 0x61:
		case 0x62:
		case 0x63:
		case 0x64:
		case 0x65:
		case 0x66:
		case 0x67:
		case 0x68:
		case 0x6A:
		case 0x6B:
		case 0x6C:
		case 0x6D:
		case 0x6E:
		case 0x6F:
		case 0x71:
		case 0x72:
		case 0x73:
		case 0x74:
		case 0x75:
		case 0x76:
		case 0x78:
		case 0x79:
		case 0x7A:
		case 0x7B:
		case 0x7C:
		case 0x7D:
			break;
		}
	if(BYTE1(evt->inputTypeBitmask) & 2 && evt->yCoordOrFieldID >= 2000 && evt->yCoordOrFieldID <= 2200)
		NormalDialog(
			"{Status Window}\n\nThis window provides information on the status of your hero or kingdom, and shows the date.  Left click here to cycle through these windows.",
			4,
			-1,
			-1,
			-1,
			0,
			-1,
			0,
			-1,
			0);
	return 1;
	}