#include "base.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"

extern char ** gEventText;
extern int giMenuCommand;
extern class heroWindow * gpInitWin;
extern int lastIMHoverID;
extern class icon * gShingleAnim;
extern int iNextShingleAnim;
extern int iShingleAnimFrame;

extern void __fastcall CheckShingleUpdate(void);
extern int __fastcall PlaySmacker(int);

void __fastcall CheckShingleUpdate(void)
	{
	if(gShingleAnim)
		{
		if(KBTickCount() > iNextShingleAnim)
			{
			iNextShingleAnim = KBTickCount() + 250;
			iShingleAnimFrame = (iShingleAnimFrame + 1) % 39;
			gShingleAnim->DrawToBuffer(0 + 80, 0, iShingleAnimFrame + 1, 0);
			gpWindowManager->UpdateScreenRegion(46 + 80, 176, 0x8Bu, 187);
			}
		}
	}


//----- (00431650) --------------------------------------------------------
int __fastcall InitMenuHandler(struct tag_message& msg)
	{
	signed int result; // eax@26
	int v2; // ST48_4@29
	int v3; // [sp+Ch] [bp-24h]@27
	signed int v5; // [sp+1Ch] [bp-14h]@40
	signed int v6; // [sp+20h] [bp-10h]@4
	signed int v7; // [sp+24h] [bp-Ch]@1
	int highID; // [sp+2Ch] [bp-4h]@32
	signed int highIDa; // [sp+2Ch] [bp-4h]@40

	POINT menuHotSpots[5] =
		{
			{ 481, 185 },
			{ 83, 96 },
			{ 83, 96 },
			{ 83, 96 },
			{ 83, 96 }
		};
	
	SIZE menuHotSpotSizes[5] =
		{
				{ 64, 100 },
				{ 83, 96 },
				{ 83, 96 },
				{ 83, 96 },
				{ 83, 96 }
		};

	//if(widescreen)
		{
		for(int i = 0; i < 5; i++)
			menuHotSpots[i].x += 80;
		}

	v7 = 0;
	PollSound();
	if(BYTE1(msg.inputTypeBitmask) & 2)
		{
		if(msg.xCoordOrKeycode == 12 || msg.xCoordOrKeycode == 14)
			{
			v6 = -1;
			switch(msg.yCoordOrFieldID)
				{
				case 101:
					v6 = 0;                               // new game
					break;
				case 102:
					v6 = 1;                               // load game
					break;
				case 103:                               // high scores
					v6 = 2;
					break;
				case 104:                               // credits
					v6 = 3;
					break;
				case 105:                               // quit
					v6 = 4;
					break;
				default:
					break;
				}
			if(v6 >= 0)
				NormalDialog(gEventText[v6 + 116], 4, -1, -1, -1, 0, -1, 0, -1, 0);
			}
		}
	else
		{
		switch(msg.eventCode)
			{
			case INPUT_KEYDOWN_EVENT_CODE:
				switch(msg.xCoordOrKeycode)
					{
					case '1':
						gpWindowManager->buttonPressedCode = 101;
						v7 = 1;
						break;
					case '&':
						gpWindowManager->buttonPressedCode = 102;
						v7 = 1;
						break;
					case '.':
						gpWindowManager->buttonPressedCode = 104;
						v7 = 1;
						break;
					case '#':
						gpWindowManager->buttonPressedCode = 103;
						v7 = 1;
						break;
					case '\x10':
						gpWindowManager->buttonPressedCode = 105;
						v7 = 1;
						break;
					default:
						goto LABEL_54;
					}
				break;
			case INPUT_GUI_MESSAGE_CODE:
				if(msg.yCoordOrFieldID < 101 || msg.yCoordOrFieldID > 107)
					return 0;
				v3 = msg.xCoordOrKeycode;
				if(v3 == 12)
					{
					if(msg.yCoordOrFieldID != 107)
						{
						v2 = msg.yCoordOrFieldID - 101;
						msg.eventCode = INPUT_GUI_MESSAGE_CODE;
						msg.yCoordOrFieldID = v2 + 11;
						msg.xCoordOrKeycode = 4;
						msg.payload = (void *)(4 * v2 + 3);
						gpInitWin->BroadcastMessage(msg);
						gpInitWin->DrawWindow(0, v2 + 11, v2 + 11);
						gpWindowManager->UpdateScreenRegion(
							menuHotSpots[v2].x,
							menuHotSpots[v2].y,
							menuHotSpotSizes[v2].cx,
							menuHotSpotSizes[v2].cy);
						}
					}
				else if(v3 == 13)
					{
					if(msg.yCoordOrFieldID == 107)
						{
						//PlaySmacker(38);
						draw_mask_0 = false; draw_mask_1 = false; draw_mask_2 = false; draw_mask_3 = false; draw_mask_4 = false; draw_mask_5 = false;
						NormalDialog("Heroes 2: Widescreen v0.0.1", 1, -1, -1, -1, 0, -1, 0, -1, 0);
						gpResourceManager->GetBackdrop("heroes.icn", gpWindowManager->screenBuffer, 1);
						gpInitWin->DrawWindow(0);
						gpWindowManager->UpdateScreenRegion(0, 0, 0x280u + 160, 480);
						gpSoundManager->PlayAmbientMusic(42, 0, -1);
						}
					else
						{
						gpWindowManager->buttonPressedCode = msg.yCoordOrFieldID;
						for(highID = 11; highID <= 15; ++highID)
							{
							msg.eventCode = INPUT_GUI_MESSAGE_CODE;
							msg.yCoordOrFieldID = highID;
							msg.xCoordOrKeycode = 4;
							msg.payload = (void *)(4 * highID - 44);
							gpInitWin->BroadcastMessage(msg);
							}
						gpInitWin->DrawWindow(0, 11, 15);
						gpWindowManager->UpdateScreenRegion(0, 105, 0x235u + 160, 375);
						v7 = 1;
						}
					}
				break;
			case INPUT_MOUSEMOVE_EVENT_CODE:
				v5 = -1;
				for(highIDa = 0; highIDa < 5; ++highIDa)
					{
					if(menuHotSpots[highIDa].x <= msg.altXCoord
					   && menuHotSpots[highIDa].y <= msg.altYCoord
					   && menuHotSpots[highIDa].x + menuHotSpotSizes[highIDa].cx > msg.altXCoord
					   && menuHotSpots[highIDa].y + menuHotSpotSizes[highIDa].cy > msg.altYCoord)
						v5 = highIDa;
					}
				if(v5 != lastIMHoverID)
					{
					if(lastIMHoverID != -1)
						{
						msg.eventCode = INPUT_GUI_MESSAGE_CODE;
						msg.yCoordOrFieldID = lastIMHoverID + 11;
						msg.xCoordOrKeycode = 4;
						msg.payload = (void *)(4 * lastIMHoverID + 1);
						gpInitWin->BroadcastMessage(msg);
						gpInitWin->DrawWindow(0, lastIMHoverID + 11, lastIMHoverID + 11);
						gpWindowManager->UpdateScreenRegion(
							menuHotSpots[lastIMHoverID].x,
							menuHotSpots[lastIMHoverID].y,
							menuHotSpotSizes[lastIMHoverID].cx,
							menuHotSpotSizes[lastIMHoverID].cy);
						}
					if(v5 != -1)
						{
						msg.eventCode = INPUT_GUI_MESSAGE_CODE;
						msg.yCoordOrFieldID = v5 + 11;
						msg.xCoordOrKeycode = 4;
						msg.payload = (void *)(4 * v5 + 2);
						gpInitWin->BroadcastMessage(msg);
						gpInitWin->DrawWindow(0, v5 + 11, v5 + 11);
						gpWindowManager->UpdateScreenRegion(
							menuHotSpots[v5].x,
							menuHotSpots[v5].y,
							menuHotSpotSizes[v5].cx,
							menuHotSpotSizes[v5].cy);
						}
					lastIMHoverID = v5;
					}
				break;
			}
		}
LABEL_54:
	if(v7 || giMenuCommand != -1)
		{
		msg.eventCode = INPUT_GUI_MESSAGE_CODE;
		msg.yCoordOrFieldID = 10;
		msg.xCoordOrKeycode = msg.yCoordOrFieldID;
		result = 2;
		}
	else
		{
		CheckShingleUpdate();
		result = 1;
		}
	return result;
	}
// 4F19A8: using guessed type int giMenuCommand;
// 50CFE8: using guessed type __int16 IMHotSpots[];
// 50CFEA: using guessed type __int16 word_50CFEA[];
// 50CFEC: using guessed type __int16 word_50CFEC[];
// 50CFEE: using guessed type __int16 word_50CFEE[];
// 50D010: using guessed type int lastIMHoverID;
// 5240A8: using guessed type int gpSoundManager;