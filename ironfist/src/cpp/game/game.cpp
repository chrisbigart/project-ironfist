#include "base.h"
#include "game/game.h"
#include "spell/spells.h"
#include "combat/creatures.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"

#include "scripting/hook.h"
#include "scripting/scripting.h"

#include <iostream>
#include "xbrz/xbrz.h"

extern DWORD dword_4F1CC0;
extern int giLimitUpdMinX;
extern class mouseManager* gpMouseManager;
extern int gbNoCDRom;

int heroWindowManager::Open(int a2)
	{
	//int original_width = this->screenBuffer->width;
	//int original_height = this->screenBuffer->height;

	int res = this->Open_orig(a2);

	//this->screenBuffer->width = original_width;
	//this->screenBuffer->height = original_height;
	this->screenBuffer->width = 800;
	this->screenBuffer->height = 640;
//	//heroWindowManager *thisa; // ebx@1
//	//bitmap *v3; // eax@1
//
//	//thisa = this;
//	//InitVideo();
//	//memset(gpBufferPalette->contents, 0, 0x300u);
//	//SetPalette(gpBufferPalette->contents, 1);
//	//v3 = (bitmap *)operator new(26);
//	//if(v3)
//	//	thisa->screenBuffer = bitmap::bitmap(v3);
//	//else
//	//	thisa->screenBuffer = 0;
//	//if(!thisa->screenBuffer)
//	//	MemError();
//	//thisa->screenBuffer->setInConstructor = 33;
//	//thisa->screenBuffer->width = 640;
//	//thisa->screenBuffer->height = 480;
//	//thisa->screenBuffer->contents = (signed __int8 *)lpInitWin;
//	//memset(thisa->screenBuffer->contents, 0x24u, 0x4B000u);
//	//thisa->idx = a2;
//	//thisa->type = 32;
//	//thisa->ready = 1;
//	//strcpy(thisa->name, "heroWindowManager");
	return res;
	}


//draw_mask_4 (keyboard "5")
int __fastcall WGAppPaint_orig(void *, void *);
int __fastcall WGAppPaint(void* thisptr, void* ptr2)
	{
	HDC v2; // [sp+Ch] [bp-78h]@2
	HWND hWnd; // [sp+10h] [bp-74h]@1
	struct tagPAINTSTRUCT Paint; // [sp+20h] [bp-64h]@2
	int v5; // [sp+60h] [bp-24h]@2
	int v6; // [sp+64h] [bp-20h]@2
	int v7; // [sp+68h] [bp-1Ch]@2
	char v8; // [sp+70h] [bp-14h]@1
	struct tagRECT Rect; // [sp+74h] [bp-10h]@2
	
	extern void* hpalApp;
	//extern HPALETTE hpalApp;
	extern void* hdcImage;
	extern int giScrollX;
	extern int giScrollY;
	hWnd = (HWND)thisptr;
	v8 = 0;
	if(draw_mask_4)
		return WGAppPaint_orig(thisptr, ptr2);

	////if(dword_530418)
	//if(lpInitWin)
	//	{
	//	v2 = BeginPaint(hWnd, &Paint);
	//	SelectPalette(v2, (HPALETTE)hpalApp, 0);
	//RealizePalette(v2);
	//GetClientRect(hWnd, &Rect);
	//v7 = Rect.right - Rect.left;
	//v5 = 0 / iMainWinScreenWidth;
	//v6 = 0 / iMainWinScreenHeight;
	//if(giScrollX)
	//	v5 += giScrollX;
	//if(giScrollY)
	//	v6 += giScrollY;
	////++dword_519704;
	//if(iMainWinScreenWidth != 640 || iMainWinScreenHeight != 480)
	//	{
	//	/*old_blt_mode = SetStretchBltMode(hdcDst, COLORONCOLOR);
	//	ret = StretchBlt(hdcDst, xDst, yDst, widthDst, heightDst,
	//					 hdcSrc, xSrc, ySrc, widthSrc, heightSrc, SRCCOPY);
	//	SetStretchBltMode(hdcDst, old_blt_mode);*/
	//	int old_blt_mode = SetStretchBltMode(v2, COLORONCOLOR);
	//	StretchBlt(
	//		v2,
	//		0,
	//		0,
	//		v7,
	//		Rect.bottom - Rect.top,
	//		(HDC)hdcImage,
	//		v5,
	//		v6,
	//		640 * v7 / iMainWinScreenWidth,
	//		480 * (Rect.bottom - Rect.top) / iMainWinScreenHeight,
	//		SRCCOPY);
	//	SetStretchBltMode(v2, old_blt_mode);
	//	}
	//else
	//	{
	//	v7 = Paint.rcPaint.right - (unsigned __int16)(Paint.rcPaint.left & 0xFFFC) + 1;
	//	BitBlt(
	//		v2,
	//		Paint.rcPaint.left & 0xFFFC,
	//		Paint.rcPaint.top,
	//		v7,
	//		Paint.rcPaint.bottom - Paint.rcPaint.top + 1,
	//		(HDC)hdcImage,
	//		giScrollX + (unsigned __int16)(Paint.rcPaint.left & 0xFFFC),
	//		giScrollY + Paint.rcPaint.top,
	//		MERGECOPY);
	//	}
	//EndPaint(hWnd, &Paint);
	//}
	//return 1;
































	//return 1;
	///////////////
	if(lpInitWin)
		{
		//InvalidateRect(hWnd, &Rect, false);
		v2 = BeginPaint(hWnd, &Paint);
		SelectPalette(v2, (HPALETTE)hpalApp, 0);
		RealizePalette(v2);
		GetClientRect(hWnd, &Rect);

		v7 = Rect.right - Rect.left;
		v5 = 0 / iMainWinScreenWidth;
		v6 = 0 / iMainWinScreenHeight;
		//extern DWORD dword_519704;
		extern int giScrollX;
		extern int giScrollY;
		if(giScrollX)
			v5 += giScrollX;
		if(giScrollY)
			v6 += giScrollY;
		//++dword_519704;
		//_thunk_WinGStretchBlt@40
		//extern int __stdcall _thunk_WinGStretchBlt(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
		//extern int (*_thunk_WinGStretchBlt)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
		
		//extern void* __imp__WinGStretchBlt;
		//int(*WinGStretchBlt_impl)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD) = (int(*)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))__imp__WinGStretchBlt;
		//BOOL WINAPI WinGStretchBlt(HDC hdcDst, INT xDst, INT yDst, INT widthDst, INT heightDst, HDC hdcSrc, INT xSrc, INT ySrc, INT widthSrc, INT heightSrc);
		//extern void* _thunk_WinGStretchBlt;
		if(iMainWinScreenWidth != 640 || iMainWinScreenHeight != 480)
			{
			//thunk_WinGStretchBlt(
			//_thunk_WinGStretchBlt_impl(
			int sz = Rect.bottom - Rect.top;
			/*	__asm
				{
				mov  eax, [ebp + v7]
				lea  eax, [eax + eax * 2]
					lea  eax, [eax + eax * 4]
					shl  eax, 5
					cdq
					idiv iMainWinScreenHeight
					push  eax
					mov  eax, [ebp + sz]
					lea  eax, [eax + eax * 4]
					shl  eax, 7
					cdq
					idiv iMainWinScreenWidth
					push  eax
					mov  eax, [ebp + v6]
					push  eax
					mov  eax, [ebp + v5]
					push  eax
					mov  eax, hdcImage
					push  eax
					mov  eax, [ebp + sz]
					push  eax
					mov  eax, [ebp + v7]
					push  eax
					mov  eax, 0 ;; [ebp + var_68]
					push  eax
					mov  eax, 0 ;; [ebp + var_70]
				push  eax
				mov  eax, [ebp + v2]
				push  eax
				call  _thunk_WinGStretchBlt
				}*/
				//WinGStretchBlt_impl(
				//	(int)v2,
				//	///v2,
				//	0,
				//	0,
				//	v7,
				//	Rect.bottom - Rect.top,
				//	(int)hdcImage,
				//	//(HDC)hdcImage,
				//	v5,
				//	v6,
				//	640 * v7 / iMainWinScreenWidth,
				//	480 * (Rect.bottom - Rect.top) / iMainWinScreenHeight);

			static HDC buffer_hdc = nullptr;
			static HBITMAP buffer_bmp = nullptr;
			//static uint32_t* buffer = nullptr;
			if(!buffer_hdc)
				{
				BITMAP bm1;
				HBITMAP screenbmp = (HBITMAP)GetCurrentObject((HDC)hdcImage, OBJ_BITMAP);
				GetObject(screenbmp, sizeof(BITMAP), &bm1);
				std::cout << bm1.bmWidth << ", " << bm1.bmWidthBytes << "\n";

				buffer_hdc = CreateCompatibleDC((HDC)hdcImage);
				buffer_bmp = CreateCompatibleBitmap((HDC)hdcImage, 1600, -960);
				SelectObject(buffer_hdc, buffer_bmp);
				//buffer = new uint32_t[1280 * 960 * 3];
				//int res = GetDIBits((HDC)hdcImage, )
				BITMAP bm; 
				GetObject(buffer_bmp, sizeof(BITMAP), &bm);
				std::cout << bm.bmWidth << ", " << bm.bmWidthBytes << "\n";
				}
			//float factor = .25;
			//bitmap* screen = gpWindowManager->screenBuffer;
			//if(!draw_mask_5)
			//	{
	
			//	//xbrz::nearestNeighborScale((const uint32_t*)screen->contents,
			//	//						   (int)screen->width * factor, (int)screen->height * factor,
			//	//						   (uint32_t*)buffer->contents,
			//	//						   (int)buffer->width * factor, (int)buffer->height * factor);

			//	////memcpy(screen->contents, buffer->contents, 480 * 480 );
			//	//memcpy(screen->contents, screen->contents + 480, 480 * 480);

			//	}
			//int mode = GetStretchBltMode((HDC)hdcImage);
			SetStretchBltMode((HDC)hdcImage, COLORONCOLOR);
			SetStretchBltMode(buffer_hdc, COLORONCOLOR);
			BOOL res = BitBlt(buffer_hdc, 0, 0, 800, 480, (HDC)hdcImage, 0, 0, SRCCOPY);
			bitmap* screen = gpWindowManager->screenBuffer;

			static uint32_t* srcbuf = new uint32_t[640 * 480];
			static uint32_t* dstbuf = new uint32_t[1600 * 960];

			int pos = 0;
			if(!draw_mask_6)
				{
				BITMAP bm;
				GetObject(buffer_bmp, sizeof(BITMAP), &bm);
				//xbrz::scale(2, (const uint32_t*)screen->contents, (uint32_t*)bm.bmBits, 500, 400);
				xbrz::nearestNeighborScale((const uint32_t*)screen->contents, 320, 240, (uint32_t*)bm.bmBits, 640, 480);
				/*for(int y = 0; y < 960; y++)
					for(int x = 0; x < 1280; x++)
						{
						COLORREF c = dstbuf[pos++];
						SetPixel(buffer_hdc, x, y, c);
						}*/
				}

			if(!draw_mask_6)
				{
				pos = 0;
				for(int y = 0; y < 480; y++)
					for(int x = 0; x < 640; x++)
						{
						COLORREF c = GetPixel((HDC)hdcImage, x, y);
						srcbuf[pos++] = c;
						//SetPixel(buffer_hdc, x, y, c);
						}
				//xbrz::nearestNeighborScale(srcbuf, 640, 480, dstbuf, 1280, 960);
				xbrz::scale(2, srcbuf, dstbuf, 640, 480);
				
				pos = 0;
				for(int y = 0; y < 960; y++)
					for(int x = 0; x < 1600; x++)
						{
						COLORREF c = dstbuf[pos++];
						SetPixel(buffer_hdc, x, y, c);
						}
				}

			if(iMainWinScreenWidth != 800 || iMainWinScreenHeight != 600)
				{
				//int old_blt_mode = SetStretchBltMode(v2, HALFTONE);
				int old_blt_mode = SetStretchBltMode(v2, COLORONCOLOR);

				StretchBlt(
					(HDC)v2,
					///v2,
					0,
					0,
					v7,
					Rect.bottom - Rect.top,
					(HDC)buffer_hdc,
					//(HDC)hdcImage,
					v5,
					v6,
					800 * v7 / iMainWinScreenWidth,
					480 * (Rect.bottom - Rect.top) / iMainWinScreenHeight,
					SRCCOPY);
				SetStretchBltMode(v2, old_blt_mode);
				}
			else
				{
				v7 = Paint.rcPaint.right - (unsigned __int16)(Paint.rcPaint.left & 0xFFFC) + 1;
				BitBlt(
					(HDC)v2,
					Paint.rcPaint.left & 0xFFFC,
					Paint.rcPaint.top,
					v7,
					Paint.rcPaint.bottom - Paint.rcPaint.top + 1,
					(HDC)buffer_hdc,
					//(HDC)hdcImage,
					giScrollX + (unsigned __int16)(Paint.rcPaint.left & 0xFFFC),
					giScrollY + Paint.rcPaint.top,
					SRCCOPY);
				}
			
			}
		else
			{
			v7 = Paint.rcPaint.right - (unsigned __int16)(Paint.rcPaint.left & 0xFFFC) + 1;
			BitBlt(
				(HDC)v2,
				Paint.rcPaint.left & 0xFFFC,
				Paint.rcPaint.top,
				v7,
				Paint.rcPaint.bottom - Paint.rcPaint.top + 1,
				(HDC)hdcImage,
				giScrollX + (unsigned __int16)(Paint.rcPaint.left & 0xFFFC),
				giScrollY + Paint.rcPaint.top,
				SRCCOPY);
			}
		EndPaint(hWnd, &Paint);
		}
	//return WGAppPaint_orig(thisptr, ptr2);
	return 1;
	}


//draw_mask_0 (keyboard "1")
void advManager::CompleteDraw(int left, int top, int a6, int a5)
	{
	if(draw_mask_0)
		return this->CompleteDraw_orig(left, top, a6, a5);
	
	int v5; // edx@1
	signed int a4; // [sp+10h] [bp-8h]@5
	signed int a4a; // [sp+10h] [bp-8h]@11
	signed int a4b; // [sp+10h] [bp-8h]@20
	signed int a4c; // [sp+10h] [bp-8h]@46
	signed int a4d; // [sp+10h] [bp-8h]@52
	int a3; // [sp+14h] [bp-4h]@7
	int a3a; // [sp+14h] [bp-4h]@13
	int a3b; // [sp+14h] [bp-4h]@17
	int a3c; // [sp+14h] [bp-4h]@23
	int a3d; // [sp+14h] [bp-4h]@26
	int a3e; // [sp+14h] [bp-4h]@30
	int a3f; // [sp+14h] [bp-4h]@33
	int a3g; // [sp+14h] [bp-4h]@36
	int a3h; // [sp+14h] [bp-4h]@40
	int a3i; // [sp+14h] [bp-4h]@43
	int a3j; // [sp+14h] [bp-4h]@48
	int a3k; // [sp+14h] [bp-4h]@54


	const int width = 20;
	const int height = 15;

	PollSound();
	if(a6 || bShowIt)
		{
		giLimitUpdMinX = -1;
		this->field_1DE = this->viewX;
		this->field_1E2 = this->viewY;
		if(gbAllBlack)
			{
			this->viewY = 0;
			this->viewX = this->viewY;
			}
		gpMouseManager->couldBeShowMouse = 0;
		this->field_2A2 = 0;
		this->field_2AE = 0;

		for(a4 = 0; a4 < height; ++a4)
			{
			for(a3 = 0; a3 < width; ++a3)
				advManager::DrawCell(a3 + left, top + a4, a3, a4, 1, a6); //0ub0000 0001
			}
		for(a4a = 0; a4a < height; ++a4a)
			{
			for(a3a = 0; a3a < width; ++a3a)
				advManager::DrawCell(a3a + left, top + a4a, a3a, a4a, 255, a6); //0ub1000 0000
			}

		for(a3b = 0; a3b < width; ++a3b)
			advManager::DrawCell(a3b + left, top, a3b, 0, 2, a6);  //0ub0000 0010

		for(a4b = 1; a4b < height; ++a4b)
			{
			PollSound();
			if(this->field_27E <= 4)  //field_27e==S1cursorDirection  //scrolling-related?  and/or the interface
				{
				for(a3e = width - 1; a3e >= 0; --a3e)
					advManager::DrawCell(a3e + left, top + a4b - 1, a3e, a4b - 1, 8, a6); //0ub0000 1000
				for(a3f = width - 1; a3f >= 0; --a3f)
					advManager::DrawCell(a3f + left, top + a4b - 1, a3f, a4b - 1, 4, a6); //0ub0000 0100
				}
			else
				{
				for(a3c = 0; a3c < width; ++a3c)
					advManager::DrawCell(a3c + left, top + a4b - 1, a3c, a4b - 1, 8, a6); //0ub0000 1000
				for(a3d = 0; a3d < width; ++a3d)
					advManager::DrawCell(a3d + left, top + a4b - 1, a3d, a4b - 1, 4, a6); //0ub0000 0100
				}
			for(a3g = 0; a3g < width; ++a3g)
				advManager::DrawCell(a3g + left, top + a4b, a3g, a4b, 2, a6);  //0ub0000 0010
			}

		for(a3h = 0; a3h < width; ++a3h)
			advManager::DrawCell(a3h + left, top + 14, a3h, 14, 8, a6); //0ub0000 1000
		for(a3i = 0; a3i < width; ++a3i)
			advManager::DrawCell(a3i + left, top + 14, a3i, 14, 4, a6); //0ub0000 0100

		for(a4c = 0; a4c < height; ++a4c)
			{
			for(a3j = 0; a3j < width; ++a3j)
				advManager::DrawCell(a3j + left, top + a4c, a3j, a4c, 64, a6); //0ub0100 0000  //0x40
			}
		for(a4d = 0; a4d < height; ++a4d)
			{
			for(a3k = 0; a3k < width; ++a3k)
				advManager::DrawCell(a3k + left, top + a4d, a3k, a4d, 32, a6); //0ub0010 0000  //0x20
			}
		advManager::DrawAdventureBorder();
		gpMouseManager->couldBeShowMouse = 1;
		PollSound();
		//if(a5)
		//	advManager::UpdBottomView(0, 1, 1);
		if(gbAllBlack)
			{
			this->viewX = this->field_1DE;
			this->viewY = this->field_1E2;
			}
		}

	return;

	this->CompleteDraw_orig(left, top, a6, a5);
	}

//draw_mask_1 (keyboard "2")
int advManager::ComboDraw(int a2, int a3, int a4)
	{
	if(draw_mask_1)
		return ComboDraw_orig(a2, a3, a4);

	if(!bShowIt)
		return 0;
	//if(this->field_2AE)
	//	{
		advManager::CompleteDraw(a2, a3, 0, 1);
		return 1;
	//	}
	}

//
//void advManager::SaveAdventureBorder()
//	{
//	void *result; // eax@1
//	int v2; // [sp+Ch] [bp-10h]@1
//	signed int i; // [sp+10h] [bp-Ch]@2
//	signed int j; // [sp+10h] [bp-Ch]@5
//	signed int k; // [sp+10h] [bp-Ch]@8
//	int v6; // [sp+14h] [bp-8h]@2
//	signed __int8 *v7; // [sp+18h] [bp-4h]@2
//
//	const int SCREEN_WIDTH = 800;
//	const int SCREEN_HEIGHT = 480;
//
//	v2 = this;
//	result = (void *)this;
//	if(!*(_DWORD *)(this + 186))
//		{
//		*(_DWORD *)(this + 186) = BaseAlloc(0x7400u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50FAE8 + 4);
//		v6 = *(_DWORD *)(v2 + 186);
//		result = gpWindowManager->screenBuffer->contents;
//		v7 = gpWindowManager->screenBuffer->contents;
//		for(i = 0; i < 16; ++i)
//			{
//			result = memcpy((void *)v6, v7, 0x1E0u);
//			v7 += 640;
//			v6 += 480;
//			}
//		for(j = 16; j < 464; ++j)
//			{
//			memcpy((void *)v6, v7, 0x10u);
//			result = memcpy((void *)(v6 + 16), v7 + 464, 0x10u);
//			v7 += 640;
//			v6 += 32;
//			}
//		for(k = 464; k < 480; ++k)
//			{
//			result = memcpy((void *)v6, v7, 0x1E0u);
//			v7 += 640;
//			v6 += 480;
//			}
//		}
//	return result;
//	}


//draw_mask_2 (keyboard "3")
void advManager::DrawAdventureBorder()
	{
	void *result; // eax@1
	signed int i; // [sp+10h] [bp-Ch]@3
	signed int j; // [sp+10h] [bp-Ch]@6
	signed int k; // [sp+10h] [bp-Ch]@9
	//int v6; // [sp+14h] [bp-8h]@3
	__int8* v6;
	signed __int8 *v7; // [sp+18h] [bp-4h]@3
	//return;

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;
	static widget* day_display_widget = nullptr;
	if(!day_display_widget)
		{
		char* content = new char[128];
		memset(content, 0, 128);
		sprintf(content, "%s: %d  %s: %d", "Month", gpGame->month, "Week", gpGame->week);
		day_display_widget = new textWidget(
				120 + 479,
				//424,
				2,
				145,
				12,
				content,
				"smalfont.fnt",
				1,
				2100,
				512,
				1);
		
		this->adventureScreen->AddWidget(day_display_widget, -1);
		}

	if(draw_mask_2)
		return advManager::DrawAdventureBorder_orig();

	//result = (void *)this;
	extern DWORD dword_4F2E80;
	//if(*(_DWORD *)(this + 186) && !dword_4F2E80)
	__int8* unknown = (__int8*)field_BA;  //could be related to evil/good interface
	if(unknown)// && !dword_4F2E80)
		{
		v7 = gpWindowManager->screenBuffer->contents;
		///result = *(void **)(this + 186);
		//v6 = *(_DWORD *)(this + 186);
		v6 = unknown;
		for(i = 0; i < 16; ++i) //top portion of border
			{
			//result = 
			memcpy(v7, (const void *)v6, 0x1E0u);
			v7 += SCREEN_WIDTH;
			v6 += 480;
			}
		for(j = 16; j < 464; ++j)
			{
			memcpy(v7, (const void *)v6, 0x10u); //left side
			//result = memcpy(v7 + 464, (const void *)(v6 + 16), 0x10u); //right side
			v7 += 640;
			v6 += 32;
			}
		for(k = 464; k < 480; ++k) //bottom
			{
			//result = 
			memcpy(v7, (const void *)v6, 0x1E0u);
			v7 += SCREEN_WIDTH;
			v6 += 480;
			}
		}
	//return result;
	return;
	}


void advManager::RedrawAdvScreen(int a2, int a3)
	{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;
	if(bShowIt)
		{
		/*int old_width =	gpWindowManager->screenBuffer->width;
		gpWindowManager->screenBuffer->width = 640;
		gpResourceManager->GetBackdrop("advbord.icn", gpWindowManager->screenBuffer, 1);
		gpWindowManager->screenBuffer->width = old_width;
		*/
		if(a3)
			{
			//BaseFree((void *)this->field_BA, (int)"F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F7C0 + 9);
			this->field_BA = 0;
			}
		//SaveAdventureBorder();
		UpdateHeroLocators(0, 0);
		UpdateTownLocators(0, 0);
		UpdBottomView(1, 0, 0);
		/*for(int x = 0; x < 2; x++)
			for(int y = 0; y < 12; y++)
				{
				widget* w = gpAdvManager->someComponents[x][y];
				if(!w)
					continue;
				if(w->offsetX >= 480 && w->offsetX < 640)
					w->offsetX += 160;

				w->Draw();
				}*/
		//widget* w = gpAdvManager->someComponents[x][y];
		widget* w = adventureScreen->firstWidget;
		while(w)
			{
			if(w->offsetX >= 480 && w->offsetX < 640)
				w->offsetX += 160;
			
			w->Draw();
			w = w->nextInLinkedList;
			}
		this->adventureScreen->DrawWindow(0, 2000, 2200);
		//if(a4)
			gpWindowManager->UpdateScreenRegion(480+160, 392, 0x8Fu, 71);
		adventureScreen->DrawWindow(0);
		if(a2)
			gpWindowManager->UpdateScreenRegion(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		UpdateRadar(a2, 0);
		CompleteDraw(this->viewX, this->viewY, 0, 1);
		if(a2)
			UpdateScreen(0, 0);
		}
	}



//draw_mask_3 (keyboard "4")
extern "C" void __fastcall BlitBitmapToScreenVesa_orig(bitmap* bmp, int x, int y, unsigned int width, int height, int screenX, signed int screenY);

extern "C" void __fastcall BlitBitmapToScreenVesa(bitmap* bmp, int x, int y, unsigned int width, int height, int screenX, signed int screenY)
	{
	int v7; // ebp@2
	signed int v8; // ebx@3
	int v9; // eax@3
	int v10; // esi@4
	int v11; // eax@14
	RECT Rect; // [sp+14h] [bp-10h]@28
				//return;


	if(draw_mask_3)
		return BlitBitmapToScreenVesa_orig(bmp, x, y, width, height, screenX, screenY);
		

	static int original_width = 640;
	original_width = 800;
	gpWindowManager->screenBuffer->width = original_width;
	if(width == 640)
		width = original_width;

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;
	//if(screenX >= 480)
	//	screenX += 160;

	if(!bmp)
		return;

	if(gpWindowManager->screenBuffer == bmp || (v7 = 0, height <= 0))
		{
		v8 = width;
		}
	else
		{
		v8 = width;
		v9 = original_width * screenY;
		do
			{
			v10 = v7++ + y;
			memcpy(&gpWindowManager->screenBuffer->contents[screenX] + v9, &bmp->contents[bmp->width * v10] + x, width);
			v9 += original_width;
			} while(v7 < height);
		}
	//if(gbEnlargeScreenBlit && !*(&bMenu + 7 * giCurExe + 5))
	if(gbEnlargeScreenBlit)// && !*(&bMenu + 7 * giCurExe + 5)) //if gbEnlargeScreenBlit && !(fullscreen)
		{
		if(iMainWinScreenWidth != 640 || iMainWinScreenHeight != 480)
			{
			if(screenX > 0)
				--screenX;
			if(screenY > 0)
				--screenY;
			if(v8 < (original_width - 3))
				v8 += 4;
			if(height < (original_width - 3))
				{
				v11 = height + 4;
				goto LABEL_23;
				}
			}
		else
			{
			if(v8 < original_width)
				++v8;
			if(height < original_width)
				{
				v11 = height + 1;
			LABEL_23:
				height = v11;
				goto LABEL_24;
				}
			}
		}
LABEL_24:
	/*if(dword_4F1CC0) //something to do with networking?
	{
	if(screenY >= 411)
	return;
	if(height + screenY >= 411)
	height = 411 - screenY;
	}*/
	Rect.left = screenX * iMainWinScreenWidth / SCREEN_WIDTH;
	Rect.top = iMainWinScreenHeight * screenY / SCREEN_HEIGHT;
	Rect.right = iMainWinScreenWidth * (v8 + screenX) / SCREEN_WIDTH - 1;
	Rect.bottom = iMainWinScreenHeight * (height + screenY) / SCREEN_HEIGHT - 1;

	if(!InvalidateRect((HWND)hwndApp, &Rect, 0))
		LogStr("InvalidateRect Failed");
	if(!UpdateWindow((HWND)hwndApp))
		LogStr("UpdateWindow Failed");

	}

//void __thiscall advManager::DrawCell(advManager *this, int x, int y, int a3, int a4, char a5, int a6)
void advManager::DrawCell(int x, int y, int a3, int a4, int DRAW_BITMASK, int a6)
	{
	//if((DRAW_BITMASK & 1) && !draw_mask_0)
	//	return;
	//if((DRAW_BITMASK & 2) && !draw_mask_1)
	//	return;
	//if((DRAW_BITMASK & 4) && !draw_mask_2)
	//	return;
	//if((DRAW_BITMASK & 8) && !draw_mask_3)
	//	return;

	this->DrawCell_orig(x, y, a3, a4, DRAW_BITMASK, a6);
	}



int __fastcall KeyboardMessageHandler_orig(void *, unsigned int, unsigned int, long);
int __fastcall KeyboardMessageHandler(void *a1, unsigned int a2, unsigned int a3, long a4)
	{
	const int KEYCODE_KEY_1 = 49;
	const int KEYCODE_KEY_2 = 50;
	const int KEYCODE_KEY_3 = 51;
	const int KEYCODE_KEY_4 = 52;
	const int KEYCODE_KEY_5 = 53;
	const int KEYCODE_KEY_6 = 54;
	const int KEYCODE_KEY_7 = 55;
	/*
	if(evt->eventCode == INPUT_KEYDOWN_EVENT_CODE)
		{
		if(evt->xCoordOrKeycode == 88 && evt->inputTypeBitmask & 3)
			heroWindowManager::ScreenShot(gpWindowManager);
	*/
	//1 == 49
	tag_message *evt; // esi@5
	//evt = &gpInputManager->inputInstances[gpInputManager->currentInfoField];

	//if(evt->eventCode == INPUT_KEYDOWN_EVENT_CODE)
	if(a2 & 1)
		{
		if(a3 == KEYCODE_KEY_1)
			draw_mask_0 = !draw_mask_0;
		if(a3 == KEYCODE_KEY_2)
			draw_mask_1 = !draw_mask_1;
		if(a3 == KEYCODE_KEY_3)
			draw_mask_2 = !draw_mask_2;
		if(a3 == KEYCODE_KEY_4)
			draw_mask_3 = !draw_mask_3;
		if(a3 == KEYCODE_KEY_5)
			draw_mask_4 = !draw_mask_4;
		if(a3 == KEYCODE_KEY_6)
			draw_mask_5 = !draw_mask_5;
		if(a3 == KEYCODE_KEY_7)
			draw_mask_6 = !draw_mask_6;
		}
	return KeyboardMessageHandler_orig(a1, a2, a3, a4);
	}

///

char* gAlignmentNames[13] = { "Knight", "Barbarian", "Sorceress", "Warlock", "Wizard", "Necromancer",
"Multiple", "Random", NULL, NULL, NULL, NULL,
"Cyborg" };

int game::GetRandomNumTroops(int creat)
	{
	return Random(gMonRandBound[creat][0], gMonRandBound[creat][1]);
	}

int game::SetupGame() {
	int oldNoCDRom = gbNoCDRom;
	gbNoCDRom = 0;
	int res = this->SetupGame_orig();
	gbNoCDRom = oldNoCDRom;
	return res;
}

void game::RandomizeHeroPool() {
	signed int idx;

	for( idx = 0; idx < MAX_HEROES; idx++) {
		this->heroes[idx].experience = Random(0, 50) + 40;
		this->SetRandomHeroArmies(idx, 0);
		this->heroes[idx].remainingMobility = this->heroes[idx].CalcMobility();
		this->heroes[idx].mobility = this->heroes[idx].remainingMobility;
		this->heroes[idx].randomSeed = Random(1, 255);
		this->heroes[idx].wisdomLastOffered = 1;
		switch(this->heroes[idx].factionID) {
		case FACTION_SORCERESS:
			this->heroes[idx].AddSpell(SPELL_BLESS);
			break;
		case FACTION_WARLOCK:
			this->heroes[idx].AddSpell(SPELL_CURSE);
			break;
		case FACTION_NECROMANCER:
			this->heroes[idx].AddSpell(SPELL_HASTE);
			break;
		case FACTION_WIZARD:
			this->heroes[idx].AddSpell(SPELL_STONESKIN);
			break;
		}
	}
}

void game::NewMap(char* mapname) {
    this->ResetIronfistGameState();
	this->NewMap_orig(mapname);
    ScriptingInit(mapname);
}

void game::NextPlayer() {
	/*
	 * Because heroes no longer regain movement on hire.
	 * we need to make sure all heroes in hero pool regain movement between turns.
	 */
	NextPlayer_orig();
	for(int i = 0; i < MAX_HEROES; i++) {
		hero *h = &this->heroes[i];
		h->mobility = h->CalcMobility();
		h->remainingMobility = h->mobility;
	}
}

void game::PerDay() {
	this->PerDay_orig();
	ScriptSignal(SCRIPT_EVT_NEW_DAY, "");
}

void game::ResetIronfistGameState() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            this->sharePlayerVision[i][j] = 0;
        }
    }
}