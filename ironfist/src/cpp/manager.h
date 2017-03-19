#ifndef TIED_MANAGER_H
#define TIED_MANAGER_H

#include "msg.h"

#pragma pack(push,1)

class baseManager
{
public:
  baseManager *next;
  baseManager *prev;
  int type;
  int idx;
  char name[30];
  int ready;

  baseManager();

  virtual int Open(int);
  virtual void Close();
  virtual int Main(tag_message&);
};

enum MOUSE_CURSOR_CATEGORY
	{
	MOUSE_CURSOR_CATEGORY_ADVENTURE = 0x0,
	MOUSE_CURSOR_CATEGORY_COMBAT = 0x1,
	MOUSE_CURSOR_CATEGORY_SPELL = 0x2,
	};

class bitmap;
class icon;

#pragma pack(push, 1)
class mouseManager : public baseManager
	{
	public:
		bitmap *bitmap;
		int spriteIdx;
		icon *cursorIcon;
		MOUSE_CURSOR_CATEGORY cursorCategory;
		int cursorIdx;
		int field_4A;
		int field_4E;
		int field_52;
		int field_56;
		int field_5A;
		int cursorTopLeftX;
		int cursorTopLeftY;
		int field_66;
		int field_6A;
		int field_6E;
		int field_72;
		int cursorWidth;
		int cursorHeight;
		int field_7E;
		int couldBeShowMouse;
		int cursorDisabled;

		mouseManager();

		int IsVis();

		void MouseCoords(int &, int &);
		void MouseCoords_orig(int &, int &);

		void NewUpdate(int);
		void NewUpdate_orig(int);

		void ShowColorPointer();
		void SetPointer(int);
		void SetPointer(char *, int, int);
		void SetColorMice(int);

		void RestoreUnderlying();
		void SaveAndDraw();
	};
#pragma pack(pop)

extern mouseManager* gpMouseManager;

#pragma pack(push, 1)
class inputManager : public baseManager
	{
	public:
		tag_message inputInstances[64];
		int currentInputEvt;
		int currentInfoField;
		int readingInputMutex;
		int field_742;
		int field_746;
		int field_74A;
		__int16 keycodeRelated[128];
		int field_84E;
		int field_852;
		int normalizingKeycodeRelated;
		int field_85A;
		int forSettingBitmask;
		int field_862;
		int field_866;

		inputManager();

		struct tag_message GetEvent(void);
		void ForceMouseMove();
	};
#pragma pack(pop)

extern inputManager* gpInputManager;

enum MANAGER_TYPE
{
  MANAGER_TYPE_HERO_WINDOW_MANAGER = 0x20,
  MANAGER_TYPE_RESOURCE_MAMANGER = 0x80,
  MANAGER_TYPE_SWAP_MANAGER = 0x100,
  MANAGER_TYPE_COMBAT_MANAGER = 0x200,
};

enum MANAGER_RETURN_CODE
{
  MANAGER_SUCCESS = 0,
  MANAGER_FINISHED = 2,
  MANAGER_FAILED = 3,
};

#pragma pack(pop)

#endif