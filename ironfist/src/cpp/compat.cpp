/*
* The Heroes II binary contains an old C++ runtime. When Ironfist
* is compiled, it adds a new C++ runtime. This file fixes compatibility
* problems.
*
* See also comments in revitalize_exports.inc
*/

#ifndef COMPAT_H
#define COMPAT_H

#include <Windows.h>

#include "driver.h"

/*
* Both runtimes have their own heap. We force the reassembled
* Heroes II code to put C++ objects on the new runtime's heap.
*/

extern "C" void* __cdecl op_new(unsigned int x) {
	return operator new(x);
}

extern "C" void __cdecl op_del(void* x) {
	operator delete(x);
}

/*
* We ensure that the startup routines of both
* runtimes get called.
*/

extern "C" {
	void _start_asm();
}

int main(int argc, char** argv)
	{
	IronfistInit();
	_start_asm();
	return 0;
	}

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	IronfistInit();
	_start_asm();
	return 0;
}

extern void* hInstApp;
extern void* gEventHandle;
extern char gcCommandLine[];

extern int __fastcall EarlySetup(void);
extern int __fastcall AppInit(void *, void *, int, char *);
extern int __fastcall AppIdle(void);
extern void __fastcall ShutDown(char*);


extern "C"
int WINAPI WinMain_asm(HINSTANCE instance, HINSTANCE prevInstance, LPSTR lpCmdnLine, int nCmdShow)
	{
	hInstApp = instance;
	gEventHandle = CreateEventA(0, 0, 0, "Heroes II");
	auto error = GetLastError();
	if(!gEventHandle)
		return 0;
	
	// && error != ERROR_CLIENT_ALREADY_EXISTS)
		
	memset(gcCommandLine, 0, 0x3Du);
	strncpy(gcCommandLine, lpCmdnLine, 0x3Cu);
	if(!EarlySetup())
		return 0;

		
	if(!AppInit(instance, prevInstance, nCmdShow, lpCmdnLine))
		return 0;
	
	struct tagMSG Msg; // [sp+Ch] [bp-20h]@8

	while(1)
		{
		while(!PeekMessageA(&Msg, 0, 0, 0, 1u))
			{
			if(AppIdle())
				WaitMessage();
			}
		if(Msg.message == 18)
			break;
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
		}

	ShutDown(0);

	return Msg.wParam;
	}


#endif
