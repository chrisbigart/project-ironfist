#include "dialog.h"
#include "gui/gui.h"
#include "base.h"


//int heroWindowManager::DoDialog(heroWindow *window, int(__fastcall *a3)(tag_message &), int a4)
//	{
//	heroWindowManager *v5; // esi@6
//	int v6; // edi@8
//	signed int v7; // ebp@9
//	int evt; // [sp+10h] [bp-38h]@10
//	int v10; // [sp+14h] [bp-34h]@15
//	int v11; // [sp+18h] [bp-30h]@16
//	tag_message a2; // [sp+2Ch] [bp-1Ch]@10
//
//	gbInDialog = 1;
//	if(!iDialogNestCount)
//		SetNoDialogMenus(0);
//	++iDialogNestCount;
//	this->hoveredFieldID = -1;
//	if(window)
//		AddWindow(window, -1, 1);
//	if(a4)
//		{
//		v5 = gpWindowManager;
//		if(gPalette)
//			SetPalette(gPalette->contents, 0);
//		v6 = v5->cycleColors;
//		v5->cycleColors = 0;
//		PollSound();
//		FadeIn(8);
//		v5->cycleColors = v6 | dword_532E54;
//		PollSound();
//		}
//	v7 = 0;
//	gpInputManager->Flush();
//	this->buttonPressedCode = -1;
//	do
//		{
//		PollSound();
//		Process1WindowsMessage();
//		auto evt = gpInputManager->GetEvent();
//		memcpy(&evt, &evt, (inputManager *)&a2), 0x1Cu);
//		(*(void(__stdcall **)(int *))(LODWORD(gpMouseManager->vtable) + 8))(&evt);
//		if(window
//		   && (evt != 4 || gbSendMouseMoveMessages)
//		   && heroWindow::BroadcastMessage(window, (tag_message *)&evt) == 2
//		   && evt == 512
//		   && v10 == 10)
//			{
//			v7 = 1;
//			this->buttonPressedCode = v11;
//			}
//		if(((int(__thiscall *)(int *))a3)(&evt) == 2 && evt == 512 && v10 == 10)
//			v7 = 1;
//		} while(!v7);
//		if(window)
//			heroWindowManager::RemoveWindow(this, window);
//		inputManager::Flush(gpInputManager);
//		gbInDialog = 0;
//		--iDialogNestCount;
//		if(!iDialogNestCount)
//			SetNoDialogMenus(1);
//		return 0;
//	}





void H2MessageBox(char* msg) {
	NormalDialog(msg, DIALOG_OKAY, -1,-1,-1,0,-1,0,-1,0);
}