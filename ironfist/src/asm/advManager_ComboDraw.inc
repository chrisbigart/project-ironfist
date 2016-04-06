                align 10h
IFDEF IMPORT_?ComboDraw@advManager@@QAEHHHH@Z
?ComboDraw@advManager@@QAEHHHH@Z PROTO SYSCALL
ELSE
?ComboDraw@advManager@@QAEHHHH@Z proc near SYSCALL


this		= dword ptr -28
var_18		= dword ptr -24
a4		= dword ptr -20
a3		= dword ptr -16
var_C		= dword ptr -12
var_8		= dword ptr -8
var_4		= dword ptr -4
left		= dword ptr 8
y		= dword ptr 12
arg_8		= dword ptr 16
 

	push  ebp
	mov  ebp, esp
	sub  esp, 1Ch
	push  ebx
	push  esi
	push  edi
	mov  [ebp+this], ecx
	call  @PollSound@0
	cmp  ?bShowIt@@3HA, 0
	jnz  loc_451D95
	xor  eax, eax
	jmp  loc_452F13
loc_451D95::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+2AEh], 0
	jz  loc_451DC3
	push  1
	push  0
	mov  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?CompleteDraw@advManager@@QAEXHHHH@Z
	mov  eax, 1
	jmp  loc_452F13
loc_451DC3::
	cmp  [ebp+arg_8], 0
	jz  loc_451E23
	mov  eax, ?giFrameStep@@3HA
	add  ?giFrameCount@@3HA, eax
	cmp  ?giFrameCount@@3HA, 0Ch
	jge  loc_451E19
	call  ?Process1WindowsMessage@@YIXXZ
	call  ?KBTickCount@@YIJXZ
	cmp  eax, ?glTimers@@3HA
	jle  loc_451E08
	call  ?KBTickCount@@YIJXZ
	add  eax, 78h
	mov  ?glTimers@@3HA, eax
loc_451E08::
	call  @PollSound@0
	xor  eax, eax
	jmp  loc_452F13
	jmp  loc_451E23
loc_451E19::
	mov  ?giFrameCount@@3HA, 0
loc_451E23::
	mov  eax, [ebp+this]
	mov  eax, [eax+1D6h]
	mov  ecx, [ebp+this]
	mov  [ecx+1DEh], eax
	mov  eax, [ebp+this]
	mov  eax, [eax+1DAh]
	mov  ecx, [ebp+this]
	mov  [ecx+1E2h], eax
	push  100h
	push  0
	push  offset ?bComboDraw@@3PAY0BC@CA
	call  _memset
	add  esp, 0Ch
	mov  eax, [ebp+this]
	mov  dword ptr [eax+2A2h], 0
	mov  [ebp+a4], 0
	jmp  loc_451E77
loc_451E74::
	inc  [ebp+a4]
loc_451E77::
	cmp  [ebp+a4], 0Fh
	jge  loc_4523B8
	mov  [ebp+a3], 0
	jmp  loc_451E90
loc_451E8D::
	inc  [ebp+a3]
loc_451E90::
	cmp  [ebp+a3], 0Fh
	jge  loc_4523B3
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	js  loc_4523AE
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	cmp  eax, ?MAP_WIDTH@@3HA
	jge  loc_4523AE
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	js  loc_4523AE
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	cmp  eax, ?MAP_HEIGHT@@3HA
	jge  loc_4523AE
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?GetCell@advManager@@QAEPAVmapCell@@HH@Z
	mov  [ebp+var_18], eax
	mov  eax, [ebp+var_18]
	mov  al, [eax+2]
	test  al, 1
	jnz  loc_451F0B
	mov  eax, [ebp+var_18]
	mov  al, [eax+6]
	test  al, 1
	jz  loc_451F1D
loc_451F0B::
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
loc_451F1D::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	and  cl, 7Fh
	cmp  cl, 28h
	jnz  loc_451F43
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
loc_451F43::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	and  cl, 7Fh
	cmp  cl, 1
	jnz  loc_451F69
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
loc_451F69::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 98h
	jnz  loc_4520A9
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFEh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?GetCloudLookup@advManager@@QAEHHH@Z
	test  eax, eax
	jz  loc_45205F
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a3]
	lea  ecx, ds:2[ecx*2]
	lea  ecx, [ecx+ecx*8]
	mov  edx, [ebp+a4]
	mov  ?bComboDraw@@3PAY0BC@CA[ecx+edx], al
	cmp  [ebp+a4], 1
	jl  loc_45205A
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, byte ptr (dword_524D2C+3)[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a4]
	mov  edx, [ebp+a3]
	add  edx, edx
	lea  edx, [edx+edx*8]
	mov  byte ptr (dword_524D2C+3)[ecx+edx], al
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	movsx  eax, byte ptr (dword_524D2C+3)[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a3]
	lea  ecx, ds:2[ecx*2]
	lea  ecx, [ecx+ecx*8]
	mov  edx, [ebp+a4]
	mov  byte ptr (dword_524D2C+3)[ecx+edx], al
loc_45205A::
	jmp  loc_4520A9
loc_45205F::
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	cmp  [ebp+a4], 1
	jl  loc_4520A9
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
loc_4520A9::
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 0AAh
	jz  loc_4520D1
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 0ABh
	jnz  loc_4523AE
loc_4520D1::
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?GetCloudLookup@advManager@@QAEHHH@Z
	test  eax, eax
	jz  loc_4522C1
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a3]
	lea  ecx, ds:2[ecx*2]
	lea  ecx, [ecx+ecx*8]
	mov  edx, [ebp+a4]
	mov  ?bComboDraw@@3PAY0BC@CA[ecx+edx], al
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, byte_524D31[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a4]
	mov  edx, [ebp+a3]
	add  edx, edx
	lea  edx, [edx+edx*8]
	mov  byte_524D31[ecx+edx], al
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	movsx  eax, byte_524D31[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a3]
	lea  ecx, ds:2[ecx*2]
	lea  ecx, [ecx+ecx*8]
	mov  edx, [ebp+a4]
	mov  byte_524D31[ecx+edx], al
	mov  eax, [ebp+a3]
	lea  eax, ds:4[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a3]
	lea  ecx, ds:4[ecx*2]
	lea  ecx, [ecx+ecx*8]
	mov  edx, [ebp+a4]
	mov  ?bComboDraw@@3PAY0BC@CA[ecx+edx], al
	cmp  [ebp+a4], 1
	jl  loc_4521F1
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, byte ptr (dword_524D2C+3)[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a4]
	mov  edx, [ebp+a3]
	add  edx, edx
	lea  edx, [edx+edx*8]
	mov  byte ptr (dword_524D2C+3)[ecx+edx], al
loc_4521F1::
	cmp  [ebp+a3], 1
	jl  loc_4522BC
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFEh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a3]
	lea  ecx, ds:0FFFFFFFEh[ecx*2]
	lea  ecx, [ecx+ecx*8]
	mov  edx, [ebp+a4]
	mov  ?bComboDraw@@3PAY0BC@CA[ecx+edx], al
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFEh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	movsx  eax, byte_524D31[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a3]
	lea  ecx, ds:0FFFFFFFEh[ecx*2]
	lea  ecx, [ecx+ecx*8]
	mov  edx, [ebp+a4]
	mov  byte_524D31[ecx+edx], al
	cmp  [ebp+a3], 2
	jl  loc_45229B
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFCh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	add  eax, 0Ah
	mov  ecx, [ebp+a3]
	lea  ecx, ds:0FFFFFFFCh[ecx*2]
	lea  ecx, [ecx+ecx*8]
	mov  edx, [ebp+a4]
	mov  ?bComboDraw@@3PAY0BC@CA[ecx+edx], al
loc_45229B::
	cmp  [ebp+a4], 1
	jl  loc_4522BC
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFCh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
loc_4522BC::
	jmp  loc_4523AE
loc_4522C1::
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte_524D31[eax+ecx]
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte_524D31[eax+ecx]
	mov  eax, [ebp+a3]
	lea  eax, ds:4[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	cmp  [ebp+a4], 1
	jl  loc_452334
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
loc_452334::
	cmp  [ebp+a3], 1
	jl  loc_4523AE
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFEh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFEh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte_524D31[eax+ecx]
	cmp  [ebp+a3], 2
	jl  loc_45238D
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFCh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
loc_45238D::
	cmp  [ebp+a4], 1
	jl  loc_4523AE
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFCh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
loc_4523AE::
	jmp  loc_451E8D
loc_4523B3::
	jmp  loc_451E74
loc_4523B8::
	mov  [ebp+a3], 0
	jmp  loc_4523C7
loc_4523C4::
	inc  [ebp+a3]
loc_4523C7::
	cmp  [ebp+a3], 0Fh
	jge  loc_4524B0
	mov  [ebp+a4], 0
	jmp  loc_4523E0
loc_4523DD::
	inc  [ebp+a4]
loc_4523E0::
	cmp  [ebp+a4], 0Fh
	jge  loc_4524AB
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	test  eax, eax
	jz  loc_4524A6
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	js  loc_452441
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	cmp  eax, ?MAP_WIDTH@@3HA
	jge  loc_452441
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	js  loc_452441
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	cmp  eax, ?MAP_HEIGHT@@3HA
	jl  loc_452459
loc_452441::
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	mov  ?bComboDraw@@3PAY0BC@CA[eax+ecx], 0
	jmp  loc_4524A6
loc_452459::
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	cmp  eax, 0Ah
	jge  loc_4524A6
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?GetCloudLookup@advManager@@QAEHHH@Z
	test  eax, eax
	jnz  loc_4524A6
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	mov  ?bComboDraw@@3PAY0BC@CA[eax+ecx], 0
loc_4524A6::
	jmp  loc_4523DD
loc_4524AB::
	jmp  loc_4523C4
loc_4524B0::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+2A6h], 0
	jz  loc_45250E
	mov  [ebp+a4], 6
	jmp  loc_4524CF
loc_4524CC::
	inc  [ebp+a4]
loc_4524CF::
	cmp  [ebp+a4], 8
	jg  loc_45250E
	mov  [ebp+a3], 5
	jmp  loc_4524E8
loc_4524E5::
	inc  [ebp+a3]
loc_4524E8::
	cmp  [ebp+a3], 9
	jg  loc_452509
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	jmp  loc_4524E5
loc_452509::
	jmp  loc_4524CC
loc_45250E::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+27Ah], 6
	jnz  loc_452530
	inc  byte_524DA1
	inc  byte_524DB3
	inc  byte_524DC5
loc_452530::
	mov  [ebp+a3], 0
	jmp  loc_45253F
loc_45253C::
	inc  [ebp+a3]
loc_45253F::
	cmp  [ebp+a3], 0Fh
	jge  loc_452759
	mov  [ebp+a4], 0
	jmp  loc_452558
loc_452555::
	inc  [ebp+a4]
loc_452558::
	cmp  [ebp+a4], 0Fh
	jge  loc_452754
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?GetCell@advManager@@QAEPAVmapCell@@HH@Z
	mov  [ebp+var_18], eax
	mov  eax, [ebp+var_18]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 97h
	jnz  loc_45274F
	mov  eax, [ebp+var_18]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	lea  ecx, ds:0[eax*8]
	sub  ecx, eax
	mov  eax, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [ecx+eax+5CB9h]
	cmp  eax, 3Bh
	jnz  loc_452718
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	cmp  [ebp+a3], 0Fh
	jge  loc_452608
	mov  eax, [ebp+a3]
	lea  eax, ds:4[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
loc_452608::
	cmp  [ebp+a3], 0
	jle  loc_452629
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFEh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
loc_452629::
	cmp  [ebp+a4], 0
	jle  loc_45269E
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
	cmp  [ebp+a3], 0Fh
	jge  loc_45267D
	mov  eax, [ebp+a3]
	lea  eax, ds:4[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
loc_45267D::
	cmp  [ebp+a3], 0
	jle  loc_45269E
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFEh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
loc_45269E::
	cmp  [ebp+a4], 1
	jle  loc_452713
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	inc  byte ptr (dword_524D2C+2)[eax+ecx]
	mov  eax, [ebp+a3]
	lea  eax, ds:2[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+2)[eax+ecx]
	cmp  [ebp+a3], 0Fh
	jge  loc_4526F2
	mov  eax, [ebp+a3]
	lea  eax, ds:4[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+2)[eax+ecx]
loc_4526F2::
	cmp  [ebp+a3], 0
	jle  loc_452713
	mov  eax, [ebp+a3]
	lea  eax, ds:0FFFFFFFEh[eax*2]
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte ptr (dword_524D2C+2)[eax+ecx]
loc_452713::
	jmp  loc_45274F
loc_452718::
	cmp  [ebp+a4], 0
	jle  loc_45274F
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, byte ptr (dword_524D2C+3)[eax+ecx]
	test  eax, eax
	jz  loc_45274F
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  ?bComboDraw@@3PAY0BC@CA[eax+ecx]
loc_45274F::
	jmp  loc_452555
loc_452754::
	jmp  loc_45253C
loc_452759::
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+0A2h], 0
	jz  loc_452896
	mov  eax, [ebp+this]
	cmp  dword ptr [eax+9Eh], 0
	jz  loc_452896
	mov  [ebp+a4], 1
	jmp  loc_452788
loc_452785::
	inc  [ebp+a4]
loc_452788::
	cmp  [ebp+a4], 0Eh
	jge  loc_452896
	mov  [ebp+a3], 0
	jmp  loc_4527A1
loc_45279E::
	inc  [ebp+a3]
loc_4527A1::
	cmp  [ebp+a3], 0Fh
	jge  loc_452891
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	test  eax, eax
	jnz  loc_4527CB
	jmp  loc_45279E
loc_4527CB::
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	mov  [ebp+var_8], eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	mov  [ebp+var_C], eax
	cmp  [ebp+var_8], 0
	jl  loc_452811
	mov  eax, ?MAP_WIDTH@@3HA
	dec  eax
	cmp  eax, [ebp+var_8]
	jl  loc_452811
	cmp  [ebp+var_C], 1
	jl  loc_452811
	mov  eax, ?MAP_HEIGHT@@3HA
	sub  eax, 2
	cmp  eax, [ebp+var_C]
	jge  loc_452816
loc_452811::
	jmp  loc_45279E
loc_452816::
	mov  eax, ?MAP_WIDTH@@3HA
	imul  eax, [ebp+var_C]
	mov  ecx, [ebp+var_8]
	add  ecx, ecx
	lea  eax, [ecx+eax*2]
	mov  ecx, [ebp+this]
	mov  ecx, [ecx+9Eh]
	xor  edx, edx
	mov  dx, [eax+ecx]
	test  edx, edx
	jz  loc_452850
	mov  eax, [ebp+a3]
	add  eax, eax
	lea  eax, [eax+eax*8]
	mov  ecx, [ebp+a4]
	inc  byte_524D31[eax+ecx]
loc_452850::
	mov  eax, [ebp+var_C]
	dec  eax
	imul  eax, ?MAP_WIDTH@@3HA
	mov  ecx, [ebp+var_8]
	add  ecx, ecx
	lea  eax, [ecx+eax*2]
	mov  ecx, [ebp+this]
	mov  ecx, [ecx+9Eh]
	xor  edx, edx
	mov  dx, [eax+ecx]
	test  edx, edx
	jz  loc_45288C
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	inc  byte ptr (dword_524D2C+3)[eax+ecx]
loc_45288C::
	jmp  loc_45279E
loc_452891::
	jmp  loc_452785
loc_452896::
	mov  eax, ?gpMouseManager@@3PAVmouseManager@@A
	mov  dword ptr [eax+82h], 0
	mov  [ebp+a4], 0
	jmp  loc_4528B4
loc_4528B1::
	inc  [ebp+a4]
loc_4528B4::
	cmp  [ebp+a4], 0Fh
	jge  loc_45291E
	mov  [ebp+a3], 0
	jmp  loc_4528CD
loc_4528CA::
	inc  [ebp+a3]
loc_4528CD::
	cmp  [ebp+a3], 0Fh
	jge  loc_452919
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	test  eax, eax
	jz  loc_452914
	push  0
	push  1
	mov  eax, [ebp+a4]
	push  eax
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452914::
	jmp  loc_4528CA
loc_452919::
	jmp  loc_4528B1
loc_45291E::
	mov  [ebp+a4], 0
	jmp  loc_45292D
loc_45292A::
	inc  [ebp+a4]
loc_45292D::
	cmp  [ebp+a4], 0Fh
	jge  loc_45299A
	mov  [ebp+a3], 0
	jmp  loc_452946
loc_452943::
	inc  [ebp+a3]
loc_452946::
	cmp  [ebp+a3], 0Fh
	jge  loc_452995
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	test  eax, eax
	jz  loc_452990
	push  0
	push  80h
	mov  eax, [ebp+a4]
	push  eax
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452990::
	jmp  loc_452943
loc_452995::
	jmp  loc_45292A
loc_45299A::
	mov  [ebp+a3], 0
	jmp  loc_4529A9
loc_4529A6::
	inc  [ebp+a3]
loc_4529A9::
	cmp  [ebp+a3], 0Fh
	jge  loc_4529EA
	mov  eax, [ebp+a3]
	add  eax, eax
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+eax*8]
	test  eax, eax
	jz  loc_4529E5
	push  0
	push  2
	push  0
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_4529E5::
	jmp  loc_4529A6
loc_4529EA::
	mov  [ebp+a4], 1
	jmp  loc_4529F9
loc_4529F6::
	inc  [ebp+a4]
loc_4529F9::
	cmp  [ebp+a4], 0Fh
	jge  loc_452B96
	call  @PollSound@0
	mov  [ebp+a3], 0
	jmp  loc_452A17
loc_452A14::
	inc  [ebp+a3]
loc_452A17::
	cmp  [ebp+a3], 0Fh
	jge  loc_452A65
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, byte ptr (dword_524D2C+3)[eax+ecx]
	test  eax, eax
	jz  loc_452A60
	push  0
	push  8
	mov  eax, [ebp+a4]
	dec  eax
	push  eax
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	dec  eax
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452A60::
	jmp  loc_452A14
loc_452A65::
	mov  [ebp+a3], 0
	jmp  loc_452A74
loc_452A71::
	inc  [ebp+a3]
loc_452A74::
	cmp  [ebp+a3], 0Fh
	jge  loc_452AC2
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, byte ptr (dword_524D2C+3)[eax+ecx]
	test  eax, eax
	jz  loc_452ABD
	push  0
	push  4
	mov  eax, [ebp+a4]
	dec  eax
	push  eax
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	dec  eax
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452ABD::
	jmp  loc_452A71
loc_452AC2::
	mov  [ebp+a3], 0
	jmp  loc_452AD1
loc_452ACE::
	inc  [ebp+a3]
loc_452AD1::
	cmp  [ebp+a3], 0Fh
	jge  loc_452B91
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	cmp  eax, ?giDeferObjDrawX@@3HA
	jnz  loc_452B04
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	cmp  eax, ?giDeferObjDrawY@@3HA
	jnz  loc_452B04
	jmp  loc_452ACE
loc_452B04::
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	cmp  eax, ?giDeferObjDrawX@@3HA
	jnz  loc_452B4F
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	mov  ecx, ?giDeferObjDrawY@@3HA
	inc  ecx
	cmp  eax, ecx
	jnz  loc_452B4F
	push  0
	push  2
	mov  eax, [ebp+a4]
	dec  eax
	push  eax
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	dec  eax
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452B4F::
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	test  eax, eax
	jz  loc_452B8C
	push  0
	push  2
	mov  eax, [ebp+a4]
	push  eax
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452B8C::
	jmp  loc_452ACE
loc_452B91::
	jmp  loc_4529F6
loc_452B96::
	mov  [ebp+a3], 0
	jmp  loc_452BA5
loc_452BA2::
	inc  [ebp+a3]
loc_452BA5::
	cmp  [ebp+a3], 0Fh
	jge  loc_452BE9
	mov  eax, [ebp+a3]
	add  eax, eax
	movsx  eax, byte_524D3E[eax+eax*8]
	test  eax, eax
	jz  loc_452BE4
	push  0
	push  8
	push  0Eh
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+y]
	add  eax, 0Eh
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452BE4::
	jmp  loc_452BA2
loc_452BE9::
	mov  [ebp+a3], 0
	jmp  loc_452BF8
loc_452BF5::
	inc  [ebp+a3]
loc_452BF8::
	cmp  [ebp+a3], 0Fh
	jge  loc_452C3C
	mov  eax, [ebp+a3]
	add  eax, eax
	movsx  eax, byte_524D3E[eax+eax*8]
	test  eax, eax
	jz  loc_452C37
	push  0
	push  4
	push  0Eh
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+y]
	add  eax, 0Eh
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452C37::
	jmp  loc_452BF5
loc_452C3C::
	mov  [ebp+a4], 0
	jmp  loc_452C4B
loc_452C48::
	inc  [ebp+a4]
loc_452C4B::
	cmp  [ebp+a4], 0Fh
	jge  loc_452CB5
	mov  [ebp+a3], 0
	jmp  loc_452C64
loc_452C61::
	inc  [ebp+a3]
loc_452C64::
	cmp  [ebp+a3], 0Fh
	jge  loc_452CB0
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	test  eax, eax
	jz  loc_452CAB
	push  0
	push  40h
	mov  eax, [ebp+a4]
	push  eax
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452CAB::
	jmp  loc_452C61
loc_452CB0::
	jmp  loc_452C48
loc_452CB5::
	mov  [ebp+a4], 0
	jmp  loc_452CC4
loc_452CC1::
	inc  [ebp+a4]
loc_452CC4::
	cmp  [ebp+a4], 0Fh
	jge  loc_452D2E
	mov  [ebp+a3], 0
	jmp  loc_452CDD
loc_452CDA::
	inc  [ebp+a3]
loc_452CDD::
	cmp  [ebp+a3], 0Fh
	jge  loc_452D29
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	test  eax, eax
	jz  loc_452D24
	push  0
	push  20h
	mov  eax, [ebp+a4]
	push  eax
	mov  eax, [ebp+a3]
	push  eax
	mov  eax, [ebp+a4]
	add  eax, [ebp+y]
	push  eax
	mov  eax, [ebp+a3]
	add  eax, [ebp+left]
	push  eax
	mov  ecx, [ebp+this]
	call  ?DrawCell@advManager@@QAEXHHHHHH@Z
loc_452D24::
	jmp  loc_452CDA
loc_452D29::
	jmp  loc_452CC1
loc_452D2E::
	mov  ecx, [ebp+this]
	call  ?DrawAdventureBorder@advManager@@QAEXXZ
	mov  eax, ?gpMouseManager@@3PAVmouseManager@@A
	mov  dword ptr [eax+82h], 1
	call  @PollSound@0
	push  1
	push  1
	push  0
	mov  ecx, [ebp+this]
	call  ?UpdBottomView@advManager@@QAEXHHH@Z
	mov  ?giLimitUpdMinX@@3HA, 0Fh
	mov  ?giLimitUpdMinY@@3HA, 0Fh
	mov  ?giLimitUpdMaxX@@3HA, 0
	mov  ?giLimitUpdMaxY@@3HA, 0
	mov  [ebp+var_4], 0
	mov  [ebp+a4], 0
	jmp  loc_452D96
loc_452D93::
	inc  [ebp+a4]
loc_452D96::
	cmp  [ebp+a4], 0Fh
	jge  loc_452E3C
	mov  [ebp+a3], 0
	jmp  loc_452DAF
loc_452DAC::
	inc  [ebp+a3]
loc_452DAF::
	cmp  [ebp+a3], 0Fh
	jge  loc_452E37
	mov  eax, [ebp+a4]
	mov  ecx, [ebp+a3]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*8]
	movsx  eax, ?bComboDraw@@3PAY0BC@CA[eax+ecx]
	test  eax, eax
	jz  loc_452E32
	inc  [ebp+var_4]
	mov  eax, [ebp+a3]
	cmp  ?giLimitUpdMinX@@3HA, eax
	jle  loc_452DEE
	mov  eax, [ebp+a3]
	mov  ?giLimitUpdMinX@@3HA, eax
loc_452DEE::
	mov  eax, ?giLimitUpdMaxX@@3HA
	cmp  [ebp+a3], eax
	jle  loc_452E04
	mov  eax, [ebp+a3]
	mov  ?giLimitUpdMaxX@@3HA, eax
loc_452E04::
	mov  eax, [ebp+a4]
	cmp  ?giLimitUpdMinY@@3HA, eax
	jle  loc_452E1B
	mov  eax, [ebp+a4]
	mov  ?giLimitUpdMinY@@3HA, eax
loc_452E1B::
	mov  eax, [ebp+a4]
	cmp  ?giLimitUpdMaxY@@3HA, eax
	jge  loc_452E32
	mov  eax, [ebp+a4]
	mov  ?giLimitUpdMaxY@@3HA, eax
loc_452E32::
	jmp  loc_452DAC
loc_452E37::
	jmp  loc_452D93
loc_452E3C::
	shl  ?giLimitUpdMinX@@3HA, 5
	shl  ?giLimitUpdMinY@@3HA, 5
	mov  eax, ?giLimitUpdMaxX@@3HA
	inc  eax
	shl  eax, 5
	dec  eax
	mov  ?giLimitUpdMaxX@@3HA, eax
	mov  eax, ?giLimitUpdMaxY@@3HA
	inc  eax
	shl  eax, 5
	dec  eax
	mov  ?giLimitUpdMaxY@@3HA, eax
	cmp  ?giLimitUpdMinX@@3HA, 10h
	jge  loc_452E7F
	mov  ?giLimitUpdMinX@@3HA, 10h
loc_452E7F::
	cmp  ?giLimitUpdMaxX@@3HA, 1CFh
	jle  loc_452E99
	mov  ?giLimitUpdMaxX@@3HA, 1CFh
loc_452E99::
	cmp  ?giLimitUpdMinY@@3HA, 10h
	jge  loc_452EB0
	mov  ?giLimitUpdMinY@@3HA, 10h
loc_452EB0::
	cmp  ?giLimitUpdMaxY@@3HA, 1CFh
	jle  loc_452ECA
	mov  ?giLimitUpdMaxY@@3HA, 1CFh
loc_452ECA::
	mov  eax, ?giLimitUpdMaxX@@3HA
	cmp  ?giLimitUpdMinX@@3HA, eax
	jg  loc_452EEC
	mov  eax, ?giLimitUpdMinY@@3HA
	cmp  ?giLimitUpdMaxY@@3HA, eax
	jge  loc_452F09
loc_452EEC::
	mov  eax, ?giLimitUpdMaxX@@3HA
	dec  eax
	mov  ?giLimitUpdMinX@@3HA, eax
	mov  eax, ?giLimitUpdMaxY@@3HA
	dec  eax
	mov  ?giLimitUpdMinY@@3HA, eax
	xor  eax, eax
	jmp  loc_452F13
loc_452F09::
	mov  eax, 1
	jmp  NEAR32 PTR $+5
loc_452F13::
	pop  edi
	pop  esi
	pop  ebx
	leave  
	retn  0Ch
?ComboDraw@advManager@@QAEHHHH@Z endp
