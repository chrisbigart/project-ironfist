#include "base.h"
#include "game/game.h"
#include "manager.h"

//
//bool __cdecl advManager::MouseInScrollZone()
//	{
//	int y; // [sp+10h] [bp-8h]@1
//	int x; // [sp+14h] [bp-4h]@1
//
//	mouseManager::MouseCoords(&x, &y);
//	return x >= 0 && x < 640 && y >= 0 && y < 480 && (x < 16 || x > 623 || y < 16 || y > 464);
//	}

int __fastcall InMapArea(int x, int y)
	{
	//return x >= 16 && x < 448 && y >= 16 && y < 448;
	const int NUMBER_OF_MAPSQUARES_WIDTH = 20;
	return x >= 16 && x < (NUMBER_OF_MAPSQUARES_WIDTH * 32 - 32) && y >= 16 && y < 448;

	}

struct tagPOINT retrieveVirtualCursorCoordinates_lppoint;
void mouseManager::MouseCoords(int& x, int& y)
	{
	GetCursorPos(&retrieveVirtualCursorCoordinates_lppoint);
	ScreenToClient((HWND)hwndApp, &retrieveVirtualCursorCoordinates_lppoint);
	x = 800 * retrieveVirtualCursorCoordinates_lppoint.x / iMainWinScreenWidth;
	y = 480 * retrieveVirtualCursorCoordinates_lppoint.y / iMainWinScreenHeight;
	}

extern BOOL gbPutzingWithMouseCtr;
extern BOOL gbColorMice;

void __fastcall CheckChangeCursor(signed int a1, signed int a2, int a3)
	{
	int result; // eax@1
	int v4; // [sp-4h] [bp-Ch]@12

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;

	result = bInCheckChangeCursor;
	if(!bInCheckChangeCursor)
		{
		//result = 28 * giCurExe;
		//if(!*(&bMenu + 7 * giCurExe + 5) || a3) //if(!fullscreen
		if(a3)
			{
			//if(*(BOOL *)((char *)&bMenu + result + 24)) //?
				{
				bInCheckChangeCursor = 1;
				if(a3 || a1 >= 0 && a1 < SCREEN_WIDTH && a2 >= 0 && a2 < SCREEN_HEIGHT)
					{
					if(bLastMouseOffscreen)
						{
						bLastMouseOffscreen = 0;
						gpMouseManager->SetPointer(1000);
						}
					result = bLastOnscreenMouseColor;
					if(bLastOnscreenMouseColor == gbColorMice)
						goto LABEL_18;
					v4 = 1;
					}
				else
					{
					result = bLastMouseOffscreen;
					if(bLastMouseOffscreen)
						goto LABEL_18;
					bLastMouseOffscreen = 1;
					bLastOnscreenMouseColor = gbColorMice;
					if(!gbColorMice)
						goto LABEL_18;
					v4 = 0;
					}
				gpMouseManager->SetColorMice(v4);
			LABEL_18:
				bInCheckChangeCursor = 0;
				//return result;
				return;
				}
			}
		}
	//return result;
	}



void mouseManager::ReallyShowPointer()
	{
	int result; // eax@2
	__int32 v3; // eax@5
	__int32 v4; // edx@5

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;
	POINT Point;

	if (gbColorMice)
		{
		result = this->cursorDisabled;
		if (result > 0)
			{
			--result;
			this->cursorDisabled = result;
			if (!result)
				{
				++gbPutzingWithMouseCtr;
				if (gbColorMice)
					{
					GetCursorPos(&Point);
					ScreenToClient((HWND)hwndApp, &Point);
					v3 = SCREEN_WIDTH * Point.x / iMainWinScreenWidth;
					field_56 = v3;
					v4 = SCREEN_HEIGHT * Point.y / iMainWinScreenHeight;
					field_5A = v4;
					CheckChangeCursor(v3, v4, 0);
					}
				NewUpdate(1);
				result = gbPutzingWithMouseCtr-- - 1;
				}
			}
		}
	else
		{
		result = ShowCursor(1);
		}
	//return result;
	}


#pragma pack(push, 1)
struct CursorHotspot
	{
	char x;
	char y;
	};
struct CursorDimension
	{
	char width;
	char height;
	};
#pragma pack(pop)


//? IMHotSpots@@3PAY03GA
//extern unsigned short* (IMHotSpots[4]);
extern unsigned short (*IMHotSpots)[4];
//extern __int16 IMHotSpots[];

void mouseManager::SaveAndDraw()
	{
	int v1; // edx@1
	mouseManager *thisa; // esi@1
	int cursorIdx; // edi@1
	int newCursorWidth; // eax@1
	int *widthPtr; // ecx@1
	int v6; // eax@3
	int v7; // edi@3
	int *heightPtr; // edx@3
	int width; // ecx@5

	extern signed char iMouseSize_asm[][2];
	extern signed char iHotSpot_asm[][2];
	CursorHotspot* iHotSpot = (CursorHotspot*)(iHotSpot_asm);
	CursorDimension* iMouseSize = (CursorDimension*)(iMouseSize_asm);

	const int SCREEN_WIDTH = 800;

	auto spots = IMHotSpots;

	v1 = this->field_66;
	thisa = this;
	cursorIdx = this->cursorIdx;
	newCursorWidth = iMouseSize[cursorIdx].width;
	widthPtr = &this->cursorWidth;
	if(v1 + newCursorWidth > SCREEN_WIDTH)
		newCursorWidth = SCREEN_WIDTH - v1;
	*widthPtr = newCursorWidth;
	v6 = iMouseSize[cursorIdx].height;
	v7 = thisa->field_6A;
	heightPtr = &thisa->cursorHeight;
	if(v7 + v6 > 480)
		v6 = 480 - v7;
	width = *widthPtr;
	*heightPtr = v6;
	gpWindowManager->screenBuffer->CopyToCareful(
		thisa->bitmap,
		0,
		0,
		thisa->cursorTopLeftX,
		thisa->cursorTopLeftY,
		width,
		*heightPtr);
	IconToBitmap(
		thisa->cursorIcon,
		gpWindowManager->screenBuffer,
		thisa->field_66,
		thisa->field_6A,
		thisa->spriteIdx,
		1,
		0,
		0,
		640u,
		480,
		0);
	}

void mouseManager::RestoreUnderlying()
	{
	this->bitmap->CopyToCareful(
		gpWindowManager->screenBuffer,
		this->cursorTopLeftX,
		this->cursorTopLeftY,
		0,
		0,
		this->cursorWidth,
		this->cursorHeight);
	}

void mouseManager::NewUpdate(int a2)
	{
	mouseManager *thisa; // esi@1
	__int32 v3; // eax@7
	__int32 v4; // edx@7
	int v5; // edx@10
	int v6; // edi@12
	int v7; // edx@12
	int v8; // ecx@12
	int v9; // edx@12
	int v10; // ebx@12
	int v11; // eax@12
	int v12; // ecx@24
	int v13; // ecx@32
	int v14; // eax@34
	int v15; // ecx@51
	int v16; // ebx@51
	int *v17; // edi@51
	int v18; // edx@51
	int v19; // ebp@54
	int v20; // edx@54
	int *v21; // ebx@54

	extern BOOL bInNewMouseUpdate;
	POINT Point;
	extern signed char iMouseSize_asm[][2];
	extern signed char iHotSpot_asm[][2];
	CursorHotspot* iHotSpot = (CursorHotspot*)(iHotSpot_asm);
	CursorDimension* iMouseSize = (CursorDimension*)(iMouseSize_asm);

	//if(draw_mask_5)
	//	return NewUpdate_orig(a2);

	DWORD dword_5330B0;
	DWORD dword_533B38;
	DWORD dword_533B3C;
	DWORD dword_534748;

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;

	thisa = this;
	if((!this->cursorDisabled || a2) && this->couldBeShowMouse && !bInNewMouseUpdate)
		{
		bInNewMouseUpdate = 1;
		++gbPutzingWithMouseCtr;
		if(!a2)
			{
			if(!gbColorMice)
				goto LABEL_61;
			GetCursorPos(&Point);
			ScreenToClient((HWND)hwndApp, &Point);
			v3 = SCREEN_WIDTH * Point.x / iMainWinScreenWidth;
			thisa->field_56 = v3;
			v4 = SCREEN_HEIGHT * Point.y / iMainWinScreenHeight;
			thisa->field_5A = v4;
			CheckChangeCursor(v3, v4, 0);
			}
		if(gbColorMice)
			{
			if(a2
			   || (v5 = thisa->cursorIdx, thisa->field_56 - iHotSpot[v5].x != thisa->field_66)
			   || thisa->field_5A - iHotSpot[v5].y != thisa->field_6A)
				{
				dword_5330B0 = thisa->cursorTopLeftX;
				dword_533B38 = thisa->cursorTopLeftY;
				dword_533B3C = thisa->field_6E;
				dword_534748 = thisa->field_72;
				v6 = thisa->cursorIdx;
				v7 = thisa->field_5A;
				v8 = thisa->field_56 - iHotSpot[v6].x;
				thisa->field_66 = v8;
				v9 = v7 - iHotSpot[v6].y;
				thisa->field_6A = v9;
				v10 = iMouseSize[v6].width + v8 - 1;
				thisa->field_6E = v10;
				v11 = iMouseSize[v6].height + v9 - 1;
				thisa->field_72 = v11;
				if(v10 > (SCREEN_WIDTH - 1))
					thisa->field_6E = (SCREEN_WIDTH - 1);
				if(v11 > (SCREEN_HEIGHT - 1))
					thisa->field_72 = (SCREEN_HEIGHT - 1);
				thisa->cursorTopLeftX = 0;
				if(v8 >= 0)
					thisa->cursorTopLeftX = v8;
				thisa->cursorTopLeftY = 0;
				if(v9 >= 0)
					thisa->cursorTopLeftY = v9;
				if(dword_5330B0 <= (SCREEN_WIDTH - 1) && dword_533B38 <= (SCREEN_HEIGHT - 1) && dword_533B3C >= 0 && dword_534748 >= 0)
					{
					v12 = thisa->cursorTopLeftX;
					if(dword_533B3C >= v12
					   && thisa->field_6E >= dword_5330B0
					   && thisa->cursorTopLeftY <= dword_534748
					   && thisa->field_72 >= dword_533B38)
						{
						if(dword_5330B0 > v12)
							dword_5330B0 = thisa->cursorTopLeftX;
						if(dword_533B38 > thisa->cursorTopLeftY)
							dword_533B38 = thisa->cursorTopLeftY;
						v13 = thisa->cursorTopLeftX;
						if(dword_533B3C < iMouseSize[thisa->cursorIdx].width + v13 - 1)
							dword_533B3C = iMouseSize[thisa->cursorIdx].width + v13 - 1;
						v14 = iMouseSize[thisa->cursorIdx].height + thisa->cursorTopLeftY - 1;
						if(dword_534748 >= v14)
							goto LABEL_43;
						goto LABEL_42;
						}
					if(dword_533B3C > (SCREEN_WIDTH - 1))
						dword_533B3C = (SCREEN_WIDTH - 1);
					if(dword_534748 > (SCREEN_HEIGHT - 1))
						dword_534748 = (SCREEN_HEIGHT - 1);
					//BlitBitmapToScreenNoMouseCheck(
					BlitBitmapToScreenVesa(
						gpWindowManager->screenBuffer,
						dword_5330B0,
						dword_533B38,
						dword_533B3C - dword_5330B0 + 1,
						dword_534748 - dword_533B38 + 1,
						dword_5330B0,
						dword_533B38);
					}
				dword_5330B0 = thisa->cursorTopLeftX;
				dword_533B38 = thisa->cursorTopLeftY;
				dword_533B3C = thisa->cursorTopLeftX + iMouseSize[thisa->field_4A].width - 1;
				v14 = thisa->cursorTopLeftY + iMouseSize[thisa->field_4A].height - 1;
			LABEL_42:
				dword_534748 = v14;
			LABEL_43:
				if(dword_5330B0 <= (SCREEN_WIDTH - 1) && dword_533B38 <= (SCREEN_HEIGHT - 1) && dword_533B3C >= 0 && dword_534748 >= 0)
					{
					if(dword_533B3C > (SCREEN_WIDTH - 1))
						dword_533B3C = (SCREEN_WIDTH - 1);
					if(dword_534748 > (SCREEN_HEIGHT - 1))
						dword_534748 = (SCREEN_HEIGHT - 1);
					v15 = thisa->cursorTopLeftX;
					v16 = thisa->cursorIdx;
					v17 = &thisa->cursorWidth;
					v18 = iMouseSize[v16].width;
					if(v15 + v18 <= SCREEN_WIDTH)
						*v17 = v18;
					else
						*v17 = SCREEN_WIDTH - v15;
					v19 = iMouseSize[v16].height;
					v20 = thisa->cursorTopLeftY;
					v21 = &thisa->cursorHeight;
					if(v20 + v19 <= SCREEN_HEIGHT)
						*v21 = v19;
					else
						*v21 = SCREEN_HEIGHT - v20;
					gpWindowManager->screenBuffer->CopyToCareful(bitmap, 0, 0, v15, v20, *v17, *v21);
					if(!thisa->cursorDisabled)
						IconToBitmap(
							thisa->cursorIcon,
							gpWindowManager->screenBuffer,
							thisa->field_66,
							thisa->field_6A,
							thisa->spriteIdx,
							1,
							0,
							0,
							SCREEN_WIDTH,
							480,
							0);
					//BlitBitmapToScreenNoMouseCheck(
					BlitBitmapToScreenVesa(
						gpWindowManager->screenBuffer,
						dword_5330B0,
						dword_533B38,
						dword_533B3C - dword_5330B0 + 1,
						dword_534748 - dword_533B38 + 1,
						dword_5330B0,
						dword_533B38);
					bitmap->CopyToCareful(
						gpWindowManager->screenBuffer,
						thisa->cursorTopLeftX,
						thisa->cursorTopLeftY,
						0,
						0,
						*v17,
						*v21);
					}
				thisa->field_4A = thisa->cursorIdx;
				goto LABEL_61;
				}
			}
	LABEL_61:
		bInNewMouseUpdate = 0;
		--gbPutzingWithMouseCtr;
		}
	}


#define SHIWORD(l)             ((SHORT)((LONG)(l) >> 16))
//int __fastcall MouseMessageHandler(void *, unsigned int, unsigned int, long)
int __fastcall MouseMessageHandler(void* hWnd, unsigned int msg, unsigned int wParam, long lParam)
	{
	int msga; // edi@1
	tag_message *evt; // esi@7
	int v7; // eax@20
	int v8; // eax@22
	int y; // edx@27
	int x; // edi@27
	int v11; // eax@44
	int v12; // [sp-4h] [bp-10h]@37


	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;

	msga = msg;
	if(!gpInputManager)
		return 1;
	if(gpInputManager->ready != 1)
		return 1;
	if(gpInputManager->readingInputMutex)
		return 1;
	gpInputManager->readingInputMutex = 1;
	evt = &gpInputManager->inputInstances[gpInputManager->currentInfoField];
	evt->inputTypeBitmask = 0;
	evt->altYCoord = 0;
	evt->altXCoord = 0;
	evt->yCoordOrFieldID = 0;
	evt->xCoordOrKeycode = 0;
	evt->eventCode = (INPUT_EVENT_CODE)0;
	switch(msg)
		{
		case WM_MOUSEFIRST:
			evt->eventCode = INPUT_MOUSEMOVE_EVENT_CODE;
			goto LABEL_17;
		case WM_LBUTTONDOWN:
			evt->eventCode = INPUT_LEFT_CLICK_EVENT_CODE;
			SetCapture((HWND)hwndApp);
			goto LABEL_17;
		case WM_LBUTTONUP:
			evt->eventCode = INPUT_LEFT_UP_EVENT_CODE;
			if(!ReleaseCapture())
				LogStr("ReleaseCapture Failed");
			goto LABEL_17;
		case WM_LBUTTONDBLCLK:
			evt->eventCode = INPUT_LEFT_CLICK_EVENT_CODE;
			goto LABEL_17;
		case WM_RBUTTONDOWN:
			evt->eventCode = INPUT_RIGHT_CLICK;
			SetCapture((HWND)hwndApp);
			goto LABEL_17;
		case WM_RBUTTONUP:
			evt->eventCode = INPUT_RIGHT_UP_EVENT_CODE;
			if(!ReleaseCapture())
				LogStr("ReleaseCapture Failed");
			goto LABEL_17;
		case WM_RBUTTONDBLCLK:
			evt->eventCode = INPUT_RIGHT_CLICK;
		LABEL_17:
			evt->xCoordOrKeycode = SCREEN_WIDTH * (signed __int16)lParam / iMainWinScreenWidth;
			evt->yCoordOrFieldID = SCREEN_HEIGHT * SHIWORD(lParam) / iMainWinScreenHeight;
			evt->altXCoord = evt->xCoordOrKeycode;
			evt->altYCoord = evt->yCoordOrFieldID;
			
			extern int iLastBWOnScreenCheck;
			extern long __fastcall KBTickCount();
			//todo fix this
			//if(!*(&bMenu + 7 * giCurExe + 5)) //if(!fullscreen)
				{
				//if(!*(&bMenu + 7 * giCurExe + 6)) //if(!color_cursor)
				if(false)
					{
					if(KBTickCount() > iLastBWOnScreenCheck)
						{
						v7 = evt->xCoordOrKeycode;
						if(v7 > 3)
							{
							if(v7 < SCREEN_WIDTH - 4)
								{
								v8 = evt->yCoordOrFieldID;
								if(v8 > 3)
									{
									if(v8 < SCREEN_HEIGHT - 4)
										{
										iLastBWOnScreenCheck = KBTickCount() + 500;
										gpMouseManager->SetPointer(1000);
										}
									}
								}
							}
						}
					}
				}
			break;
		default:
			break;
		}
	if(msga == WM_MOUSEMOVE)
		{
		if(gpMouseManager)
			{
			y = evt->yCoordOrFieldID;
			x = evt->xCoordOrKeycode;
			if(!bInCheckChangeCursor)
				{
				//if(!*(&bMenu + 7 * giCurExe + 5) && *(&bMenu + 7 * giCurExe + 6)) //if(!fullscreen && colorMouse)
					{
					bInCheckChangeCursor = 1;
					if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
						{
						if(bLastMouseOffscreen)
							goto LABEL_42;
						bLastMouseOffscreen = 1;
						bLastOnscreenMouseColor = gbColorMice;
						if(!gbColorMice)
							goto LABEL_42;
						v12 = 0;
						}
					else
						{
						if(bLastMouseOffscreen)
							{
							bLastMouseOffscreen = 0;
							gpMouseManager->SetPointer(1000);
							}
						if(bLastOnscreenMouseColor == gbColorMice)
							goto LABEL_42;
						v12 = 1;
						}
					gpMouseManager->SetColorMice(v12);
				LABEL_42:
					bInCheckChangeCursor = 0;
					goto LABEL_43;
					}
				}
			}
		}
LABEL_43:
	if(evt->eventCode)
		{
		evt->inputTypeBitmask = gpInputManager->forSettingBitmask;
		++gpInputManager->currentInfoField;
		gpInputManager->currentInfoField = (((unsigned __int64)gpInputManager->currentInfoField >> 32) ^ abs(gpInputManager->currentInfoField) & 0x3F)
			- ((unsigned __int64)gpInputManager->currentInfoField >> 32);
		v11 = gpInputManager->currentInputEvt;
		if(gpInputManager->currentInfoField == v11)
			{
			gpInputManager->currentInputEvt = v11 + 1;
			gpInputManager->currentInputEvt = (((unsigned __int64)gpInputManager->currentInputEvt >> 32) ^ abs(gpInputManager->currentInputEvt) & 0x3F)
				- ((unsigned __int64)gpInputManager->currentInputEvt >> 32);
			}
		}
	gpInputManager->readingInputMutex = 0;
	return evt->eventCode < 1u;
	}
