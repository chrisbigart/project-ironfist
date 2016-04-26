#include "base.h"
#include "game/game.h"

void __fastcall InitGraphics_orig();
void __fastcall InitGraphics()
	{
	InitGraphics_orig();
	}


extern DWORD dword_530418;

void __fastcall WGInitGraphics_orig();
void __fastcall WGInitGraphics()
	{
	HBITMAP v0; // ST24_4@5
	//typedef struct tagBITMAPINFO
	//	{
	//	//BITMAPINFOHEADER    bmiHeader;
	//	typedef struct tagBITMAPINFOHEADER
	//		{
	//		DWORD      biSize;
	//		LONG       biWidth;
	//		LONG       biHeight;
	//		WORD       biPlanes;
	//		WORD       biBitCount;
	//		DWORD      biCompression;
	//		DWORD      biSizeImage;
	//		LONG       biXPelsPerMeter;
	//		LONG       biYPelsPerMeter;
	//		DWORD      biClrUsed;
	//		DWORD      biClrImportant;
	//		} BITMAPINFOHEADER;
	//	//RGBQUAD             bmiColors[1];
	//	typedef struct tagRGBQUAD
	//		{
	//		BYTE    rgbBlue;
	//		BYTE    rgbGreen;
	//		BYTE    rgbRed;
	//		BYTE    rgbReserved;
	//		} RGBQUAD;  //same (size) structure as PALETTEENTRY
	//	};


	//return WGInitGraphics_orig();

	BITMAPINFO& screen_image = *(BITMAPINFO*)&screenImage; //?screenImage@@3U_IMAGE@@A dd ? ; DATA XREF: WGInitGraphics(void):loc_49C59Bo

	
	//DWORD dword_52FFF4;
	//DWORD dword_52FFF8 = 0;
	//short word_52FFFE;
	//short word_52FFFC;
	//int dword_530000;
	//int dword_530004;
	//int dword_530010;
	//int dword_530014;
	int Orientation = 1;
							
	//	typedef struct tagBITMAPINFOHEADER
	//		{
	//		DWORD      biSize;			=>    0x52FFF0
	//		LONG       biWidth;			=>dword_52FFF4
	//		LONG       biHeight;		=>dword_52FFF8
	//		WORD       biPlanes;		=>word_52FFFC
	//		WORD       biBitCount;		=>word_52FFFE
	//		DWORD      biCompression;	=>dword_530000
	//		DWORD      biSizeImage;		=>dword_530004
	//		LONG       biXPelsPerMeter;	=>
	//		LONG       biYPelsPerMeter;	=>
	//		DWORD      biClrUsed;		=>dword_530010
	//		DWORD      biClrImportant;	=>dword_530014
	//		} BITMAPINFOHEADER;
	

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 480;

	HDC hDC; // [sp+Ch] [bp-4h]@1

	hDC = GetDC(0);
	if(hDC)
		{
		int giMainVideoModeColorDepth = GetDeviceCaps(hDC, BITSPIXEL);
		int giMainVideoModeWidth = GetDeviceCaps(hDC, HORZRES);
		int giMainVideoModeHeight = GetDeviceCaps(hDC, VERTRES);
		ReleaseDC(0, hDC);
		if(giMainVideoModeColorDepth < 8)
			ShutDown("Heroes II requires 256 color mode or higher.\n\nTo change color mode, right click in an open area on the Windows 95 background, choose 'Properties', then the 'Settings' tab, then change the entry in the 'Color Palette Box'.");
		}

	if(!hdcImage)
		{
		if(thunk_WinGRecommendDIBFormat(&screen_image))
			{
			screen_image.bmiHeader.biBitCount = 8;		//word_52FFFE = 8;
			screen_image.bmiHeader.biCompression = 0;	//dword_530000 = 0;
			Orientation = screen_image.bmiHeader.biHeight;
			}
		else
			{
			screen_image.bmiHeader.biSize = 40;			//screen_image = 40;
			screen_image.bmiHeader.biPlanes = 1;		//word_52FFFC = 1;
			screen_image.bmiHeader.biBitCount = 8;		//word_52FFFE = 8;
			screen_image.bmiHeader.biCompression = 0;	//dword_530000 = 0;
			screen_image.bmiHeader.biSizeImage = 0;		//dword_530004 = 0;
			screen_image.bmiHeader.biClrUsed = 0;		//dword_530010 = 0;
			screen_image.bmiHeader.biClrImportant = 0;	//dword_530014 = 0;
			}
		screen_image.bmiHeader.biWidth = SCREEN_WIDTH;	//dword_52FFF4 = 640;
		screen_image.bmiHeader.biHeight = -SCREEN_HEIGHT; //dword_52FFF8 = -480;
		
		InitializePalette();
		hdcImage = (HDC)thunk_WinGCreateDC();
		
		//don't know why this is duplicated
		screen_image.bmiHeader.biWidth = SCREEN_WIDTH;	//dword_52FFF4 = 640;
		screen_image.bmiHeader.biHeight = -SCREEN_HEIGHT; //dword_52FFF8 = -480;

		int simgsz = sizeof(BITMAPINFOHEADER);
		void* pbuffer = nullptr;

		/*	HBITMAP WINAPI WinGCreateBitmap(HDC hdc, BITMAPINFO *bmi, void **bits)
			{
			    return CreateDIBSection(hdc, bmi, DIB_RGB_COLORS, bits, 0, 0);
			}*/

		v0 = thunk_WinGCreateBitmap((HDC)hdcImage, &screen_image, 
									//(void**)(((DWORD*)&screenImage) + 266)
									&pbuffer
									);

		//screen_image.bmiHeader.biBitCount = 8;
		screen_image.bmiHeader.biSizeImage = Orientation * 
									screen_image.bmiHeader.biHeight * screen_image.bmiHeader.biWidth;
		//sizeof(BITMAPINFO);
		gbmOldMonoBitmap = (void*)SelectObject((HDC)hdcImage, (HGDIOBJ)v0);
		//lpInitWin = (bitmap *)dword_530418;
		//lpInitWin = (void*)*(((DWORD*)&screenImage) + 266);
		*(void**)(((DWORD*)&screenImage) + 266) = pbuffer;  //window will remain white/blank if this is omitted
		lpInitWin = pbuffer;

		PatBlt((HDC)hdcImage, 0, 0, iMainWinScreenWidth, iMainWinScreenHeight, 0x42u); 
		}

	}

void __fastcall DDInitGraphics_orig();
void __fastcall DDInitGraphics()
	{
	DDInitGraphics_orig();
	}

int __fastcall SetGraphicsType_orig(int);
int __fastcall SetGraphicsType(int ptr)
	{
	return SetGraphicsType_orig(ptr);
	}

void __fastcall IconToBitmap_orig(class icon *, class bitmap *, int, int, int, int, int, int, int, int, int);
void __fastcall IconToBitmap(class icon * icn, class bitmap * bmp,
							 int x, int y, int spriteIdx, int a6, int a7, int a8,
							 int width, int height,
							 int a11)
	{
	if(width == 640)
		width += 160;
	if(width == 480)
		width += 160;
	IconToBitmap_orig(icn, bmp, x, y, spriteIdx, a6, a7, a8, width, height, a11);
	return;
	}