#include "msg.h"
#include "gui/gui.h"

#include <iostream>

void GUIAddFlag(heroWindow* hwnd, int f, int p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_ADD_FLAGS, (void*)p);
}

void GUIRemoveFlag(heroWindow* hwnd, int f, int p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_REMOVE_FLAGS, (void*)p);
}

void GUISetImgIdx(heroWindow* hwnd, int f, int p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_SET_IMG_IDX, (void*)p);
}

void GUISetIcon(heroWindow* hwnd, int f, char* p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_SET_ICON, (void*)p);
}

void GUISetText(heroWindow* hwnd, int f, char* p) {
	GUIBroadcastMessage(hwnd, f, GUI_MESSAGE_SET_TEXT, (void*)p);
}


void GUIBroadcastMessage(heroWindow* hwnd, int f, int c, void* p) {
	tag_message evt;
	evt.yCoordOrFieldID = f;
	evt.eventCode = INPUT_GUI_MESSAGE_CODE;
	evt.xCoordOrKeycode = c;
	evt.payload = p;
	hwnd->BroadcastMessage(evt);
}

tag_message inputManager::GetEvent()
	{
	tag_message r = GetEvent_orig();
	if(r.eventCode || r.xCoordOrKeycode)
		std::cout << "eventCode: " << r.eventCode << "\txCoordOrKeycode: " << r.xCoordOrKeycode << "\n";
	return r;
	}

void inputManager::AsciiConvert(tag_message& evt)
	{
	AsciiConvert_orig(evt);
	return;
	}

int heroWindow::BroadcastMessage(tag_message& evt)
	{
	//return BroadcastMessage_orig(evt);
	widget *guiComp; // [sp+14h] [bp-8h]@1
	int v4; // [sp+18h] [bp-4h]@1

	v4 = 0;
	for(guiComp = this->firstWidget; guiComp; guiComp = guiComp->nextInLinkedList)
		{
		v4 = guiComp->main(evt);
		if(v4 && v4 >= 1 && v4 <= 2)
			return v4;
		}
	return v4;
	}