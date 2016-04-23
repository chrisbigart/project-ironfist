#ifndef GUI_H
#define GUI_H

#include "manager.h"
#include "resource/resources.h"

#pragma pack(push,1)

class heroWindow;

class widget {
public:
  heroWindow *parentWindow;
  widget *nextInLinkedList;
  widget *prevInLinkedList;
  __int16 fieldID;
  __int16 componentIndex;
  __int16 field_14;
  __int16 flags;
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;

  //widget(widget *this, __int16 a2, __int16 a3, __int16 a4, __int16 a5, __int16 fieldID, __int16 a7)
  //widget(short, short, short, short, short, short);

  virtual void Draw();
  virtual ~widget();
  virtual int main(tag_message&);
};

class textWidget : public widget {
  char *content;
  font *font;
  __int16 field_28;
  char field_2A;
public:
  //textWidget(__int16 offsetX, __int16 offsetY, __int16 width, __int16 height, char *content, const char *fontName, __int16 a8, __int16 fieldID, __int16 a7, char a11);
	textWidget(short, short, short, short, char *, char *, short, short, short, short);
};

class iconWidget : public widget
	{
	icon *icon;
	__int16 imgIdx;
	char mirror;
	__int16 field_27;
	int iconFileID;
	public:
		iconWidget(short, short, short, short, char *, short, signed char, short, short, short);
	
	};

class heroWindow {
public:
  int idx;
  heroWindow *nextWindow;
  heroWindow *prevWindow;
  char filename[20];
  int flags1;
  int flags2;
  int xOffset;
  int yOffset;
  int width;
  int height;
  widget *lastWidget;
  widget *firstWidget;
  bitmap *bitmap;

  heroWindow(int, int, char*);
  
  void DrawWindow(int);
  void DrawWindow(int updateScreen, int lowID, int highID);
  int BroadcastMessage(tag_message&);
  void AddWidget_orig(widget *guiObj, int index);
  void AddWidget(widget *guiObj, int index);
};

class heroWindowManager : public baseManager
{
public:
  heroWindow *firstWindow;
  heroWindow *lastWindow;
  heroWindow *topmostWindow;
  heroWindow *nextTopmostWindow;
  bitmap *screenBuffer;
  bitmap *fizzleSource;
  bitmap *field_4E;
  int numScreenshots;
  int cycleColors;
  int buttonPressedCode;
  int hoveredFieldID;

  heroWindowManager();

  void UpdateScreenRegion(int, int, int, int);
  void FizzleForward(int, int, int, int, int, signed char *, signed char *);

  int DoDialog(heroWindow *,int (__fastcall*)(tag_message &),int);
  int Open(int);
  int Open_orig(int);
};

extern heroWindowManager* gpWindowManager;

enum ICON_GUI_FLAGS
{
  ICON_GUI_VISIBLE = 0x4,
};

/* These functions provide a simpler API to parts of the old GUI "BroadcastMessage" API */

void GUIAddFlag(heroWindow*, int, int);
void GUIRemoveFlag(heroWindow*, int, int);
void GUISetImgIdx(heroWindow*, int, int);
void GUISetIcon(heroWindow*, int, char*);
void GUISetText(heroWindow*, int, char*);

void GUIBroadcastMessage(heroWindow*, int,int,void*);

#pragma pack(pop)

#endif