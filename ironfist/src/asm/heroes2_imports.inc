;;; Compatibility. See comments in compat.cpp

IMPORT__exit = 1

;; Avoiding name conflicts
IMPORT__stricmp = 1
IMPORT__strnicmp = 1

___xi_a EQU ___xi_a_asm
___xc_a EQU ___xc_a_asm
___xc_z EQU ___xc_z_asm
___xt_a EQU ___xt_a_asm
___xp_a EQU ___xp_a_asm

;; Requiring assembly to use new runtime's file operations
IMPORT__open = 1
IMPORT__close = 1
IMPORT__tell = 1
IMPORT___read = 1
IMPORT___write = 1
IMPORT___lseek = 1

;; Statically linking runtime

__CIexp EQU __CIexp_asm
__CIatan2 EQU __CIatan2_asm
__indefinite EQU __indefinite_asm
__infinity EQU __infinity_asm
__OP_EXPjmptab EQU __OP_asm
__CIacos EQU __CIacos_asm
___argc EQU ___argc_asm
___argv EQU ___argv_asm
__acmdln EQU __acmbdln_asm
__pgmptr EQU __pgmptr_asm
__CIatan EQU __CIatan_asm
__pctype EQU __pctype_asm
___badioinfo EQU ___badioinfo_asm
___pioinfo EQU ___pioinfo_asm
__nhandle EQU __nhandle_asm
__CIlog EQU __CIlog_asm
__CIlog10 EQU __CIlog10_asm
___mbcodepage EQU ___mbcodepage_asm
___mbulinfo EQU ___mbulinfo_asm
__mbctype EQU __mbctype_asm
__commode EQU __commode_asm
__CIpow EQU __CIpow_asm
__sys_nerr EQU __sys_asm
_tolower EQU _tolower_asm
_toupper EQU _toupper_asm
___mb_cur_max EQU ___mb_cur_max_asm
__d_inf EQU __d_inf_asm
__d_ind EQU __d_ind_asm
__d_max EQU __d_max_asm
__d_mzero EQU __d_asm
__nstream EQU __nstream_asm
___piob EQU ___piob_asm
__cflush EQU __cflush_asm
__iob EQU __iob_asm
___from_strstr_to_strchr EQU ___from_strstr_to_strchr_asm
__NLG_Dispatch EQU __NLG_Dispatch_asm
__NLG_Return2 EQU __NLG_Return2_asm
__NLG_Destination EQU __NLG_Destination_asm
__NLG_Notify1 EQU __NLG_Notify1_asm


;; Preventing the startup routines' names from clashing
_WinMainCRTStartup EQU _start_asm
_WinMain@16 EQU  _WinMain_asm@16
IMPORT__WinMain@16 = 1
_WinMain@16_clone EQU _WinMain_orig@16

;; Hooking app exit
IMPORT_?AppExit@@YIXXZ = 1

;; Requiring assembly to put C++ objects on new heap
??2@YAPAXI@Z EQU _op_new
IMPORT_??2@YAPAXI@Z = 1
??3@YAXPAX@Z EQU _op_del
IMPORT_??3@YAXPAX@Z = 1

;;init
IMPORT_?InitMainClasses@@YIXXZ = 1
IMPORT_?DeleteMainClasses@@YIXXZ = 1

;;allowing play without CD
IMPORT_?SetupCDDrive@@YIHXZ = 1
?SetupCDDrive@@YIHXZ_clone EQU ?SetupCDDrive_orig@@YIHXZ
IMPORT_?SetupCDRom@@YIXXZ = 1
IMPORT_?SetupGame@game@@QAEHXZ = 1
?SetupGame@game@@QAEHXZ_clone EQU ?SetupGame_orig@game@@QAEHXZ

IMPORT_?CDStartup@soundManager@@QAEXXZ = 1
?CDStartup@soundManager@@QAEXXZ_clone EQU ?CDStartup_orig@soundManager@@QAEXXZ

;;;resourceManager

IMPORT_??_7resourceManager@@6B@ = 1
IMPORT_??0resourceManager@@QAE@XZ = 1
IMPORT_?GetBackdrop@resourceManager@@QAEXPADPAVbitmap@@H@Z = 1
IMPORT_?GetPalette@resourceManager@@QAEPAVpalette@@PAD@Z = 1
IMPORT_?GetBitmap@resourceManager@@QAEPAVbitmap@@PAD@Z = 1
IMPORT_?GetIcon@resourceManager@@QAEPAVicon@@PAD@Z = 1
IMPORT_?GetIcon@resourceManager@@QAEPAVicon@@K@Z = 1
IMPORT_?GetTileset@resourceManager@@QAEPAVtileset@@PAD@Z = 1
IMPORT_?GetFont@resourceManager@@QAEPAVfont@@PAD@Z = 1
IMPORT_?GetSample@resourceManager@@QAEPAVsample@@PAD@Z = 1
IMPORT_?GetMIDIWrap@resourceManager@@QAEPAVMIDIWrap@@PAD@Z = 1
IMPORT_?Dispose@resourceManager@@QAEXPAVresource@@@Z = 1
IMPORT_?AddResource@resourceManager@@QAEXPAVresource@@@Z = 1
IMPORT_?Expunge@resourceManager@@QAEXXZ = 1
IMPORT_?Query@resourceManager@@QAEPAVresource@@K@Z = 1
IMPORT_?Main@resourceManager@@UAEHAAUtag_message@@@Z = 1
IMPORT_?Open@resourceManager@@UAEHH@Z = 1
IMPORT_?RemoveResource@resourceManager@@QAEXPAVresource@@@Z = 1
IMPORT_?Close@resourceManager@@UAEXXZ = 1
IMPORT_?LoadAggregateHeader@resourceManager@@QAEHPAD@Z = 1
IMPORT_?PointToFile@resourceManager@@QAEXK@Z = 1
IMPORT_?GetFileSize@resourceManager@@QAEKK@Z = 1
IMPORT_?SavePosition@resourceManager@@QAEXXZ = 1
IMPORT_?RestorePosition@resourceManager@@QAEXXZ = 1
IMPORT_?ReadWord@resourceManager@@QAEFXZ = 1
IMPORT_?ReadLong@resourceManager@@QAEJXZ = 1
IMPORT_?MakeId@resourceManager@@QAEKPADH@Z = 1
IMPORT_?Read13@resourceManager@@QAEXPAC@Z = 1
IMPORT_?ReadBlock@resourceManager@@QAEXPACK@Z = 1

IMPORT_?GetBackdrop@resourceManager@@QAEXPADPAVbitmap@@H@Z = 1
?GetBackdrop@resourceManager@@QAEXPADPAVbitmap@@H@Z_clone EQU ?GetBackdrop_orig@resourceManager@@QAEXPADPAVbitmap@@H@Z

;;creatures

IMPORT_?cArmyFrameFileNames@@3PAPADA = 1
IMPORT_?cMonFilename@@3PAPADA = 1
IMPORT_?gArmyNames@@3PAPADA = 1
IMPORT_?gArmyNamesPlural@@3PAPADA = 1
IMPORT_?gMonsterDatabase@@3PAUtag_monsterInfo@@A = 1

;;armies

IMPORT_??0armyGroup@@QAE@XZ = 1

;;game
IMPORT_?oldmain@@YIHXZ = 1
?oldmain@@YIHXZ_clone EQU ?oldmain_orig@@YIHXZ
;;IMPORT_?MainLoop@executive@@QAEXXZ = 1
;;?MainLoop@executive@@QAEXXZ_clone EQU ?MainLoop_orig@executive@@QAEXXZ
IMPORT_?Process1WindowsMessage@@YIXXZ = 1
?Process1WindowsMessage@@YIXXZ_clone EQU ?Process1WindowsMessage_orig@@YIXXZ

;;sound
;;IMPORT___imp__AIL_redbook_play@12 = 1
IMPORT_?CDPlay@soundManager@@QAEXHHHH@Z = 1
?CDPlay@soundManager@@QAEXHHHH@Z_clone EQU CDPlay_orig@soundManager@@QAEXHHHH@Z
IMPORT_?CDStop@soundManager@@QAEXXZ = 1
?CDStop@soundManager@@QAEXXZ_clone EQU ?CDStop_orig@soundManager@@QAEXXZ
IMPORT_?CDSetVolume@soundManager@@QAEXHH@Z = 1
?CDSetVolume@soundManager@@QAEXHH@Z_clone EQU ?CDSetVolume_orig@soundManager@@QAEXHH@Z
IMPORT_?ConvertVolume@soundManager@@QAEHHH@Z = 1
?ConvertVolume@soundManager@@QAEHHH@Z_clone EQU ?ConvertVolume_orig@soundManager@@QAEHHH@Z


;;mouse manager
IMPORT_?NewUpdate@mouseManager@@QAEXH@Z = 1
?NewUpdate@mouseManager@@QAEXH@Z_clone EQU ?NewUpdate_orig@mouseManager@@QAEXH@Z
?iHotSpot@@3PAY01CA EQU ?iHotSpot_asm@@3PAY01CA
?iMouseSize@@3PAY01CA EQU ?iMouseSize_asm@@3PAY01CA

IMPORT_?MouseMessageHandler@@YIHPAXIIJ@Z = 1
?MouseMessageHandler@@YIHPAXIIJ@Z_clone EQU MouseMessageHandler_orig@@YIHPAXIIJ@Z


;;drawing
IMPORT_?CompleteDraw@advManager@@QAEXHHHH@Z = 1
?CompleteDraw@advManager@@QAEXHHHH@Z_clone EQU ?CompleteDraw_orig@advManager@@QAEXHHHH@Z
IMPORT_?DrawAdventureBorder@advManager@@QAEXXZ = 1
?DrawAdventureBorder@advManager@@QAEXXZ_clone EQU ?DrawAdventureBorder_orig@advManager@@QAEXXZ
IMPORT_?SaveAdventureBorder@advManager@@QAEXXZ = 1
?SaveAdventureBorder@advManager@@QAEXXZ_clone EQU ?SaveAdventureBorder_orig@advManager@@QAEXXZ
IMPORT_?DrawCell@advManager@@QAEXHHHHHH@Z = 1
?DrawCell@advManager@@QAEXHHHHHH@Z_clone EQU ?DrawCell_orig@advManager@@QAEXHHHHHH@Z
IMPORT_?ComboDraw@advManager@@QAEHHHH@Z = 1
?ComboDraw@advManager@@QAEHHHH@Z_clone EQU ?ComboDraw_orig@advManager@@QAEHHHH@Z
IMPORT_?RedrawAdvScreen@advManager@@QAEXHH@Z = 1
?RedrawAdvScreen@advManager@@QAEXHH@Z_clone EQU ?RedrawAdvScreen_orig@advManager@@QAEXHH@Z
IMPORT_?CopyTo@bitmap@@QAEXPAV1@HHHHHH@Z = 1
?CopyTo@bitmap@@QAEXPAV1@HHHHHH@Z_clone EQU ?CopyTo_orig@bitmap@@QAEXPAV1@HHHHHH@Z
IMPORT_?RedrawHeroScreen@@YIXXZ = 1
?RedrawHeroScreen@@YIXXZ_clone EQU ?RedrawHeroScreen_orig@@YIXXZ
IMPORT_?FizzleCenter@advManager@@QAEXH@Z = 1
?FizzleCenter@advManager@@QAEXH@Z_clone EQU ?FizzleCenter_orig@advManager@@QAEXH@Z
IMPORT_?SaveFizzleSource@heroWindowManager@@QAEXHHHH@Z = 1
?SaveFizzleSource@heroWindowManager@@QAEXHHHH@Z_clone EQU ?SaveFizzleSource_orig@heroWindowManager@@QAEXHHHH@Z

IMPORT_?IconToBitmap@@YIXPAVicon@@PAVbitmap@@HHHHHHHHH@Z = 1
?IconToBitmap@@YIXPAVicon@@PAVbitmap@@HHHHHHHHH@Z_clone EQU ?IconToBitmap_orig@@YIXPAVicon@@PAVbitmap@@HHHHHHHHH@Z
IMPORT_?WGAppPaint@@YIHPAX0@Z = 1
?WGAppPaint@@YIHPAX0@Z_clone EQU ?WGAppPaint_orig@@YIHPAX0@Z

IMPORT_?UpdateScreenRegion@heroWindowManager@@QAEXHHHH@Z = 1
?UpdateScreenRegion@heroWindowManager@@QAEXHHHH@Z_clone EQU ?UpdateScreenRegion_orig@heroWindowManager@@QAEXHHHH@Z
IMPORT_?InitGraphics@@YIXXZ = 1
?InitGraphics@@YIXXZ_clone EQU ?InitGraphics_orig@@YIXXZ
IMPORT_?WGInitGraphics@@YIXXZ = 1
?WGInitGraphics@@YIXXZ_clone EQU ?WGInitGraphics_orig@@YIXXZ
IMPORT_?DDInitGraphics@@YIXXZ = 1
?DDInitGraphics@@YIXXZ_clone EQU ?DDInitGraphics_orig@@YIXXZ
IMPORT_?SetGraphicsType@@YIHH@Z = 1
?SetGraphicsType@@YIHH@Z_clone EQU ?SetGraphicsType_orig@@YIHH@Z
IMPORT_?ShowHeroesLogo@game@@QAEXXZ = 1
?ShowHeroesLogo@game@@QAEXXZ_clone EQU ?ShowHeroesLogo_orig@game@@QAEXXZ

IMPORT_?FizzleForward@heroWindowManager@@QAEXHHHHHPAC0@Z = 1
?FizzleForward@heroWindowManager@@QAEXHHHHHPAC0@Z_clone EQU ?FizzleForward_orig@heroWindowManager@@QAEXHHHHHPAC0@Z

IMPORT_??0heroWindow@@QAE@HHHHH@Z = 1
;;??0heroWindow@@QAE@HHHHH@Z_clone EQU ??0heroWindow@@QAE@HHHHH@Z

IMPORT_@BlitBitmapToScreenVesa@28 = 1
@BlitBitmapToScreenVesa@28_clone EQU @BlitBitmapToScreenVesa_orig@28
;;IMPORT_?BlitBitmapToScreenNoMouseCheck@@YIXPAVbitmap@@HHHHHH@Z = 1
;;BlitBitmapToScreenNoMouseCheck@@YIXPAVbitmap@@HHHHHH@Z_clone EQU BlitBitmapToScreenNoMouseCheck_orig@@YIXPAVbitmap@@HHHHHH@Z
IMPORT_?BlitBitmapToScreen@@YIXPAVbitmap@@HHHHHH@Z = 1
?BlitBitmapToScreen@@YIXPAVbitmap@@HHHHHH@Z_clone EQU ?BlitBitmapToScreen_orig@@YIXPAVbitmap@@HHHHHH@Z

;;puzzle
IMPORT_?PuzzleDraw@advManager@@QAEXHHHH@Z = 1
?PuzzleDraw@advManager@@QAEXHHHH@Z_clone EQU ?PuzzleDraw_orig@advManager@@QAEXHHHH@Z
IMPORT_?ViewPuzzle@advManager@@QAEXXZ = 1
IMPORT_?ViewPuzzle@advManager@@QAEXXZ_clone EQU IMPORT_?ViewPuzzle_orig@advManager@@QAEXXZ

;;fix for tickcount bug
IMPORT_?KBTickCount@@YIJXZ = 1
?KBTickCount@@YIJXZ_clone EQU ?KBTickCount_orig@@YIJXZ

;;adventure screen
IMPORT_?InMapArea@@YIHHH@Z = 1
;;IMPORT_?ProcessHover@advManager@@QAEHHH@Z = 1

IMPORT_?UpdateScreen@advManager@@QAEXHH@Z = 1
?UpdateScreen@advManager@@QAEXHH@Z_clone EQU ?UpdateScreen_orig@advManager@@QAEXHH@Z
IMPORT_?UpdBottomView@advManager@@QAEXHHH@Z = 1
?UpdBottomView@advManager@@QAEXHHH@Z_clone EQU ?UpdBottomView_orig@advManager@@QAEXHHH@Z

IMPORT_?QuickInfo@advManager@@QAEXHH@Z = 1
?QuickInfo@advManager@@QAEXHH@Z_clone EQU ?QuickInfo_orig@advManager@@QAEXHH@Z

IMPORT_?Open@heroWindowManager@@UAEHH@Z = 1
?Open@heroWindowManager@@UAEHH@Z_clone EQU ?Open_orig@heroWindowManager@@QAEHH@Z

IMPORT_?SetTownContext@advManager@@QAEXH@Z = 1
?SetTownContext@advManager@@QAEXH@Z_clone EQU ?SetTownContext_orig@advManager@@QAEXH@Z
IMPORT_?SetHeroContext@advManager@@QAEXHH@Z = 1
?SetHeroContext@advManager@@QAEXHH@Z_clone EQU ?SetHeroContext_orig@advManager@@QAEXHH@Z

IMPORT_?SetEnvironmentOrigin@advManager@@QAEXHHH@Z = 1
?SetEnvironmentOrigin@advManager@@QAEXHHH@Z_clone EQU ?SetEnvironmentOrigin_orig@advManager@@QAEXHHH@Z


;;adventure screen 'radar' (mini-map)
IMPORT_?UpdateRadar@advManager@@QAEXHH@Z = 1
?UpdateRadar@advManager@@QAEXHH@Z_clone EQU ?UpdateRadar_orig@advManager@@QAEXHH@Z

;;application functions
IMPORT_?AppCommand@@YIJPAXIIJ@Z = 1
?AppCommand@@YIJPAXIIJ@Z_clone EQU ?AppCommand_orig@@YIJPAXIIJ@Z
IMPORT_?UpdateDfltMenu@@YIXPAX@Z = 1
?UpdateDfltMenu@@YIXPAX@Z_clone EQU ?UpdateDfltMenu_orig@@YIXPAX@Z

;;main menu
IMPORT_?InitMenuHandler@@YIHAAUtag_message@@@Z = 1
?InitMenuHandler@@YIHAAUtag_message@@@Z_clone EQU ?InitMenuHandler_orig@@YIHAAUtag_message@@@Z
IMPORT_?CheckShingleUpdate@@YIXXZ = 1
?CheckShingleUpdate@@YIXXZ_clone EQU ?CheckShingleUpdate_clone@@YIXXZ


;;system options
IMPORT_?SystemOptionsHandler@@YIHAAUtag_message@@@Z = 1
?SystemOptionsHandler@@YIHAAUtag_message@@@Z_clone EQU ?SystemOptionsHandler_orig@@YIHAAUtag_message@@@Z

;;keyboard input
IMPORT_?KeyboardMessageHandler@@YIHPAXIIJ@Z = 1
?KeyboardMessageHandler@@YIHPAXIIJ@Z_clone EQU ?KeyboardMessageHandler_orig@@YIHPAXIIJ@Z

;;mouse input / cursor
IMPORT_?MouseCoords@mouseManager@@QAEXAAH0@Z = 1
?MouseCoords@mouseManager@@QAEXAAH0@Z_clone EQU ?MouseCoords_orig@mouseManager@@QAEXAAH0@Z
IMPORT_?SaveAndDraw@mouseManager@@QAEXXZ = 1
?SaveAndDraw@mouseManager@@QAEXXZ_clone EQU ?SaveAndDraw_orig@mouseManager@@QAEXXZ
IMPORT_?RestoreUnderlying@mouseManager@@QAEXXZ = 1
?RestoreUnderlying@mouseManager@@QAEXXZ_clone EQU ?RestoreUnderlying_orig@mouseManager@@QAEXXZ
IMPORT_?CheckChangeCursor@@YIXHHH@Z= 1
?CheckChangeCursor@@YIXHHH@Z_clone EQU ?CheckChangeCursor_orig@@YIXHHH@Z
IMPORT_?ReallyShowPointer@mouseManager@@QAEXXZ = 1
?ReallyShowPointer@mouseManager@@QAEXXZ_clone EQU ?ReallyShowPointer_orig@mouseManager@@QAEXXZ


IMPORT_?GetRandomNumTroops@game@@QAEHH@Z = 1
IMPORT_?NextPlayer@game@@QAEXXZ = 1
?NextPlayer@game@@QAEXXZ_clone EQU ?NextPlayer_orig@game@@QAEXXZ

;;gui
;;IMPORT_??0iconWidget@@QAE@FFFFPADFCFFF@Z = 1
;;IMPORT_??_GiconWidget@@UAEPAXI@Z = 1
;;IMPORT_??_7iconWidget@@6B@ = 1
;;??0iconWidget@@QAE@FFFFPADFCFFF@Z_clone EQU ??0iconWidget_orig@@QAE@FFFFPADFCFFF@Z ;;this does not work
IMPORT_?AddWidget@heroWindow@@QAEXPAVwidget@@H@Z = 1
?AddWidget@heroWindow@@QAEXPAVwidget@@H@Z_clone EQU ?AddWidget_orig@heroWindow@@QAEXPAVwidget@@H@Z

;;hero
IMPORT_??0hero@@QAE@XZ = 1
IMPORT_?AddSpell@hero@@QAEXHH@Z = 1
IMPORT_?HasSpell@hero@@QAEHH@Z = 1
IMPORT_?GetNumSpells@hero@@QAEHH@Z = 1
IMPORT_?GetNthSpell@hero@@QAEHHH@Z = 1

;;artifacts
IMPORT_?gArtifactNames@@3PAPADA = 1
IMPORT_?gArtifactDesc@@3PAPADA = 1
IMPORT_?gArtifactEvents@@3PAPADA = 1
IMPORT_?gArtifactLevel@@3PAEA = 1

;;combat
IMPORT_?CombatClipDrawToBuffer@icon@@QAEHHHHPAUSLimitData@@HHPAEPAC@Z = 1
?CombatClipDrawToBuffer@icon@@QAEHHHHPAUSLimitData@@HHPAEPAC@Z_clone EQU ?CombatClipDrawToBuffer_orig@icon@@QAEHHHHPAUSLimitData@@HHPAEPAC@Z
IMPORT_?InitNonVisualVars@combatManager@@QAEXXZ = 1
?InitNonVisualVars@combatManager@@QAEXXZ_clone EQU ?InitNonVisualVars_orig@combatManager@@QAEXXZ
IMPORT_?DrawFrame@combatManager@@QAEXHHHHHHH@Z = 1
?DrawFrame@combatManager@@QAEXHHHHHHH@Z_clone EQU ?DrawFrame_orig@combatManager@@QAEXHHHHHHH@Z
IMPORT_?MoveAttack@army@@QAEXHH@Z = 1
?MoveAttack@army@@QAEXHH@Z_clone EQU ?MoveAttack_orig@army@@QAEXHH@Z
IMPORT_?sElevationOverlay@@3PAUSElevationOverlay@@A = 1
IMPORT_?DrawFrame@combatManager@@QAEXHHHHHHH@Z = 1
?DrawFrame@combatManager@@QAEXHHHHHHH@Z_clone EQU ?DrawFrame_orig@combatManager@@QAEXHHHHHHH@Z
;;lich death cloud attack effect
IMPORT_?PowEffect@army@@QAEXHHHH@Z = 1
?PowEffect@army@@QAEXHHHH@Z_clone EQU ?PowEffect_orig@army@@QAEXHHHH@Z
IMPORT_?SpecialAttack@army@@QAEXXZ = 1
?SpecialAttack@army@@QAEXXZ_clone EQU ?SpecialAttack_orig@army@@QAEXXZ

;;heroes
IMPORT_?cHeroTypeInitial@@3PADA = 1
IMPORT_?sCmbtHero@@3PAUSCmbtHero@@A = 1
IMPORT_?gAlignmentNames@@3PAPADA = 1

;; adventure map

IMPORT_?SetVisibility@game@@QAEXHHHH@Z = 1
?SetVisibility@game@@QAEXHHHH@Z_clone EQU ?SetVisibility_orig@game@@QAEXHHHH@Z
IMPORT_?MakeAllWaterVisible@game@@QAEXH@Z = 1
?MakeAllWaterVisible@game@@QAEXH@Z_clone EQU ?MakeAllWaterVisible_orig@game@@QAEXH@Z

IMPORT_?ProcessSelect@advManager@@QAEHPAUtag_message@@PAPAVmapCell@@@Z = 1
?ProcessSelect@advManager@@QAEHPAUtag_message@@PAPAVmapCell@@@Z_clone EQU ?ProcessSelect_orig@advManager@@QAEHPAUtag_message@@PAPAVmapCell@@@Z

;;hero movement reminder
IMPORT_?ProcessDeSelect@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z = 1
?ProcessDeSelect@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z_clone EQU ?ProcessDeSelect_orig@advManager@@QAEHPAUtag_message@@PAHPAPAVmapCell@@@Z

;;;; border guards
IMPORT_?BarrierEvent@advManager@@QAEHPAVmapCell@@PAVhero@@@Z = 1
IMPORT_?PasswordEvent@advManager@@QAEXPAVmapCell@@PAVhero@@@Z = 1

;;saving
IMPORT_?LoadGame@game@@QAEXPADHH@Z = 1
?LoadGame@game@@QAEXPADHH@Z_clone EQU ?LoadGame_orig@game@@QAEXPADHH@Z
IMPORT_?SaveGame@game@@QAEHPADHC@Z = 1
IMPORT_?Read@hero@@QAEXHC@Z = 1
IMPORT_?RandomizeHeroPool@game@@QAEXXZ = 1

;;maps
IMPORT_?NewMap@game@@QAEXPAD@Z = 1
?NewMap@game@@QAEXPAD@Z_clone EQU ?NewMap_orig@game@@QAEXPAD@Z

;;spells
IMPORT_?gsSpellInfo@@3PAUSSpellInfo@@A = 1
IMPORT_?gSpellDesc@@3PAPADA = 1
IMPORT_?gSpellNames@@3PAPADA = 1
IMPORT_?CastSpell@advManager@@QAEXH@Z = 1
?CastSpell@advManager@@QAEXH@Z_clone EQU ?CastSpell_orig@advManager@@QAEXH@Z
IMPORT_?Resurrect@combatManager@@QAEXHHH@Z = 1
IMPORT_?DimensionDoor@advManager@@QAEXXZ = 1

;;towns
IMPORT_?SetupTowns@game@@QAEXXZ = 1
IMPORT_?SetupMage@townManager@@QAEXPAVheroWindow@@@Z = 1
IMPORT_?RecruitHero@townManager@@QAEHHH@Z = 1
?RecruitHero@townManager@@QAEHHH@Z_clone EQU ?RecruitHero_orig@townManager@@QAEHHH@Z
IMPORT_?GetBuildingName@@YIPADHH@Z = 1

;;scripting hooks
IMPORT_?PerDay@game@@QAEXXZ = 1
?PerDay@game@@QAEXXZ_clone EQU ?PerDay_orig@game@@QAEXXZ
IMPORT_?Open@advManager@@UAEHH@Z = 1
?Open@advManager@@UAEHH@Z_clone EQU ?Open_orig@advManager@@QAEHH@Z ; Changing U to Q changes virtual method to non
IMPORT_?Open@townManager@@UAEHH@Z = 1
?Open@townManager@@UAEHH@Z_clone EQU ?Open_orig@townManager@@QAEHH@Z ; Changing U to Q changes virtual method to non