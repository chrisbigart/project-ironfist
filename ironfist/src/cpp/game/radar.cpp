#include "base.h"
#include "game/game.h"


extern BOOL gbInViewWorld;
extern signed char gbThisNetHumanPlayer[];
extern unsigned char giCurPlayerBit;
extern int giViewWorldScale;
extern unsigned char giGroundToTerrain[];


void advManager::UpdateRadar(int a2, int a3)
	{
	advManager *v3; // [sp+4Ch] [bp-74h]@1
	signed int v4; // [sp+50h] [bp-70h]@84
	signed int v5; // [sp+54h] [bp-6Ch]@76
	signed int v6; // [sp+58h] [bp-68h]@66
	signed int v7; // [sp+5Ch] [bp-64h]@46
	int v8; // [sp+60h] [bp-60h]@50
	int v9; // [sp+64h] [bp-5Ch]@44
	int v10; // [sp+64h] [bp-5Ch]@65
	int v11; // [sp+64h] [bp-5Ch]@75
	int v12; // [sp+64h] [bp-5Ch]@83
	int v13; // [sp+68h] [bp-58h]@39
	int v14; // [sp+6Ch] [bp-54h]@13
	float v15; // [sp+74h] [bp-4Ch]@111
	int v16; // [sp+78h] [bp-48h]@65
	signed int v17; // [sp+7Ch] [bp-44h]@109
	int i; // [sp+80h] [bp-40h]@20
	signed int v19; // [sp+88h] [bp-38h]@2
	int v20; // [sp+8Ch] [bp-34h]@2
	int v21; // [sp+90h] [bp-30h]@65
	int a4; // [sp+94h] [bp-2Ch]@109
	int j; // [sp+9Ch] [bp-24h]@33
	signed int v24; // [sp+A0h] [bp-20h]@2
	int v25; // [sp+A4h] [bp-1Ch]@2
	int v26; // [sp+ACh] [bp-14h]@22
	unsigned __int8 v27; // [sp+B0h] [bp-10h]@1
	int v28; // [sp+B4h] [bp-Ch]@12
	int v29; // [sp+B8h] [bp-8h]@12
	signed __int8 *v30; // [sp+BCh] [bp-4h]@13

	extern int iVWMapOriginX;
	extern int iVWMapOriginY;
	static char byte_4F0A48[73]; //byte_4F0A48	db 49h	; DATA XREF : advManager__UpdateRadar(int, int) + 43C
	static char byte_4F0A28[77]; //byte_4F0A28	db 4Dh	; DATA XREF: advManager__UpdateRadar(int,int)+61Cr
	v3 = this;
	v27 = 36;
	if(a3)
		{
		v24 = this->viewX - 2;
		v19 = this->viewY - 2;
		v25 = this->viewX + 16;
		v20 = this->viewY + 16;
		if(v24 < 0)
			v24 = 0;
		if(v19 < 0)
			v19 = 0;
		if(MAP_WIDTH - 1 < v25)
			v25 = MAP_WIDTH - 1;
		if(MAP_HEIGHT - 1 < v20)
			v20 = MAP_HEIGHT - 1;
		}
	else
		{
		v24 = 0;
		v19 = 0;
		v25 = MAP_WIDTH - 1;
		v20 = MAP_HEIGHT - 1;
		}
	if(gbThisNetHumanPlayer[giCurPlayer])
		{
		gpAdvManager->field_37A = 0;
		v29 = 0;
		v28 = 0;
		switch(MAP_HEIGHT)
			{
			case 36:
				v30 = &gpWindowManager->screenBuffer->contents[128 * (20 * v19 + 80) + 480];
				v14 = 4 * v24;
				break;
			case 72:
				v30 = &gpWindowManager->screenBuffer->contents[128 * (10 * v19 + 80) + 480];
				v14 = 2 * v24;
				break;
			case 108:
				v30 = &gpWindowManager->screenBuffer->contents[128 * (5 * ((v19 + 2) / 3 + v19) + 80) + 480];
				v14 = (v24 + 2) / 3 + v24;
				v28 = v24 % 3;
				v29 = v19 % 3;
				break;
			default:
				v30 = &gpWindowManager->screenBuffer->contents[128 * (5 * v19 + 80) + 480];
				v14 = v24;
				break;
			}
		for(i = v19; v20 >= i; ++i)
			{
			v26 = (int)&v30[v14];
			switch(MAP_HEIGHT)
				{
				case 36:
					v30 += 2560;
					break;
				case 72:
					v30 += 1280;
					break;
				case 108:
					++v29;
					if(v29 > 2)
						v29 = 0;
					if(v29)
						v30 += 640;
					else
						v30 += 1280;
					break;
				case 144:
					v30 += 640;
					break;
				default:
					break;
				}
			for(j = v24; j <= v25; ++j)
				{
				if(!gbAllBlack && (unsigned __int8)(*(&mapRevealed[j] + MAP_WIDTH * i) & giCurPlayerBit))
					{
					v13 = (int)(&v3->map->tiles[i * v3->map->width] + j);
					if(*(BYTE *)(v13 + 8) & 0x40 && v3->viewX + 7 == j && v3->viewY + 7 == i)
						{
						v27 = byte_4F0A48[gpGame->players[giCurPlayer].color];
						}
					else if((*(BYTE *)(v13 + 9) & 0x7F) == 42)
						{
						v9 = gpGame->relatedToHeroForHireStatus[
							//(unsigned __int8)((unsigned __int8)(*(WORD *)(v13 + 4) >> 8) >> -5)
							(unsigned __int8)((*(WORD *)(v13 + 4) >> 3)) & 0x1FFF
							];
						if(giCurPlayer == v9)
							{
							if(v9 < 0)
								v7 = 6;
							else
								v7 = gpGame->players[v9].color;
							v27 = byte_4F0A48[v7];
							}
						}
					else
						{
						v8 = -1;
						if(*(BYTE *)(v13 + 3) == 255)
							{
							if(*(BYTE *)(v13 + 7) != 255)
								v8 = (*(BYTE *)(v13 + 6) >> 2) & 0x3F;
							}
						else
							{
							v8 = (*(BYTE *)(v13 + 2) >> 2) & 0x3F;
							}
						if(*(BYTE *)(v13 + 9) == 35
						   || v8 == 14
						   && j > 0
						   && MAP_WIDTH - 1 > j
						   // && *(v3->map->tiles[i * v3->map->width].objType + 4 * (3 * j - 3)) == 163
						   //|| *(v3->map->tiles[i * v3->map->width].objType + 4 * (3 * j + 3)) == 163
						   )
							v8 = 35;
						if(v8 != 62 || *(BYTE *)(v13 + 9) != 103)
							{
							switch(v8)
								{
								case 35:
								case 36:
									v10 = gpGame->field_2773[(unsigned __int8)((unsigned __int8)(*(WORD *)(v13 + 4) >> 8) >> -5)];
									v21 = gpGame->castles[(unsigned __int8)((unsigned __int8)(*(WORD *)(v13 + 4) >> 8) >> -5)].x;
									v16 = gpGame->castles[(unsigned __int8)((unsigned __int8)(*(WORD *)(v13 + 4) >> 8) >> -5)].y;
									if(v10 < 0)
										v6 = 6;
									else
										v6 = gpGame->players[v10].color;
									v27 = byte_4F0A48[v6];
									if(v16 - 2 > i || i > v16 || v21 - 2 > j || v21 + 2 < j)
										goto LABEL_88;
									break;
								case 22:
								case 23:
								case 24:
								case 25:
								case 26:
								case 27:
								case 31:
								case 32:
								case 33:
								case 34:
								case 42:
								case 43:
								case 44:
								case 49:
									switch(*(BYTE *)(v13 + 9))
										{
										case 1:
										case 0x17:
										case 0x1D:
										case 0x81:
										case 0x97:
										case 0x9D:
											v11 = gpGame->field_60A6[(unsigned __int8)((unsigned __int8)(*(WORD *)(v13 + 4) >> 8) >> -5)];
											if(v11 < 0)
												v5 = 6;
											else
												v5 = gpGame->players[v11].color;
											v27 = byte_4F0A48[v5];
											break;
										default:
											v27 = byte_4F0A28[(unsigned __int8)giGroundToTerrain[*(WORD *)v13]] + 3;
											break;
										}
									break;
								default:
									LABEL_88:
										switch(*(BYTE *)(v13 + 9))
											{
											case 1:
											case 0x17:
											case 0x1D:
											case 0x81:
											case 0x97:
											case 0x9D:
												v12 = gpGame->field_60A6[(unsigned __int8)((unsigned __int8)(*(WORD *)(v13 + 4) >> 8) >> -5)];
												if(v12 < 0)
													v4 = 6;
												else
													v4 = gpGame->players[v12].color;
												v27 = byte_4F0A48[v4];
												break;
											default:
												v27 = byte_4F0A28[(unsigned __int8)giGroundToTerrain[*(WORD *)v13]];
												break;
											}
										break;
								}
							}
						else
							{
							v27 = byte_4F0A28[(unsigned __int8)giGroundToTerrain[*(WORD *)v13]] + 3;
							}
						}
					}
				else
					{
					v27 = 36;
					}
				switch(MAP_HEIGHT)
					{
					case 36:
						memset((void *)v26, v27, 4u);
						memset((void *)(v26 + 640), v27, 4u);
						memset((void *)(v26 + 1280), v27, 4u);
						memset((void *)(v26 + 1920), v27, 4u);
						v26 += 4;
						break;
					case 72:
						memset((void *)v26, v27, 2u);
						memset((void *)(v26 + 640), v27, 2u);
						v26 += 2;
						break;
					case 108:
						if(v28)
							{
							if(v29)
								{
								*(BYTE *)v26++ = v27;
								}
							else
								{
								*(BYTE *)v26 = v27;
								*(BYTE *)(v26++ + 640) = v27;
								}
							}
						else if(v29)
							{
							*(BYTE *)v26 = v27;
							*(BYTE *)(v26 + 1) = v27;
							v26 += 2;
							}
						else
							{
							*(BYTE *)v26 = v27;
							*(BYTE *)(v26 + 1) = v27;
							*(BYTE *)(v26 + 640) = v27;
							*(BYTE *)(v26 + 641) = v27;
							v26 += 2;
							}
						++v28;
						if(v28 > 2)
							v28 = 0;
						break;
					case 144:
						*(BYTE *)v26++ = v27;
						break;
					default:
						continue;
					}
				}
			}
		a4 = -1;
		v17 = 0;
		if(gbInViewWorld)
			{
			switch(MAP_HEIGHT)
				{
				case 36:
					v15 = 4.0;
					v17 = 1;
					break;
				case 72:
					v15 = 2.0;
					if(giViewWorldScale > 6)
						a4 = 6;
					else
						v17 = 1;
					break;
				case 108:
					v15 = 1.33;
					if(giViewWorldScale > 4)
						{
						if(giViewWorldScale == 6)
							a4 = 9;
						else
							a4 = 8;
						}
					else
						{
						v17 = 1;
						}
					break;
				default:
					v15 = 1.0;
					if(giViewWorldScale == 4)
						{
						a4 = 7;
						}
					else if(giViewWorldScale == 6)
						{
						a4 = 6;
						}
					else
						{
						a4 = 4;
						}
					break;
				}
			}
		else
			{
			switch(MAP_HEIGHT)
				{
				case 36:
					a4 = 5;
					v15 = 4.0;
					break;
				case 72:
					a4 = 3;
					v15 = 2.0;
					break;
				case 108:
					a4 = 2;
					v15 = 1.33;
					break;
				default:
					a4 = 1;
					v15 = 1.0;
					break;
				}
			}
		if(!v17)
			{
			if(gbInViewWorld)
				v3->radarIcon->ClipFillToBuffer(
					(signed __int64)((double)iVWMapOriginX * v15 + 480.0),
					(signed __int64)((double)iVWMapOriginY * v15 + 16.0),
					a4,
					-75,
					0,
					480,
					16,
					0x90u,
					144);
			else
				v3->radarIcon->ClipFillToBuffer(
					(signed __int64)((double)v3->viewX * v15 + 480.0),
					(signed __int64)((double)v3->viewY * v15 + 16.0),
					a4,
					-75,
					0,
					480,
					16,
					0x90u,
					144);
			}
		if(a2)
			{
			if(a3)
				gpWindowManager->UpdateScreenRegion(
					(signed __int64)((double)v24 * v15 + 480.0),
					(signed __int64)((double)v19 * v15 + 16.0),
					(signed __int64)((double)(v25 - v24 + 1) * v15),
					(signed __int64)((double)(v20 - v19 + 1) * v15));
			else
				gpWindowManager->UpdateScreenRegion(480, 16, 0x90u, 144);
			}
		}
	}
