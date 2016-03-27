?ProcessHover@advManager@@QAEHHH@Z proc near SYSCALL


var_2C		= dword ptr -44
this		= dword ptr -40
spriteIdxArg		= dword ptr -36
var_20		= dword ptr -32
var_1C		= dword ptr -28
var_18		= dword ptr -24
var_14		= dword ptr -20
var_10		= dword ptr -16
var_C		= dword ptr -12
var_8		= dword ptr -8
var_4		= dword ptr -4
arg_0		= dword ptr 8
arg_4		= dword ptr 12
 

	push  ebp
	mov  ebp, esp
	sub  esp, 2Ch
	push  ebx
	push  esi
	push  edi
	mov  [ebp+this], ecx
	mov  edx, [ebp+arg_4]
	mov  ecx, [ebp+arg_0]
	call  ?InMapArea@@YIHHH@Z
	test  eax, eax
	jz  loc_4479AF
	cmp  [ebp+arg_0], 280h		;;1E0h
	jle  loc_446FF3
	push  0
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, 1
	jmp  loc_4479F9
loc_446FF3::
	mov  eax, [ebp+arg_0]
	cdq  
	and  edx, 1Fh
	add  eax, edx
	sar  eax, 5
	mov  [ebp+var_C], eax
	mov  eax, [ebp+arg_4]
	cdq  
	and  edx, 1Fh
	add  eax, edx
	sar  eax, 5
	mov  [ebp+var_10], eax
	cmp  [ebp+var_C], 0
	jge  loc_447022
	mov  [ebp+var_C], 0
loc_447022::
	cmp  [ebp+var_10], 0
	jge  loc_447033
	mov  [ebp+var_10], 0
loc_447033::
	cmp  [ebp+var_C], 13h		;;0Eh
	jle  loc_447044
	mov  [ebp+var_C], 13h		;;0Eh
loc_447044::
	cmp  [ebp+var_10], 0Eh
	jle  loc_447055
	mov  [ebp+var_10], 0Eh
loc_447055::
	mov  eax, [ebp+this]
	mov  ecx, [ebp+var_C]
	cmp  [eax+1E6h], ecx
	jnz  loc_447079
	mov  eax, [ebp+this]
	mov  ecx, [ebp+var_10]
	cmp  [eax+1EAh], ecx
	jz  loc_4479AA
loc_447079::
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 0FFFFFFFFh
	mov  eax, [ebp+var_C]
	mov  ecx, [ebp+this]
	mov  [ecx+1E6h], eax
	mov  eax, [ebp+var_10]
	mov  ecx, [ebp+this]
	mov  [ecx+1EAh], eax
	mov  eax, [ebp+this]
	mov  eax, [eax+1D6h]
	add  eax, [ebp+var_C]
	mov  ecx, [ebp+this]
	mov  [ecx+1EEh], eax
	mov  eax, [ebp+this]
	mov  eax, [eax+1DAh]
	add  eax, [ebp+var_10]
	mov  ecx, [ebp+this]
	mov  [ecx+1F2h], eax
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+1EEh], 0
	jl  loc_447144
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+1F2h], 0
	jl  loc_447144
	mov  eax, [ebp+this]
	mov  ecx, ?MAP_WIDTH@@3HA
	dec  ecx
	cmp  [eax+1EEh], ecx
	jg  loc_447144
	mov  eax, [ebp+this]
	mov  ecx, ?MAP_HEIGHT@@3HA
	dec  ecx
	cmp  [eax+1F2h], ecx
	jg  loc_447144
	mov  eax, [ebp+this]
	mov  eax, [eax+1F2h]
	imul  eax, ?MAP_WIDTH@@3HA
	mov  ecx, [ebp+this]
	add  eax, [ecx+1EEh]
	mov  ecx, ?mapRevealed@@3PAEA
	xor  edx, edx
	mov  dl, [eax+ecx]
	xor  eax, eax
	mov  al, ?giCurPlayerBit@@3EA
	test  eax, edx
	jnz  loc_44715B
loc_447144::
	push  0
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, 1
	jmp  loc_4479F9
loc_44715B::
	mov  eax, [ebp+this]
	mov  eax, [eax+1F2h]
	push  eax
	mov  eax, [ebp+this]
	mov  eax, [eax+1EEh]
	push  eax
	mov  ecx, [ebp+this]
	call  ?GetCell@advManager@@QAEPAVmapCell@@HH@Z
	mov  [ebp+var_18], eax
	mov  eax, ?gpCurPlayer@@3PAVplayerData@@A
	movsx  eax, byte ptr [eax+2]
	cmp  eax, 0FFFFFFFFh
	jnz  loc_44728C
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	and  cl, 7Fh
	cmp  cl, 23h
	jnz  loc_4471FE
	jmp  NEAR32 PTR $+5
loc_4471A5::
	mov  eax, [ebp+var_18]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	shl  eax, 2
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [eax+ecx+0B54h]
	cmp  eax, ?giCurPlayer@@3HA
	jnz  loc_4471FE
	push  3
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 3
	mov  eax, 1
	jmp  loc_4479F9
	jmp  loc_447287
loc_4471FE::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	and  cl, 7Fh
	cmp  cl, 2Ah
	jnz  loc_447270
	jmp  NEAR32 PTR $+5
loc_447217::
	mov  eax, [ebp+var_18]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [ecx+eax*2+27C7h]
	cmp  eax, ?giCurPlayer@@3HA
	jnz  loc_447270
	push  2
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 2
	mov  eax, 1
	jmp  loc_4479F9
	jmp  loc_447287
loc_447270::
	push  0
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, 1
	jmp  loc_4479F9
loc_447287::
	jmp  loc_4479AA
loc_44728C::
	jmp  NEAR32 PTR $+5
loc_447291::
	mov  eax, ?gpCurPlayer@@3PAVplayerData@@A
	movsx  eax, byte ptr [eax+2]
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	add  eax, eax
	add  eax, ?gpGame@@3PAVgame@@A
	add  eax, 27C4h
	mov  [ebp+var_1C], eax
	mov  eax, [ebp+var_1C]
	mov  eax, [eax+19h]
	mov  ecx, [ebp+this]
	sub  eax, [ecx+1D6h]
	mov  [ebp+var_4], eax
	mov  eax, [ebp+var_1C]
	mov  eax, [eax+1Dh]
	mov  ecx, [ebp+this]
	sub  eax, [ecx+1DAh]
	mov  [ebp+var_8], eax
	mov  eax, [ebp+var_4]
	cmp  [ebp+var_C], eax
	jnz  loc_447310
	mov  eax, [ebp+var_8]
	cmp  [ebp+var_10], eax
	jnz  loc_447310
	push  2
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 2
	mov  eax, 1
	jmp  loc_4479F9
loc_447310::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+8]
	test  cl, 8
	jz  loc_4473B8
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	and  cl, 7Fh
	cmp  cl, 23h
	jnz  loc_447395
	jmp  NEAR32 PTR $+5
loc_44733A::
	mov  eax, [ebp+var_18]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	shl  eax, 2
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	add  eax, ?gpGame@@3PAVgame@@A
	add  eax, 0B53h
	mov  [ebp+var_14], eax
	mov  eax, [ebp+var_14]
	movsx  eax, byte ptr [eax+1]
	cmp  eax, ?giCurPlayer@@3HA
	jnz  loc_447395
	push  3
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 5
	mov  eax, 1
	jmp  loc_4479F9
loc_447395::
	mov  eax, ?gpSearchArray@@3PAVsearchArray@@A
	mov  dword ptr [eax+8], 0
	push  0
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, 1
	jmp  loc_4479F9
loc_4473B8::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+27Ah], 6
	jz  loc_44741C
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cx, [eax]
	xor  eax, eax
	mov  al, ?giGroundToTerrain@@3PAEA[ecx]
	test  eax, eax
	jnz  loc_44741C
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 0AAh
	jz  loc_44741C
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 0ABh
	jz  loc_44741C
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 0A0h
	jnz  loc_447455
loc_44741C::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+27Ah], 6
	jnz  loc_447478
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cx, [eax]
	xor  eax, eax
	mov  al, ?giGroundToTerrain@@3PAEA[ecx]
	test  eax, eax
	jz  loc_447478
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 1Ch
	jz  loc_447478
loc_447455::
	mov  eax, ?gpSearchArray@@3PAVsearchArray@@A
	mov  dword ptr [eax+8], 0
	push  0
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, 1
	jmp  loc_4479F9
loc_447478::
	mov  eax, [ebp+this]
	mov  eax, [eax+1F2h]
	push  eax
	mov  eax, [ebp+this]
	mov  eax, [eax+1EEh]
	push  eax
	mov  ecx, [ebp+this]
	call  ?SeedTo@advManager@@QAEXHH@Z
	jmp  NEAR32 PTR $+5
loc_447499::
	mov  eax, [ebp+this]
	mov  eax, [eax+1F2h]
	imul  eax, ?MAP_WIDTH@@3HA
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+this]
	mov  ecx, [ecx+1EEh]
	lea  ecx, [ecx+ecx*8]
	add  eax, ecx
	mov  ecx, ?gpSearchArray@@3PAVsearchArray@@A
	mov  ecx, [ecx+2414h]
	mov  al, [eax+ecx+4]
	test  al, 1
	jz  loc_447993
	jmp  NEAR32 PTR $+5
loc_4474D7::
	mov  eax, [ebp+this]
	mov  eax, [eax+1F2h]
	imul  eax, ?MAP_WIDTH@@3HA
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+this]
	mov  ecx, [ecx+1EEh]
	lea  ecx, [ecx+ecx*8]
	add  eax, ecx
	mov  ecx, ?gpSearchArray@@3PAVsearchArray@@A
	mov  ecx, [ecx+2414h]
	xor  edx, edx
	mov  dx, [eax+ecx+2]
	mov  eax, [ebp+var_1C]
	cmp  edx, [eax+35h]
	jg  loc_447523
	mov  [ebp+var_20], 0
	jmp  loc_447580
loc_447523::
	jmp  NEAR32 PTR $+5
loc_447528::
	mov  eax, [ebp+this]
	mov  eax, [eax+1F2h]
	imul  eax, ?MAP_WIDTH@@3HA
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+this]
	mov  ecx, [ecx+1EEh]
	lea  ecx, [ecx+ecx*8]
	add  eax, ecx
	mov  ecx, ?gpSearchArray@@3PAVsearchArray@@A
	mov  ecx, [ecx+2414h]
	xor  edx, edx
	mov  dx, [eax+ecx+2]
	mov  eax, [ebp+var_1C]
	sub  edx, [eax+35h]
	mov  ecx, [ebp+var_1C]
	mov  eax, edx
	cdq  
	idiv  dword ptr [ecx+31h]
	inc  eax
	mov  [ebp+var_20], eax
	cmp  [ebp+var_20], 3
	jle  loc_447580
	mov  [ebp+var_20], 3
loc_447580::
	mov  eax, [ebp+var_20]
	lea  eax, [eax+eax*2]
	add  eax, eax
	mov  [ebp+spriteIdxArg], eax
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	and  ecx, 7Fh
	mov  [ebp+var_2C], ecx
	jmp  loc_447938
loc_44759E::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+27Ah], 6
	jz  loc_4475CF
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 6
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 1
	jmp  loc_4475DE
loc_4475CF::
	mov  eax, [ebp+spriteIdxArg]
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
loc_4475DE::
	jmp  loc_447984
loc_4475E3::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+27Ah], 6
	jnz  loc_44760A
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 7
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	jmp  loc_447660
loc_44760A::
	mov  eax, [ebp+this]
	mov  eax, [eax+1F2h]
	imul  eax, ?MAP_WIDTH@@3HA
	mov  ecx, [ebp+this]
	add  eax, [ecx+1EEh]
	mov  ecx, ?mapRevealed@@3PAEA
	xor  edx, edx
	mov  dl, [eax+ecx]
	test  dl, 80h
	jz  loc_44764E
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 5
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	jmp  loc_447660
loc_44764E::
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 4
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
loc_447660::
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 1
	jmp  loc_447984
loc_44766F::
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 5
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 1
	jmp  loc_447984
loc_447690::
	jmp  NEAR32 PTR $+5
loc_447695::
	mov  eax, [ebp+var_18]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [ecx+eax*2+27C7h]
	cmp  eax, ?giCurPlayer@@3HA
	jz  loc_4476E9
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 5
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 1
	jmp  loc_447705
loc_4476E9::
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 8
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 1
loc_447705::
	jmp  loc_447984
loc_44770A::
	jmp  NEAR32 PTR $+5
loc_44770F::
	mov  eax, [ebp+var_18]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	shl  eax, 2
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	add  eax, ?gpGame@@3PAVgame@@A
	add  eax, 0B53h
	mov  [ebp+var_14], eax
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	test  cl, 80h
	jz  loc_44778B
	mov  eax, [ebp+var_14]
	movsx  eax, byte ptr [eax+1]
	cmp  eax, ?giCurPlayer@@3HA
	jz  loc_44778B
	mov  ecx, [ebp+var_14]
	call  ?HasGarrison@town@@QAEHXZ
	test  eax, eax
	jz  loc_44778B
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 5
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 1
	jmp  loc_447984
loc_44778B::
	jmp  loc_4479F4
	jmp  NEAR32 PTR $+5
loc_447795::
	mov  eax, [ebp+this]
	mov  eax, [eax+1F2h]
	imul  eax, ?MAP_WIDTH@@3HA
	mov  ecx, [ebp+this]
	add  eax, [ecx+1EEh]
	mov  ecx, ?mapRevealed@@3PAEA
	xor  edx, edx
	mov  dl, [eax+ecx]
	test  dl, 80h
	jz  loc_44780E
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+27Ah], 6
	jz  loc_44780E
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	test  cl, 80h
	jz  loc_4477F7
	mov  ecx, [ebp+var_18]
	call  ?StopOnTrigger@@YIEPAVmapCell@@@Z
	xor  ecx, ecx
	mov  cl, al
	test  ecx, ecx
	jnz  loc_44780E
loc_4477F7::
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 5
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	jmp  loc_447924
loc_44780E::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	test  cl, 80h
	jz  loc_4478EB
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+27Ah], 6
	jz  loc_4478A5
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cx, [eax]
	xor  eax, eax
	mov  al, ?giGroundToTerrain@@3PAEA[ecx]
	test  eax, eax
	jz  loc_44785E
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 9
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	jmp  loc_4478A0
loc_44785E::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 0A0h
	jnz  loc_447889
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 9
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	jmp  loc_4478A0
loc_447889::
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 4
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	jmp  loc_447984
loc_4478A0::
	jmp  loc_4478E6
loc_4478A5::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cx, [eax]
	xor  eax, eax
	mov  al, ?giGroundToTerrain@@3PAEA[ecx]
	test  eax, eax
	jnz  loc_4478D4
	mov  eax, [ebp+var_20]
	add  eax, 1Ch
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	jmp  loc_4478E6
loc_4478D4::
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 6
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
loc_4478E6::
	jmp  loc_447924
loc_4478EB::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+27Ah], 6
	jnz  loc_447912
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 6
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	jmp  loc_447924
loc_447912::
	mov  eax, [ebp+spriteIdxArg]
	add  eax, 4
	push  eax
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
loc_447924::
	mov  eax, [ebp+this]
	mov  dword ptr [eax+36h], 1
	jmp  loc_447984
	jmp  loc_447984
loc_447938::
	sub  [ebp+var_2C], 18h
	cmp  [ebp+var_2C], 13h
	ja  loc_447795
	mov  eax, [ebp+var_2C]
	xor  ecx, ecx
	mov  cl, ds:byte_447970[eax]
	jmp  ds:off_447958[ecx*4]
IFDEF IMPORT_off_447958
extern off_447958 : dword
ELSE
off_447958      dd offset loc_44766F    ; DATA XREF: advManager__ProcessHover(int,int)+9A1r
                dd offset loc_4475E3    ; jump table for switch statement
                dd offset loc_44770A
                dd offset loc_447690
                dd offset loc_44759E
                dd offset loc_447795
ENDIF
IFDEF IMPORT_byte_447970
extern byte_447970 : dword
ELSE
byte_447970     db      0,     5,     5,     5
                db      1,     5,     5,     5 ; indirect table for switch statement
                db      5,     5,     5,     2
                db      5,     5,     5,     5
                db      5,     5,     3,     4
ENDIF
loc_447984::
	mov  eax, 1
	jmp  loc_4479F9
	jmp  loc_4479AA
loc_447993::
	push  0
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
	mov  eax, 1
	jmp  loc_4479F9
loc_4479AA::
	jmp  loc_4479EA
loc_4479AF::
	mov  eax, ?gpMouseManager@@3PAVmouseManager@@A
	cmp  dword ptr [eax+3Ah], 20h
	jl  loc_4479DD
	mov  eax, ?gpMouseManager@@3PAVmouseManager@@A
	cmp  dword ptr [eax+3Ah], 28h
	jge  loc_4479DD
	mov  ecx, [ebp+this]
	call  ?MouseInScrollZone@advManager@@QAEHXZ
	test  eax, eax
	jnz  loc_4479EA
loc_4479DD::
	push  0
	mov  ecx, ?gpMouseManager@@3PAVmouseManager@@A
	call  ?SetPointer@mouseManager@@QAEXH@Z
loc_4479EA::
	mov  eax, 1
	jmp  loc_4479F9
loc_4479F4::
	jmp  loc_447795
loc_4479F9::
	pop  edi
	pop  esi
	pop  ebx
	leave  
	retn  8
?ProcessHover@advManager@@QAEHHH@Z endp