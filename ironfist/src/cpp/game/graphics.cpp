#include "base.h"
#include "game/game.h"

void __fastcall InitGraphics_orig();
void __fastcall InitGraphics()
	{
	InitGraphics_orig();
	}

extern void* hpalApp;
//extern HPALETTE hpalApp;
extern void* hdcImage;
extern void* gbmOldMonoBitmap;

extern "C" int __stdcall thunk_WinGRecommendDIBFormat(BITMAPINFO*);
extern "C" int __stdcall thunk_WinGCreateDC(void);
extern "C" HBITMAP __stdcall thunk_WinGCreateBitmap(HDC, BITMAPINFO*, void**);

extern void __fastcall InitializePalette();

extern DWORD dword_530418;

extern struct _IMAGE screenImage;

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
	//		DWORD      biSize;
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
			screen_image.bmiHeader.biPlanes = 1;			//word_52FFFC = 1;
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

		//void* pbuffer = (&screenImage + 266); //not sure exactly what this does
		v0 = thunk_WinGCreateBitmap((HDC)hdcImage, &screen_image, 
									(void**)(((DWORD*)&screenImage) + 266)
									//&pbuffer
									);
		screen_image.bmiHeader.biSizeImage = Orientation * 
									screen_image.bmiHeader.biHeight * screen_image.bmiHeader.biWidth;
		//sizeof(BITMAPINFO);
		gbmOldMonoBitmap = (void*)SelectObject((HDC)hdcImage, (HGDIOBJ)v0);
		//lpInitWin = (bitmap *)dword_530418;
		lpInitWin = (void*)*(((DWORD*)&screenImage) + 266);
		//lpInitWin = pbuffer;
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
	IconToBitmap_orig(icn, bmp, x, y, spriteIdx, a6, a7, a8, width, height, a11);
	return;
	}