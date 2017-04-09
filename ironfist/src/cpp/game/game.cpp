#include "base.h"
#include "game/game.h"
#include "spell/spells.h"
#include "combat/creatures.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"

#include "scripting/hook.h"
#include "scripting/scripting.h"

#include <iostream>
#include <map>
#include "xbrz/xbrz_indexed.h"

extern DWORD dword_4F1CC0;

bool draw_mask_0 = true;
bool draw_mask_1 = true;
bool draw_mask_2 = true;
bool draw_mask_3 = true;
bool draw_mask_4 = true;
bool draw_mask_5 = true;
bool draw_mask_6 = true;

int heroWindowManager::Open(int a2)
	{
	//int original_width = this->screenBuffer->width;
	//int original_height = this->screenBuffer->height;

	int res = this->Open_orig(a2);

	//this->screenBuffer->width = original_width;
	//this->screenBuffer->height = original_height;
	this->screenBuffer->width = 800;
	this->screenBuffer->height = 480;
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

	//return 1;
	///////////////
	if(lpInitWin)
		{
		//InvalidateRect(hWnd, &Rect, false);
		v2 = BeginPaint(hWnd, &Paint);
		SelectPalette(v2, (HPALETTE)hpalApp, 0);
		RealizePalette(v2);
		GetClientRect(hWnd, &Rect);


		std::cout << "GetClientRect:\t["
			<< Rect.left << ", " << Rect.top << ", " << Rect.bottom << ", " << Rect.right
			<< "]\n";

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
		if(iMainWinScreenWidth != 640 || iMainWinScreenHeight != 480)
			{
			//thunk_WinGStretchBlt(
			//_thunk_WinGStretchBlt_impl(
			int sz = Rect.bottom - Rect.top;
			
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
			static BITMAP bm1;
			static BITMAP bm2; 
			if(!buffer_hdc)
				{
				HBITMAP screenbmp = (HBITMAP)GetCurrentObject((HDC)hdcImage, OBJ_BITMAP);
				GetObject(screenbmp, sizeof(BITMAP), &bm1);
				std::cout << bm1.bmWidth << ", " << bm1.bmWidthBytes << "\n";

				buffer_hdc = CreateCompatibleDC(0);
				//buffer_hdc = CreateCompatibleDC((HDC)hdcImage);
				void* bits = 0;
				BITMAPINFO bmp_info;
				thunk_WinGRecommendDIBFormat(&bmp_info);
				bmp_info.bmiHeader.biBitCount = 32;
				bmp_info.bmiHeader.biWidth = 1600;
				bmp_info.bmiHeader.biHeight = -960;
				buffer_bmp = CreateDIBSection(buffer_hdc, &bmp_info, DIB_RGB_COLORS, &bits, 0, 0);
				//buffer_bmp = CreateCompatibleBitmap((HDC)hdcImage, 1600, -960);
				SelectObject(buffer_hdc, buffer_bmp);
				//buffer = new uint32_t[1280 * 960 * 3];
				//int res = GetDIBits((HDC)hdcImage, )
				
				GetObject(buffer_bmp, sizeof(BITMAP), &bm2);
				std::cout << bm2.bmWidth << ", " << bm2.bmWidthBytes << "\n";
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
			/*struct _PALETTE {
    WORD        palVersion;
	WORD        palNumEntries;
	_Field_size_opt_(palNumEntries) PALETTEENTRY        palPalEntry[1];
				};*/
			//extern struct LogicalPalette;
			//LOGPALETTE curpal = *(LOGPALETTE*)&LogicalPalette;
			SetStretchBltMode((HDC)hdcImage, COLORONCOLOR);
			SetStretchBltMode(buffer_hdc, COLORONCOLOR);
			//BOOL res = BitBlt(buffer_hdc, 0, 0, 800, 480, (HDC)hdcImage, 0, 0, SRCCOPY);
			StretchBlt(buffer_hdc, 0, 0, 1600, 960, (HDC)hdcImage, 0, 0, 800, 480, SRCCOPY);
			bitmap* screen = gpWindowManager->screenBuffer;

			static uint32_t* srcbuf = new uint32_t[800 * 480];
			//static uint32_t* dstbuf = new uint32_t[1600 * 960];

			int pos = 0;
			//if(!draw_mask_7)
			//	{
			//	BITMAP bm;
			//	GetObject(buffer_bmp, sizeof(BITMAP), &bm);
			//	//xbrz::scale(2, (const uint32_t*)screen->contents, (uint32_t*)bm.bmBits, 500, 400);
			//	xbrz::nearestNeighborScale((const uint32_t*)screen->contents, 320, 240, (uint32_t*)bm.bmBits, 640, 480);
			//	/*for(int y = 0; y < 960; y++)
			//		for(int x = 0; x < 1280; x++)
			//			{
			//			COLORREF c = dstbuf[pos++];
			//			SetPixel(buffer_hdc, x, y, c);
			//			}*/
			//	}

			static const unsigned char colors[] = { 0x00,0xff,0xff,0xff,0x96,0xff,0xff,0x64,0xff,0xff,0x32,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0xb4,0x00,0xff,0x00,0xff,0x00,0xc9,0xc9,0xff,0xb9,0xb9,0xff,0xfc,0xfc,0xfc,0xf0,0xf0,0xf0,0xe8,0xe8,0xe8,0xdc,0xdc,0xdc,0xd4,0xd4,0xd4,0xc8,0xc8,0xc8,0xc0,0xc0,0xc0,0xb4,0xb4,0xb4,0xac,0xac,0xac,0xa4,0xa4,0xa4,0x98,0x98,0x98,0x90,0x90,0x90,0x84,0x84,0x84,0x7c,0x7c,0x7c,0x70,0x70,0x70,0x68,0x68,0x68,0x5c,0x5c,0x5c,0x54,0x54,0x54,0x48,0x48,0x48,0x40,0x40,0x40,0x38,0x38,0x38,0x2c,0x2c,0x2c,0x24,0x24,0x24,0x18,0x18,0x18,0x10,0x10,0x10,0x04,0x04,0x04,0x00,0x00,0x00,0xfc,0xec,0xdc,0xf0,0xdc,0xc8,0xe8,0xd0,0xb8,0xe0,0xc4,0xa8,0xd8,0xb8,0x98,0xd0,0xa8,0x88,0xc8,0xa0,0x78,0xc0,0x94,0x6c,0xb8,0x88,0x60,0xac,0x7c,0x54,0xa4,0x70,0x48,0x9c,0x68,0x3c,0x94,0x60,0x34,0x8c,0x54,0x2c,0x84,0x4c,0x20,0x7c,0x44,0x1c,0x74,0x3c,0x14,0x68,0x34,0x10,0x60,0x30,0x0c,0x58,0x28,0x08,0x50,0x24,0x04,0x48,0x1c,0x04,0x3c,0x18,0x00,0x34,0x14,0x00,0x2c,0x10,0x00,0x24,0x0c,0x00,0xc0,0xcc,0xfc,0xac,0xb8,0xf0,0x98,0xa8,0xe8,0x88,0x98,0xe0,0x78,0x88,0xd8,0x68,0x78,0xd0,0x58,0x68,0xc4,0x4c,0x58,0xbc,0x40,0x4c,0xb4,0x34,0x40,0xac,0x28,0x34,0xa4,0x20,0x30,0x98,0x1c,0x28,0x90,0x14,0x24,0x88,0x10,0x20,0x80,0x0c,0x1c,0x78,0x08,0x18,0x70,0x04,0x14,0x64,0x04,0x14,0x5c,0x00,0x10,0x54,0x00,0x0c,0x4c,0x00,0x0c,0x44,0xac,0xe0,0x9c,0x9c,0xd4,0x8c,0x90,0xcc,0x80,0x80,0xc0,0x70,0x74,0xb8,0x64,0x68,0xb0,0x5c,0x5c,0xa4,0x50,0x50,0x9c,0x44,0x48,0x90,0x3c,0x3c,0x88,0x30,0x34,0x7c,0x28,0x2c,0x74,0x24,0x24,0x6c,0x1c,0x20,0x64,0x18,0x18,0x5c,0x14,0x14,0x54,0x0c,0x0c,0x4c,0x08,0x08,0x40,0x04,0x04,0x38,0x04,0x04,0x30,0x00,0x00,0x28,0x00,0x00,0x20,0x00,0x00,0x18,0x00,0xfc,0xf4,0xd0,0xf8,0xe8,0xac,0xf4,0xe0,0x8c,0xf0,0xdc,0x6c,0xec,0xd4,0x50,0xe8,0xcc,0x34,0xe4,0xc8,0x14,0xe0,0xc4,0x00,0xd8,0xbc,0x20,0xd0,0xb0,0x1c,0xc8,0xa0,0x18,0xbc,0x98,0x18,0xb4,0x8c,0x18,0xa8,0x7c,0x14,0x9c,0x70,0x10,0x94,0x64,0x0c,0x88,0x58,0x0c,0x7c,0x4c,0x08,0x74,0x44,0x08,0x68,0x3c,0x00,0x60,0x30,0x00,0x54,0x28,0x00,0x4c,0x20,0x00,0xe4,0xcc,0xf8,0xd8,0xbc,0xec,0xc8,0xa8,0xe4,0xc0,0x9c,0xd8,0xb4,0x8c,0xd0,0xa8,0x7c,0xc4,0x9c,0x70,0xbc,0x90,0x64,0xb4,0x84,0x58,0xa8,0x78,0x4c,0xa0,0x70,0x44,0x94,0x64,0x38,0x8c,0x5c,0x30,0x80,0x50,0x28,0x78,0x48,0x20,0x6c,0x40,0x18,0x64,0x38,0x14,0x5c,0x2c,0x08,0x50,0x20,0x04,0x44,0x18,0x00,0x38,0x10,0x00,0x2c,0xb4,0xf4,0xfc,0xa8,0xe8,0xf0,0xa0,0xe0,0xe8,0x94,0xd8,0xe0,0x88,0xcc,0xd4,0x80,0xc4,0xcc,0x78,0xb8,0xc4,0x70,0xb0,0xbc,0x64,0xa8,0xb0,0x5c,0x9c,0xa8,0x58,0x94,0xa0,0x50,0x8c,0x94,0x48,0x80,0x8c,0x40,0x74,0x80,0x38,0x68,0x74,0x30,0x60,0x6c,0x28,0x54,0x60,0x20,0x4c,0x58,0x1c,0x40,0x4c,0x14,0x38,0x40,0x10,0x2c,0x38,0x0c,0x24,0x2c,0x08,0x1c,0x24,0xfc,0xe4,0xe4,0xf4,0xd0,0xd0,0xf0,0xbc,0xbc,0xe8,0xac,0xac,0xe4,0x9c,0x9c,0xdc,0x8c,0x8c,0xd8,0x7c,0x7c,0xd0,0x6c,0x6c,0xcc,0x5c,0x5c,0xc4,0x50,0x50,0xc0,0x44,0x44,0xbc,0x38,0x38,0xb8,0x2c,0x2c,0xb4,0x24,0x24,0xa8,0x20,0x20,0x9c,0x18,0x18,0x90,0x10,0x10,0x84,0x0c,0x0c,0x78,0x08,0x08,0x6c,0x04,0x04,0x60,0x00,0x00,0x54,0x00,0x00,0x48,0x00,0x00,0xfc,0xe4,0x9c,0xf8,0xd8,0x8c,0xf4,0xd0,0x7c,0xf0,0xc4,0x70,0xec,0xb8,0x60,0xe8,0xac,0x50,0xe4,0xa0,0x44,0xe0,0x90,0x38,0xe0,0x84,0x2c,0xcc,0x74,0x20,0xb8,0x64,0x18,0xa4,0x58,0x10,0x94,0x48,0x08,0x80,0x3c,0x04,0x6c,0x30,0x00,0x5c,0x28,0x00,0xfc,0x58,0x0c,0xdc,0x34,0x04,0xc0,0x14,0x00,0xa4,0x00,0x00,0xfc,0xfc,0x00,0xfc,0xcc,0x00,0xc0,0x8c,0x00,0x8c,0x48,0x00,0xa4,0xd0,0x00,0x94,0xbc,0x00,0x84,0xac,0x00,0x78,0x9c,0x04,0x68,0x8c,0x04,0x5c,0x78,0x04,0x4c,0x68,0x04,0x40,0x58,0x04,0x34,0x48,0x04,0x28,0x78,0xd0,0x18,0x68,0xc4,0x04,0x48,0xb4,0x00,0x38,0xac,0x0c,0x54,0xbc,0x00,0x38,0xac,0x00,0x40,0xb4,0x84,0xe0,0xfc,0x00,0x98,0xfc,0x00,0x50,0xe4,0x00,0x00,0xa4,0x8c,0x8c,0xbc,0x70,0x70,0x9c,0x54,0x54,0x7c,0x3c,0x3c,0x5c,0xa9,0xa9,0xff,0x99,0x99,0xff,0x89,0x89,0xff,0x79,0x79,0xff,0x69,0x69,0xff,0x59,0x59,0xff,0x49,0x49,0xff,0x39,0x39,0xff,0x29,0x29,0xff,0x19,0x19,0xff };

			std::map<unsigned int, unsigned char> reverse_palette;
			//uint32_t* color_table = (uint32_t*)colors;

			if(!draw_mask_6)
				{
				//xbrz::nearestNeighborScale((uint8_t*)bm1.bmBits, 800, 480, (uint8_t*)bm2.bmBits, 1600, 960);
				pos = 0;
				//for(int y = 0; y < 480; y++)
				//	for(int x = 0; x < 800; x++)
				RECT AdjustedRect;
				//AdjustedRect.left = (Rect.left * 800) / iMainWinScreenWidth;
				//AdjustedRect.right = (Rect.right * 800) / iMainWinScreenWidth;
				//AdjustedRect.top = (Rect.top * 480) / iMainWinScreenHeight;
				//AdjustedRect.bottom = (Rect.bottom * 480) / iMainWinScreenHeight;
				//for(int y = AdjustedRect.top; y < AdjustedRect.bottom; y++)
				//	for(int x = AdjustedRect.left; x < AdjustedRect.right; x++)
				for(int y = 0; y < 480; y++)
					for(int x = 0; x < 800; x++)
						{
						//COLORREF c = GetPixel((HDC)hdcImage, x, y);
						unsigned char palettized_color = ((unsigned char*)bm1.bmBits)[y * bm1.bmWidthBytes + x];
						unsigned char r = colors[palettized_color * 3 + 0];
						unsigned char g = colors[palettized_color * 3 + 1];
						unsigned char b = colors[palettized_color * 3 + 2];
						uint32_t c = (r << 8*2) | (g << 8) | b;
						
						//reverse_palette[c] = palettized_color;
						//pos = y * 800 + x;
						srcbuf[pos++] = c;
						//SetPixel(buffer_hdc, x, y, c);
						}
				//xbrz::nearestNeighborScale(srcbuf, 800, 480, dstbuf, 1600, 960);
				//xbrz::ScalerCfg cfg;
				//cfg.equalColorTolerance_ = 0;
				xbrz::scale(2, srcbuf, (uint32_t*)bm2.bmBits, 800, 480);
				//xbrz::scale(2, srcbuf, dstbuf, Rect.right - Rect.left, Rect.top - Rect.bottom);
				
				pos = 0;

				//for(int y = AdjustedRect.top*2; y < AdjustedRect.bottom*2; y++)
				//	for(int x = AdjustedRect.left*2; x < AdjustedRect.right*2; x++)
				//for(int y = 0; y < 960 / 4; y++)
				//	for(int x = 0; x < 1600 / 4; x++)
				//		{
				//		//uint32_t c = dstbuf[pos];
				//		//((unsigned char*)bm2.bmBits)[pos++] = reverse_palette[c];
				//		pos = y * 960 + x;
				//		COLORREF c = dstbuf[pos];
				//		SetPixel(buffer_hdc, x, y, c);
				//		}
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
					1600 * v7 / iMainWinScreenWidth,
					960 * (Rect.bottom - Rect.top) / iMainWinScreenHeight,
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


	extern long __fastcall KBTickCount();
	void __fastcall Process1WindowsMessage();

	int CELLS_WIDTH = 20;
	int CELLS_HEIGHT = 15;
//draw_mask_1 (keyboard "2")
int advManager::ComboDraw(int view_x, int view_y, int a4)
	{
	if(draw_mask_1)
		return ComboDraw_orig(view_x, view_y, a4);

	signed int result; // eax@2
	int v5; // edx@11
	mapCell *v7; // [sp+10h] [bp-18h]@19
	mapCell *v8; // [sp+10h] [bp-18h]@81
	signed int a4a; // [sp+14h] [bp-14h]@11
	signed int a4b; // [sp+14h] [bp-14h]@55
	signed int a4c; // [sp+14h] [bp-14h]@69
	signed int a4d; // [sp+14h] [bp-14h]@79
	signed int a4e; // [sp+14h] [bp-14h]@105
	signed int a4f; // [sp+14h] [bp-14h]@122
	signed int a4g; // [sp+14h] [bp-14h]@130
	signed int a4h; // [sp+14h] [bp-14h]@143
	signed int a4i; // [sp+14h] [bp-14h]@177
	signed int a4j; // [sp+14h] [bp-14h]@185
	signed int a4k; // [sp+14h] [bp-14h]@193
	signed int a3a; // [sp+18h] [bp-10h]@13
	signed int a3b; // [sp+18h] [bp-10h]@53
	signed int a3c; // [sp+18h] [bp-10h]@71
	signed int a3d; // [sp+18h] [bp-10h]@77
	signed int a3e; // [sp+18h] [bp-10h]@107
	signed int a3f; // [sp+18h] [bp-10h]@124
	signed int a3g; // [sp+18h] [bp-10h]@132
	signed int a3h; // [sp+18h] [bp-10h]@138
	signed int a3i; // [sp+18h] [bp-10h]@145
	signed int a3j; // [sp+18h] [bp-10h]@150
	signed int a3k; // [sp+18h] [bp-10h]@155
	signed int a3l; // [sp+18h] [bp-10h]@167
	signed int a3m; // [sp+18h] [bp-10h]@172
	signed int a3n; // [sp+18h] [bp-10h]@179
	signed int a3o; // [sp+18h] [bp-10h]@187
	signed int a3p; // [sp+18h] [bp-10h]@195
	int v36; // [sp+1Ch] [bp-Ch]@111
	int v37; // [sp+20h] [bp-8h]@111
	int v38; // [sp+24h] [bp-4h]@193

	extern int giFrameCount;
	extern int giFrameStep;
	extern int glTimers;
	extern int giLimitUpdMinY;
	extern int giLimitUpdMaxX;
	extern int giLimitUpdMaxY;
	extern int giDeferObjDrawX;
	extern int giDeferObjDrawY;

	//BYTE bComboDraw[bcsize]; //memset(&bComboDraw, 0, 0x100u);


		//static const int bcsize = 4*512; //(16 * 16)
	struct d
		{
		BYTE pre_padding[256];
		BYTE data[4 * 512];
		BYTE post_padding[256];
		d()
			{
			memset(pre_padding, 0xaa, 256);
			memset(post_padding, 0xbb, 256);
			memset(data, 0, 4 * 512);
			}
		BYTE& operator[](const int index)
			{
			if(index < 0)
				{
				//std::cerr << "negative index\n";
				return pre_padding[128 + index];
				}
			//if(index > 256)
			//	std::cerr << "index out of bounds\n";
			
			return data[index];
			}
		} bComboDraw;


	//BYTE* dword_524D2C = (bComboDraw);
	//BYTE* byte_524D31 = (bComboDraw + 1);
	//BYTE* byte_524D3E = (bComboDraw + 14);

	typedef BYTE _BYTE;

	typedef WORD _WORD;
	
	PollSound();
	if(!bShowIt)
		return 0;
	if(this->field_2AE)
		{
		CompleteDraw(view_x, view_y, 0, 1);
		return 1;
		}
	if(a4)
		{
		giFrameCount += giFrameStep;
		if(giFrameCount < 12)
			{
			Process1WindowsMessage();
			if(KBTickCount() > glTimers)
				glTimers = KBTickCount() + 120;
			PollSound();
			return 0;
			}
		giFrameCount = 0;
		}
	this->field_1DE = this->viewX;
	this->field_1E2 = this->viewY;
	//memset(&bComboDraw, 0, 0x100u);
	this->field_2A2 = 0;
	for(a4a = 0; a4a < CELLS_HEIGHT; ++a4a)
		{
		for(a3a = 0; a3a < CELLS_WIDTH; ++a3a)
			{
			if(view_x + a3a >= 0 && view_x + a3a < MAP_WIDTH && view_y + a4a >= 0 && view_y + a4a < MAP_HEIGHT)
				{
				v7 = GetCell(view_x + a3a, view_y + a4a);
				//if(v7->bitfield_1_hasObject_1_isRoad_6_objTileset & 1
				//	|| v7->field__1_hasOverlay_1_hasLateOverlay_6_overlayTileset & 1)
				if(v7->hasObject & 1
					|| v7->hasOverlay & 1)
					++bComboDraw[ 18 * a3a + a4a];
				if((v7->objType & 0x7F) == LOCATION_WINDMILL)
					++bComboDraw[ 18 * a3a + a4a];
				if((v7->objType & 0x7F) == LOCATION_ALCHEMIST_LAB)
					++bComboDraw[ 18 * a3a + a4a];
				if(v7->objType == (TILE_HAS_EVENT | LOCATION_ARMY_CAMP)) // 152)
					{
					++bComboDraw[ 18 * a3a + a4a];
					++bComboDraw[ 9 * (2 * a3a - 2) + a4a];
					if(GetCloudLookup(view_x + a3a, view_y + a4a))
						{
						v5 = a4a;
						bComboDraw[ 9 * (2 * a3a + 2) + a4a] += 10;
						if(a4a >= 1)
							{
							bComboDraw[18 * a3a + a4a  - 1] += 10;
							v5 = a4a;
							bComboDraw[9 * (2 * a3a + 2) + a4a - 1] += 10;
							}
						}
					else
						{
						++bComboDraw[ 9 * (2 * a3a + 2) + a4a];
						if(a4a >= 1)
							{
							++bComboDraw[18 * a3a + a4a - 1];
							++bComboDraw[9 * (2 * a3a + 2) + a4a - 1];
							}
						}
					}
				if(v7->objType == (TILE_HAS_EVENT | LOCATION_HERO)
				   || v7->objType == (TILE_HAS_EVENT | LOCATION_BOAT)) //170, 171
					{
					++bComboDraw[ 18 * a3a + a4a];
					if(GetCloudLookup(view_x + a3a, view_y + a4a))
						{
						bComboDraw[ 9 * (2 * a3a + 2) + a4a] += 10;
						bComboDraw[18 * a3a + a4a + 1] += 10;
						bComboDraw[9 * (2 * a3a + 2) + a4a + 1] += 10;
						v5 = a4a;
						bComboDraw[ 9 * (2 * a3a + 4) + a4a] += 10;
						if(a4a >= 1)
							{
							v5 = 18 * a3a;
							bComboDraw[18 * a3a + a4a - 1] += 10;
							}
						if(a3a >= 1)
							{
							bComboDraw[ 9 * (2 * a3a - 2) + a4a] += 10;
							v5 = a4a;
							bComboDraw[9 * (2 * a3a - 2) + a4a + 1] += 10;
							if(a3a >= 2)
								{
								v5 = a4a;
								bComboDraw[ 9 * (2 * a3a - 4) + a4a] += 10;
								}
							if(a4a >= 1)
								++bComboDraw[9 * (2 * a3a - 4) + a4a - 1];
							}
						}
					else
						{
						++bComboDraw[ 9 * (2 * a3a + 2) + a4a];
						++bComboDraw[18 * a3a + a4a + 1];
						++bComboDraw[9 * (2 * a3a + 2) + a4a + 1];
						++bComboDraw[ 9 * (2 * a3a + 4) + a4a];
						if(a4a >= 1)
							++bComboDraw[18 * a3a + a4a - 1];
						if(a3a >= 1)
							{
							++bComboDraw[ 9 * (2 * a3a - 2) + a4a];
							++bComboDraw[9 * (2 * a3a - 2) + a4a + 1];
							if(a3a >= 2)
								++bComboDraw[ 9 * (2 * a3a - 4) + a4a];
							if(a4a >= 1)
								++bComboDraw[9 * (2 * a3a - 4) + a4a - 1];
							}
						}
					}
				}
			}
		}
	for(a3b = 0; a3b < CELLS_WIDTH; ++a3b)
		{
		for(a4b = 0; a4b < CELLS_HEIGHT; ++a4b)
			{
			if(bComboDraw[ 18 * a3b + a4b])
				{
				if(view_x + a3b >= 0 && view_x + a3b < MAP_WIDTH && view_y + a4b >= 0 && view_y + a4b < MAP_HEIGHT)
					{
					if((signed int)bComboDraw[ 18 * a3b + a4b] < 10
						&& !GetCloudLookup(view_x + a3b, view_y + a4b))
						bComboDraw[ 18 * a3b + a4b] = 0;
					}
				else
					{
					bComboDraw[ 18 * a3b + a4b] = 0;
					}
				}
			}
		}
	if(this->heroMobilized)
		{
		for(a4c = 6; a4c <= 8; ++a4c)
			{
			for(a3c = 5; a3c <= 9; ++a3c)
				++bComboDraw[ 18 * a3c + a4c];
			}
		}
	if(this->field_27A == 6)
		{
		int a = 0;
		a++;
		//++byte_524DA1;
		//++byte_524DB3;
		//++byte_524DC5;
		}
	for(a3d = 0; a3d < CELLS_WIDTH; ++a3d)
		{
		for(a4d = 0; a4d < CELLS_HEIGHT; ++a4d)
			{
			v8 = GetCell(view_x + a3d, view_y + a4d);
			if(v8->objType == (TILE_HAS_EVENT | LOCATION_MINE)) //151)
				{
				//if(gpGame->mines[(unsigned __int8)((unsigned __int8)(v8->field_4_1_1_isShadow_1_13_extraInfo >> 8) >> -5)].guardianType == 59) //ghosts or elementals guarding mines?
				if(false)
					{
					++bComboDraw[ 18 * a3d + a4d];
					++bComboDraw[ 9 * (2 * a3d + 2) + a4d];
					if(a3d < 15)
						++bComboDraw[ 9 * (2 * a3d + 4) + a4d];
					if(a3d > 0)
						++bComboDraw[ 9 * (2 * a3d - 2) + a4d];
					if(a4d > 0)
						{
						++bComboDraw[18 * a3d + a4d - 1];
						++bComboDraw[9 * (2 * a3d + 2) + a4d - 1];
						if(a3d < 15)
							++bComboDraw[9 * (2 * a3d + 4) + a4d - 1];
						if(a3d > 0)
							++bComboDraw[9 * (2 * a3d - 2) + a4d - 1];
						}
					if(a4d > 1)
						{
						++bComboDraw[18 * a3d + a4d - 2];
						++bComboDraw[9 * (2 * a3d + 2) + a4d - 2];
						if(a3d < 15)
							++bComboDraw[9 * (2 * a3d + 4) + a4d - 2];
						if(a3d > 0)
							++bComboDraw[9 * (2 * a3d - 2) + a4d - 2];
						}
					}
				else if(a4d > 0 && bComboDraw[18 * a3d + a4d - 1])
					{
					++bComboDraw[ 18 * a3d + a4d];
					}
				}
			}
		}
	if(this->field_A2 && this->sizeOfSomethingMapRelated)
		{
		for(a4e = 1; a4e < CELLS_HEIGHT - 1; ++a4e)
			{
			for(a3e = 0; a3e < CELLS_WIDTH - 5; ++a3e)
				{
				if(bComboDraw[ 18 * a3e + a4e])
					{
					v37 = view_x + a3e;
					v36 = view_y + a4e;
					if(view_x + a3e >= 0)
						{
						if(MAP_WIDTH - 1 >= v37 && v36 >= 1 && MAP_HEIGHT - 2 >= v36)
							{
							if(*(_WORD *)(2 * v37 + 2 * v36 * MAP_WIDTH + this->sizeOfSomethingMapRelated))
								++bComboDraw[18 * a3e + a4e + 1];
							v5 = *(_WORD *)(2 * v37 + 2 * MAP_WIDTH * (v36 - 1) + this->sizeOfSomethingMapRelated);
							if(*(_WORD *)(2 * v37 + 2 * MAP_WIDTH * (v36 - 1) + this->sizeOfSomethingMapRelated))
								++bComboDraw[18 * a3e + a4e - 1];
							}
						}
					}
				}
			}
		}
	gpMouseManager->couldBeShowMouse = 0;
	for(a4f = 0; a4f < CELLS_HEIGHT; ++a4f)
		{
		for(a3f = 0; a3f < CELLS_WIDTH; ++a3f)
			{
			if(bComboDraw[ 18 * a3f + a4f])
				DrawCell(view_x + a3f, view_y + a4f, a3f, a4f, 1, 0);
			}
		}
	for(a4g = 0; a4g < CELLS_HEIGHT; ++a4g)
		{
		for(a3g = 0; a3g < CELLS_WIDTH; ++a3g)
			{
			if(bComboDraw[ 18 * a3g + a4g])
				DrawCell(view_x + a3g, view_y + a4g, a3g, a4g, -128, 0);
			}
		}
	for(a3h = 0; a3h < CELLS_WIDTH; ++a3h)
		{
		if(bComboDraw[ 18 * a3h])
			DrawCell(view_x + a3h, view_y, a3h, 0, 2, 0);
		}
	for(a4h = 1; a4h < CELLS_HEIGHT; ++a4h)
		{
		PollSound();
		for(a3i = 0; a3i < CELLS_WIDTH; ++a3i)
			{
			if(bComboDraw[18 * a3i + a4h - 1])
				DrawCell(view_x + a3i, view_y + a4h - 1, a3i, a4h - 1, 8, 0);
			}
		for(a3j = 0; a3j < CELLS_WIDTH; ++a3j)
			{
			if(bComboDraw[18 * a3j + a4h - 1])
				DrawCell(view_x + a3j, view_y + a4h - 1, a3j, a4h - 1, 4, 0);
			}
		for(a3k = 0; a3k < CELLS_WIDTH; ++a3k)
			{
			if(view_x + a3k != giDeferObjDrawX || view_y + a4h != giDeferObjDrawY)
				{
				if(view_x + a3k == giDeferObjDrawX && view_y + a4h == giDeferObjDrawY + 1)
					DrawCell(view_x + a3k, view_y + a4h - 1, a3k, a4h - 1, 2, 0);
				if(bComboDraw[ 18 * a3k + a4h])
					DrawCell(view_x + a3k, view_y + a4h, a3k, a4h, 2, 0);
				}
			}
		}
	for(a3l = 0; a3l < CELLS_WIDTH; ++a3l)
		{
		if(bComboDraw[18 * a3l + 14])
			DrawCell(view_x + a3l, view_y + 14, a3l, 14, 8, 0);
		}
	for(a3m = 0; a3m < CELLS_WIDTH; ++a3m)
		{
		if(bComboDraw[18 * a3m + 14])
			DrawCell(view_x + a3m, view_y + 14, a3m, 14, 4, 0);
		}
	for(a4i = 0; a4i < CELLS_HEIGHT; ++a4i)
		{
		for(a3n = 0; a3n < CELLS_WIDTH; ++a3n)
			{
			if(bComboDraw[ 18 * a3n + a4i])
				DrawCell(view_x + a3n, view_y + a4i, a3n, a4i, 64, 0);
			}
		}
	for(a4j = 0; a4j < CELLS_HEIGHT; ++a4j)
		{
		for(a3o = 0; a3o < CELLS_WIDTH; ++a3o)
			{
			if(bComboDraw[ 18 * a3o + a4j])
				DrawCell(view_x + a3o, view_y + a4j, a3o, a4j, 32, 0);
			}
		}

	//DrawAdventureBorder(v5);
	DrawAdventureBorder();
	gpMouseManager->couldBeShowMouse = 1;
	PollSound();
	UpdBottomView(0, 1, 1);
	giLimitUpdMinX = 15+15;// 15;
	giLimitUpdMinY = 15;
	giLimitUpdMaxX = 0;
	giLimitUpdMaxY = 0;
	v38 = 0;
	for(a4k = 0; a4k < CELLS_HEIGHT; ++a4k)
		{
		for(a3p = 0; a3p < CELLS_WIDTH; ++a3p)
			{
			if(bComboDraw[ 18 * a3p + a4k])
				{
				++v38;
				if(giLimitUpdMinX > a3p)
					giLimitUpdMinX = a3p;
				if(a3p > giLimitUpdMaxX)
					giLimitUpdMaxX = a3p;
				if(giLimitUpdMinY > a4k)
					giLimitUpdMinY = a4k;
				if(giLimitUpdMaxY < a4k)
					giLimitUpdMaxY = a4k;
				}
			}
		}
	giLimitUpdMinX *= 32;
	giLimitUpdMinY *= 32;
	giLimitUpdMaxX = 32 * (giLimitUpdMaxX + 1) - 1;
	giLimitUpdMaxY = 32 * (giLimitUpdMaxY + 1) - 1;
	if(giLimitUpdMinX < 16)
		giLimitUpdMinX = 16;
	
	int max_x = 463 + 160;
	if(giLimitUpdMaxX > max_x)
		giLimitUpdMaxX = max_x;
	if(giLimitUpdMinY < 16)
		giLimitUpdMinY = 16;
	if(giLimitUpdMaxY > max_x)
		giLimitUpdMaxY = max_x;
	if(giLimitUpdMinX <= giLimitUpdMaxX && giLimitUpdMaxY >= giLimitUpdMinY)
		{
		result = 1;
		}
	else
		{
		giLimitUpdMinX = giLimitUpdMaxX - 1;
		giLimitUpdMinY = giLimitUpdMaxY - 1;
		result = 0;
		}
	return result;
	}


void advManager::SaveAdventureBorder()
	{
	//void *result; // eax@1
	//char* v2; // [sp+Ch] [bp-10h]@1
	signed int i; // [sp+10h] [bp-Ch]@2
	signed int j; // [sp+10h] [bp-Ch]@5
	signed int k; // [sp+10h] [bp-Ch]@8
	char* v6; // [sp+14h] [bp-8h]@2
	signed __int8 *v7; // [sp+18h] [bp-4h]@2

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;

	//v2 = this;
	//result = (void *)this; 

	//return SaveAdventureBorder_orig();
	
	__int8* unknown = (__int8*)field_BA;  //could be related to evil/good interface
	if(!unknown)
	//if(!*(_DWORD *)(this + 186))
		{
		//*(_DWORD *)(this + 186) = 
		extern short word_50FAE8;
		unknown = new char[0x7400u + 0x4200u]; //fixme
		field_BA = (int)unknown;
		//unknown = (char*)BaseAlloc(0x7400u + 0x4200, "F:\\h2xsrc\\Source\\ADVMGR.CPP", 8270 + 4);
		//v6 = *(_DWORD *)(v2 + 186);
		v6 = unknown;
		//result = gpWindowManager->screenBuffer->contents;
		v7 = gpWindowManager->screenBuffer->contents;
		//return;
		for(i = 0; i < 16; ++i) //top
			{
			memcpy(v6, v7, 0x1E0u + 160);
			v7 += SCREEN_WIDTH;
			v6 += 480 + 160;
			}
		for(j = 16; j < 464; ++j) //left + right
			{
			memcpy(v6, v7, 0x10u); //left
			memcpy(v6 + 16, v7 + 464 + 160, 0x10u); //right
			v7 += SCREEN_WIDTH;
			v6 += 32;
			}
		for(k = 464; k < 480; ++k) //bottom
			{
			memcpy(v6, v7, 0x1E0u + 160);
			v7 += SCREEN_WIDTH;
			v6 += 480 + 160;
			}
		}
	//return result;
	}


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
		sprintf(content, "%s: %d  %s: %d  %s: %d",
				"Month", gpGame->month, "Week", gpGame->week, "Day", gpGame->day);
		day_display_widget = new textWidget(
				160 + 479,
				//424,
				2,
				160,
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
			memcpy(v7, (const void *)v6, 0x1E0u + 160);
			v7 += SCREEN_WIDTH;
			v6 += 480 + 160;
			}
		for(j = 16; j < 464; ++j)
			{
			memcpy(v7, (const void *)v6, 0x10u); //left side
			result = memcpy(v7 + 464 + 160, v6 + 16, 0x10u); //right side
			v7 += SCREEN_WIDTH;
			v6 += 32;
			}
		//return;
		for(k = 464; k < 480; ++k) //bottom
			{
			//result = 
			memcpy(v7, (const void *)v6, 0x1E0u + 160);
			v7 += SCREEN_WIDTH;
			v6 += 480 + 160;
			}
		}
	//return result;
	return;
	}

void advManager::SetEnvironmentOrigin(int x, int y, int a3)
	{
	return;
	if(x == viewX + 7)
		x += 3;

	SetEnvironmentOrigin_orig(x, y, a3);
	}


void advManager::RedrawAdvScreen(int a2, int a3)
	{
	extern int gbUseEvilInterface;
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;
	if(bShowIt)
		{
		//int old_width =	gpWindowManager->screenBuffer->width;
		//gpWindowManager->screenBuffer->width = 640;
		
		//if(widescreen)
		//char evilbit = gpGame->players[giCurPlayer]._4_1; //this is set in newmap()
		FACTION faction = (FACTION)gpGame->castles[gpGame->players[giCurPlayer].castlesOwned[0]].factionID;
		////if(gbUseEvilInterface)
		//warning: below is a hack //todo fixme
		if(faction == FACTION_KNIGHT || faction == FACTION_SORCERESS) //good
			gpResourceManager->GetBackdrop("advbordw.icn", gpWindowManager->screenBuffer, 1);
		else if(faction == FACTION_BARBARIAN || faction == FACTION_WIZARD || faction == FACTION_MULTIPLE) //neutral
			gpResourceManager->GetBackdrop("advbordwn.icn", gpWindowManager->screenBuffer, 1);
		else if(faction == FACTION_WARLOCK || faction == FACTION_NECROMANCER) //evil
			gpResourceManager->GetBackdrop("advbordwe.icn", gpWindowManager->screenBuffer, 1);
		//gpWindowManager->screenBuffer->width = old_width;
		
		if(a3)
			{
			//BaseFree((void *)this->field_BA, (int)"F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F7C0 + 9);
			this->field_BA = 0;
			}
		SaveAdventureBorder();
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
			std::cout << "widget(" << w->offsetX << ", " << w->offsetY << ")\n";
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
		return BlitBitmapToScreenVesa_orig(bmp, x, y, width + 160, height, screenX, screenY);
		

	static int original_width = 640;
	original_width = 800;
	gpWindowManager->screenBuffer->width = original_width;
	
	if(width >= 448 && width <= 480)
		width += 160;

	if(width == 640)
		width = original_width;
	if(width == 640 - 1)
		width = original_width - 1;

	static int SCREEN_WIDTH = 800;
	static int SCREEN_HEIGHT = 480;
	//if(screenX >= 480)
	//	screenX += 160;

	if(!bmp)
		return;

	v7 = 0;
	if(gpWindowManager->screenBuffer == bmp || (v7 = 0, height <= 0))
		{
		v8 = width;
		////v8 = width;
		//v9 = original_width * screenY;
		//do
		//	{
		//	v10 = v7++ + y;
		//	memcpy(&gpWindowManager->screenBuffer->contents[screenX] + v9, &bmp->contents[bmp->width * v10] + x, width);
		//	v9 += original_width;
		//	} while(v7 < height);
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
	
	//v8 = 800;
	//height = 480;
	static int extral = 0;
	static int extrat = 0;
	static int extrar = 0;
	static int extrab = 0;
	Rect.left = screenX * iMainWinScreenWidth / SCREEN_WIDTH + extral;
	Rect.top = iMainWinScreenHeight * screenY / SCREEN_HEIGHT + extrat;
	Rect.right = iMainWinScreenWidth * (v8 + screenX) / SCREEN_WIDTH - 1 + extrar;
	Rect.bottom = iMainWinScreenHeight * (height + screenY) / SCREEN_HEIGHT - 1 + extrab;

	std::cout << "InvalidateRect:\t[" 
		<< Rect.left << ", " << Rect.top << ", " << Rect.bottom << ", " << Rect.right 
		<< "]\n";

	if(!InvalidateRect((HWND)hwndApp, &Rect, 0))
		LogStr("InvalidateRect Failed");
	if(!UpdateWindow((HWND)hwndApp))
		LogStr("UpdateWindow Failed");

	}


void __fastcall BlitBitmapToScreen(bitmap *bmp, int xOff, int yOff, int width, int height, int screenX, int screenY)
	{
	unsigned int v7; // ebp@5
	int v8; // ebx@5
	int v9; // ecx@12
	int x; // [sp+10h] [bp-8h]@1
	bitmap *bmpa; // [sp+14h] [bp-4h]@1

	extern BOOL gbColorMice;
	extern int giScrollX;
	extern int giScrollY;

	//int xOff 

	x = xOff;
	bmpa = bmp;
	if(gbColorMice)
		{
		if(giScrollX || giScrollY)
			{
			v7 = 448 + 160;
			v8 = giScrollY + 16;
			x = giScrollX + 16;
			height = 448;
			}
		else
			{
			v8 = yOff;
			v7 = width;
			}
		int dword_532E78 = v7 + screenX - 1;
		int dword_532E70 = screenY + height - 1;
		if(gpMouseManager->IsVis()
		   && gpMouseManager->cursorTopLeftX <= dword_532E78 + 160
		   && gpMouseManager->field_6E >= screenX
		   && gpMouseManager->cursorTopLeftY <= dword_532E70 + 160
		   && gpMouseManager->field_72 >= screenY)
			{
			gpMouseManager->SaveAndDraw();
			BlitBitmapToScreenVesa(bmpa, x, v8, v7, height, screenX, screenY);
			v9 = gpMouseManager->field_6E;
			if(v9 > dword_532E78
			   || gpMouseManager->cursorTopLeftX < screenX
			   || gpMouseManager->field_72 > dword_532E70
			   || gpMouseManager->cursorTopLeftY < screenY)
				BlitBitmapToScreenVesa(
					bmpa,
					gpMouseManager->cursorTopLeftX,
					gpMouseManager->cursorTopLeftY,
					v9 - gpMouseManager->cursorTopLeftX + 1,
					gpMouseManager->field_72 - gpMouseManager->cursorTopLeftY + 1,
					gpMouseManager->cursorTopLeftX,
					gpMouseManager->cursorTopLeftY);
			gpMouseManager->RestoreUnderlying();
			}
		else
			{
			if(x != 481)
				BlitBitmapToScreenVesa(bmpa, x, v8, v7 + 160, height, screenX, screenY);
			//Sleep(750);
			std::cout << "BlitBitmapToScreenVesa(" << bmpa << ", " << x << ", " << v8 << ", " << v7 << ", " << height << ", " << screenX << ", " << screenY << ")\n";
			}
		}
	else
		{
		BlitBitmapToScreenVesa(bmp, xOff, yOff, width, height, screenX, screenY);
		}
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
  /*  for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            this->sharePlayerVision[i][j] = 0;
        }
    }*/
}