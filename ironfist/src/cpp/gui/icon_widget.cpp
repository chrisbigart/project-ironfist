//iconWidget(__int16 x, __int16 y, __int16 width, __int16 height, const char *filename, __int16 imgIdx, char mirror, __int16 fieldID, __int16 a10, __int16 a11);
#include "base.h"
#include "game/game.h"
#include "manager.h"

#include "gui/gui.h"



void heroWindow::AddWidget(widget *guiObj, int index)
	{
	for(int i = 0; i < 12; ++i)
		{
		if(guiObj == gpAdvManager->someComponents[0][i] ||
		   guiObj == gpAdvManager->someComponents[1][i])
			{
			guiObj->offsetX += 160;
			}
		}
	AddWidget_orig(guiObj, index);
	if(guiObj->width == 448)
		guiObj->width += 160;
	}

//
//
//iconWidget::iconWidget(short x, short y, short width, short height, char* filename, short imgIdx, signed char mirror, short fieldID, short a10, short a11) //: widget(0, 0, 0, 0, 0, 0)
//	{
//	//iconWidget *thisa; // edi@1
//	//int v12; // eax@1
//	//iconWidget *result; // eax@1
//
//	//thisa = this;
//	//widget::widget((widget *)this, x, y, width, height, fieldID, a10);
//	//thisa->vtable = &iconWidget::_vftable_;
//	//v12 = resourceManager::MakeId(gpResourceManager, filename, 1);
//	//thisa->iconFileID = v12;
//	//thisa->icon = resourceManager::GetIcon(gpResourceManager, v12);
//	//thisa->imgIdx = imgIdx;
//	//thisa->mirror = mirror;
//	//thisa->field_27 = a11;
//	//result = thisa;
//	//thisa->field_14 = a10;
//	//return result;
//	}


