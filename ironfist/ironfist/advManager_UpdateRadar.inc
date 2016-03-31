                align 10h
IFDEF IMPORT_?UpdateRadar@advManager@@QAEXHH@Z
?UpdateRadar@advManager@@QAEXHH@Z PROTO SYSCALL
ELSE
?UpdateRadar@advManager@@QAEXHH@Z proc near SYSCALL


var_B4		= dword ptr -180
var_B0		= dword ptr -176
var_AC		= dword ptr -172
var_A8		= dword ptr -168
var_A4		= dword ptr -164
var_A0		= dword ptr -160
var_9C		= dword ptr -156
var_98		= dword ptr -152
var_94		= dword ptr -148
var_90		= dword ptr -144
var_8C		= dword ptr -140
var_88		= dword ptr -136
var_84		= dword ptr -132
var_80		= dword ptr -128
var_7C		= dword ptr -124
var_78		= dword ptr -120
var_74		= dword ptr -116
var_70		= dword ptr -112
var_6C		= dword ptr -108
var_68		= dword ptr -104
var_64		= dword ptr -100
var_60		= dword ptr -96
var_5C		= dword ptr -92
var_58		= dword ptr -88
var_54		= dword ptr -84
var_4C		= dword ptr -76
var_48		= dword ptr -72
var_44		= dword ptr -68
var_40		= dword ptr -64
var_38		= dword ptr -56
var_34		= dword ptr -52
var_30		= dword ptr -48
a4		= dword ptr -44
var_24		= dword ptr -36
var_20		= dword ptr -32
var_1C		= dword ptr -28
var_14		= dword ptr -20
var_10		= byte ptr -16
var_C		= dword ptr -12
var_8		= dword ptr -8
var_4		= dword ptr -4
arg_0		= dword ptr 8
arg_4		= dword ptr 12
 

	push  ebp
	mov  ebp, esp
	sub  esp, 0B4h
	push  ebx
	push  esi
	push  edi
	mov  [ebp+var_74], ecx
	mov  [ebp+var_10], 24h
	cmp  [ebp+arg_4], 0
	jnz  loc_44AAC2
	mov  [ebp+var_20], 0
	mov  [ebp+var_38], 0
	mov  eax, ?MAP_WIDTH@@3HA
	dec  eax
	mov  [ebp+var_1C], eax
	mov  eax, ?MAP_HEIGHT@@3HA
	dec  eax
	mov  [ebp+var_34], eax
	jmp  loc_44AB50
loc_44AAC2::
	mov  eax, [ebp+var_74]
	mov  eax, [eax+1D6h]
	sub  eax, 2
	mov  [ebp+var_20], eax
	mov  eax, [ebp+var_74]
	mov  eax, [eax+1DAh]
	sub  eax, 2
	mov  [ebp+var_38], eax
	mov  eax, [ebp+var_74]
	mov  eax, [eax+1D6h]
	add  eax, 10h
	mov  [ebp+var_1C], eax
	mov  eax, [ebp+var_74]
	mov  eax, [eax+1DAh]
	add  eax, 10h
	mov  [ebp+var_34], eax
	cmp  [ebp+var_20], 0
	jge  loc_44AB0F
	mov  [ebp+var_20], 0
loc_44AB0F::
	cmp  [ebp+var_38], 0
	jge  loc_44AB20
	mov  [ebp+var_38], 0
loc_44AB20::
	mov  eax, ?MAP_WIDTH@@3HA
	dec  eax
	cmp  eax, [ebp+var_1C]
	jge  loc_44AB38
	mov  eax, ?MAP_WIDTH@@3HA
	dec  eax
	mov  [ebp+var_1C], eax
loc_44AB38::
	mov  eax, ?MAP_HEIGHT@@3HA
	dec  eax
	cmp  eax, [ebp+var_34]
	jge  loc_44AB50
	mov  eax, ?MAP_HEIGHT@@3HA
	dec  eax
	mov  [ebp+var_34], eax
loc_44AB50::
	mov  eax, ?giCurPlayer@@3HA
	movsx  eax, ?gbThisNetHumanPlayer@@3PACA[eax]
	test  eax, eax
	jnz  loc_44AB69
	jmp  loc_44BAC6
loc_44AB69::
	mov  eax, ?gpAdvManager@@3PAVadvManager@@A
	mov  dword ptr [eax+37Ah], 0
	mov  [ebp+var_8], 0
	mov  eax, [ebp+var_8]
	mov  [ebp+var_C], eax
	mov  eax, ?MAP_HEIGHT@@3HA
	mov  [ebp+var_78], eax
	jmp  loc_44AC83
loc_44AB92::
	mov  eax, [ebp+var_38]
	shl  eax, 2
	lea  eax, [eax+eax*4+50h]
	shl  eax, 7
	mov  ecx, ?gpWindowManager@@3PAVheroWindowManager@@A
	mov  ecx, [ecx+46h]
	add  eax, [ecx+16h]
	add  eax, 280h		;;1E0h
	mov  [ebp+var_4], eax
	mov  eax, [ebp+var_20]
	shl  eax, 2
	mov  [ebp+var_54], eax
	jmp  loc_44ACA6
loc_44ABC1::
	mov  eax, ?gpWindowManager@@3PAVheroWindowManager@@A
	mov  eax, [eax+46h]
	mov  eax, [eax+16h]
	mov  ecx, [ebp+var_38]
	add  ecx, ecx
	lea  ecx, [ecx+ecx*4+50h]
	shl  ecx, 7
	add  eax, ecx
	add  eax, 280h		;;1E0h
	mov  [ebp+var_4], eax
	mov  eax, [ebp+var_20]
	add  eax, eax
	mov  [ebp+var_54], eax
	jmp  loc_44ACA6
loc_44ABEF::
	mov  eax, [ebp+var_38]
	mov  ecx, 3
	add  eax, 2
	cdq  
	idiv  ecx
	mov  ecx, [ebp+var_38]
	add  ecx, eax
	lea  ecx, [ecx+ecx*4+50h]
	shl  ecx, 7
	mov  eax, ?gpWindowManager@@3PAVheroWindowManager@@A
	mov  eax, [eax+46h]
	add  ecx, [eax+16h]
	add  ecx, 280h		;;1E0h
	mov  [ebp+var_4], ecx
	mov  eax, [ebp+var_20]
	mov  ecx, 3
	add  eax, 2
	cdq  
	idiv  ecx
	mov  ecx, [ebp+var_20]
	add  ecx, eax
	mov  [ebp+var_54], ecx
	mov  ecx, 3
	mov  eax, [ebp+var_20]
	cdq  
	idiv  ecx
	mov  [ebp+var_C], edx
	mov  ecx, 3
	mov  eax, [ebp+var_38]
	cdq  
	idiv  ecx
	mov  [ebp+var_8], edx
	jmp  loc_44ACA6
loc_44AC54::
	mov  eax, ?gpWindowManager@@3PAVheroWindowManager@@A
	mov  eax, [eax+46h]
	mov  eax, [eax+16h]
	mov  ecx, [ebp+var_38]
	lea  ecx, [ecx+ecx*4+50h]
	shl  ecx, 7
	add  eax, ecx
	add  eax, 280h		;;1E0h
	mov  [ebp+var_4], eax
	mov  eax, [ebp+var_20]
	mov  [ebp+var_54], eax
	jmp  loc_44ACA6
	jmp  loc_44ACA6
loc_44AC83::
	cmp  [ebp+var_78], 24h
	jz  loc_44AB92
	cmp  [ebp+var_78], 48h
	jz  loc_44ABC1
	cmp  [ebp+var_78], 6Ch
	jz  loc_44ABEF
	jmp  loc_44AC54
loc_44ACA6::
	mov  eax, [ebp+var_38]
	mov  [ebp+var_40], eax
	jmp  loc_44ACB4
loc_44ACB1::
	inc  [ebp+var_40]
loc_44ACB4::
	mov  eax, [ebp+var_40]
	cmp  [ebp+var_34], eax
	jl  loc_44B759
	mov  eax, [ebp+var_54]
	add  eax, [ebp+var_4]
	mov  [ebp+var_14], eax
	mov  eax, ?MAP_HEIGHT@@3HA
	mov  [ebp+var_7C], eax
	jmp  loc_44AD35
loc_44ACD6::
	add  [ebp+var_4], 0A00h
	jmp  loc_44ADD6
loc_44ACE2::
	add  [ebp+var_4], 640h		;;500h
	jmp  loc_44ADD6
loc_44ACEE::
	inc  [ebp+var_8]
	cmp  [ebp+var_8], 2
	jle  loc_44AD02
	mov  [ebp+var_8], 0
loc_44AD02::
	cmp  [ebp+var_8], 0
	jz  loc_44AD18
	add  [ebp+var_4], 320h		;;280h
	jmp  loc_44AD1F
loc_44AD18::
	add  [ebp+var_4], 640h		;;500h
loc_44AD1F::
	jmp  loc_44ADD6
loc_44AD24::
	add  [ebp+var_4], 320h		;;280h
	jmp  loc_44ADD6
	jmp  loc_44ADD6
loc_44AD35::
	sub  [ebp+var_7C], 24h
	cmp  [ebp+var_7C], 6Ch
	ja  loc_44ADD6
	mov  eax, [ebp+var_7C]
	xor  ecx, ecx
	mov  cl, ds:byte_44AD69[eax]
	jmp  ds:off_44AD55[ecx*4]
IFDEF IMPORT_off_44AD55
extern off_44AD55 : dword
ELSE
off_44AD55      dd offset loc_44ACD6, offset loc_44ACE2, offset loc_44ACEE
                dd offset loc_44AD24, offset loc_44ADD6 ; jump table for switch statement
ENDIF
IFDEF IMPORT_byte_44AD69
extern byte_44AD69 : dword
ELSE
byte_44AD69     db      0,     4,     4,     4
                db      4,     4,     4,     4 ; indirect table for switch statement
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      1,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      2,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      3
ENDIF
loc_44ADD6::
	mov  eax, [ebp+var_20]
	mov  [ebp+var_24], eax
	jmp  loc_44ADE4
loc_44ADE1::
	inc  [ebp+var_24]
loc_44ADE4::
	mov  eax, [ebp+var_1C]
	cmp  [ebp+var_24], eax
	jg  loc_44B754
	cmp  ?gbAllBlack@@3HA, 0
	jnz  loc_44AE24
	mov  eax, [ebp+var_40]
	imul  eax, ?MAP_WIDTH@@3HA
	add  eax, [ebp+var_24]
	mov  ecx, ?mapRevealed@@3PAEA
	xor  edx, edx
	mov  dl, [eax+ecx]
	xor  eax, eax
	mov  al, ?giCurPlayerBit@@3EA
	test  eax, edx
	jnz  loc_44AE2D
loc_44AE24::
	mov  [ebp+var_10], 24h
	jmp  loc_44B538
loc_44AE2D::
	jmp  NEAR32 PTR $+5
loc_44AE32::
	mov  eax, [ebp+var_74]
	mov  eax, [eax+0AEh]
	mov  eax, [eax+8]
	imul  eax, [ebp+var_40]
	lea  eax, [eax+eax*2]
	shl  eax, 2
	mov  ecx, [ebp+var_74]
	mov  ecx, [ecx+0AEh]
	add  eax, [ecx]
	mov  ecx, [ebp+var_24]
	lea  ecx, [ecx+ecx*2]
	lea  eax, [eax+ecx*4]
	mov  [ebp+var_58], eax
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cl, [eax+8]
	test  cl, 40h
	jz  loc_44AECA
	mov  eax, [ebp+var_74]
	mov  eax, [eax+1D6h]
	add  eax, 7
	cmp  eax, [ebp+var_24]
	jnz  loc_44AECA
	mov  eax, [ebp+var_74]
	mov  eax, [eax+1DAh]
	add  eax, 7
	cmp  eax, [ebp+var_40]
	jnz  loc_44AECA
	mov  eax, ?giCurPlayer@@3HA
	mov  ecx, eax
	shl  eax, 3
	lea  eax, [eax+eax*8]
	sub  eax, ecx
	shl  eax, 2
	sub  eax, ecx
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [eax+ecx+49Ch]
	mov  al, byte_4F0A48[eax]
	mov  [ebp+var_10], al
	jmp  loc_44B538
loc_44AECA::
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cl, [eax+9]
	and  cl, 7Fh
	cmp  cl, 2Ah
	jnz  loc_44AF58
	mov  eax, [ebp+var_58]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [ecx+eax+5C80h]
	mov  [ebp+var_5C], eax
	mov  eax, [ebp+var_5C]
	cmp  ?giCurPlayer@@3HA, eax
	jnz  loc_44AF53
	cmp  [ebp+var_5C], 0
	jl  loc_44AF40
	mov  eax, [ebp+var_5C]
	mov  ecx, eax
	shl  eax, 3
	lea  eax, [eax+eax*8]
	sub  eax, ecx
	shl  eax, 2
	sub  eax, ecx
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [eax+ecx+49Ch]
	mov  [ebp+var_64], eax
	jmp  loc_44AF47
loc_44AF40::
	mov  [ebp+var_64], 6
loc_44AF47::
	mov  eax, [ebp+var_64]
	mov  al, byte_4F0A48[eax]
	mov  [ebp+var_10], al
loc_44AF53::
	jmp  loc_44B538
loc_44AF58::
	mov  [ebp+var_60], 0FFFFFFFFh
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cl, [eax+3]
	cmp  ecx, 0FFh
	jz  loc_44AF8D
	mov  eax, [ebp+var_58]
	mov  al, [eax+2]
	shr  al, 2
	and  ax, 3Fh
	and  eax, 0FFFFh
	mov  [ebp+var_60], eax
	jmp  loc_44AFB6
loc_44AF8D::
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cl, [eax+7]
	cmp  ecx, 0FFh
	jz  loc_44AFB6
	mov  eax, [ebp+var_58]
	mov  al, [eax+6]
	shr  al, 2
	and  ax, 3Fh
	and  eax, 0FFFFh
	mov  [ebp+var_60], eax
loc_44AFB6::
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 23h
	jz  loc_44B068
	cmp  [ebp+var_60], 0Eh
	jnz  loc_44B029
	cmp  [ebp+var_24], 0
	jle  loc_44B029
	mov  eax, ?MAP_WIDTH@@3HA
	dec  eax
	cmp  eax, [ebp+var_24]
	jle  loc_44B029
	jmp  NEAR32 PTR $+5
loc_44AFEF::
	mov  eax, [ebp+var_74]
	mov  eax, [eax+0AEh]
	mov  eax, [eax+8]
	imul  eax, [ebp+var_40]
	lea  eax, [eax+eax*2]
	shl  eax, 2
	mov  ecx, [ebp+var_74]
	mov  ecx, [ecx+0AEh]
	add  eax, [ecx]
	mov  ecx, [ebp+var_24]
	lea  ecx, [ecx+ecx*2-3]
	xor  edx, edx
	mov  dl, [eax+ecx*4+9]
	cmp  edx, 0A3h
	jz  loc_44B068
loc_44B029::
	jmp  NEAR32 PTR $+5
loc_44B02E::
	mov  eax, [ebp+var_74]
	mov  eax, [eax+0AEh]
	mov  eax, [eax+8]
	imul  eax, [ebp+var_40]
	lea  eax, [eax+eax*2]
	shl  eax, 2
	mov  ecx, [ebp+var_74]
	mov  ecx, [ecx+0AEh]
	add  eax, [ecx]
	mov  ecx, [ebp+var_24]
	lea  ecx, [ecx+ecx*2+3]
	xor  edx, edx
	mov  dl, [eax+ecx*4+9]
	cmp  edx, 0A3h
	jnz  loc_44B06F
loc_44B068::
	mov  [ebp+var_60], 23h
loc_44B06F::
	cmp  [ebp+var_60], 3Eh
	jnz  loc_44B0AD
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cl, [eax+9]
	cmp  ecx, 67h
	jnz  loc_44B0AD
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cx, [eax]
	xor  eax, eax
	mov  al, ?giGroundToTerrain@@3PAEA[ecx]
	xor  ecx, ecx
	mov  cl, byte_4F0A28[eax]
	add  ecx, 3
	mov  [ebp+var_10], cl
	jmp  loc_44B538
loc_44B0AD::
	mov  eax, [ebp+var_60]
	mov  [ebp+var_80], eax
	jmp  loc_44B4E4
loc_44B0B8::
	mov  eax, [ebp+var_58]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [ecx+eax+2773h]
	mov  [ebp+var_5C], eax
	jmp  NEAR32 PTR $+5
loc_44B0DE::
	mov  eax, [ebp+var_58]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	shl  eax, 2
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	mov  ecx, ?gpGame@@3PAVgame@@A
	xor  edx, edx
	mov  dl, [eax+ecx+0B57h]
	mov  [ebp+var_30], edx
	jmp  NEAR32 PTR $+5
loc_44B10E::
	mov  eax, [ebp+var_58]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	shl  eax, 2
	lea  eax, [eax+eax*4]
	lea  eax, [eax+eax*4]
	mov  ecx, ?gpGame@@3PAVgame@@A
	xor  edx, edx
	mov  dl, [eax+ecx+0B58h]
	mov  [ebp+var_48], edx
	cmp  [ebp+var_5C], 0
	jl  loc_44B16B
	mov  eax, [ebp+var_5C]
	mov  ecx, eax
	shl  eax, 3
	lea  eax, [eax+eax*8]
	sub  eax, ecx
	shl  eax, 2
	sub  eax, ecx
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [eax+ecx+49Ch]
	mov  [ebp+var_68], eax
	jmp  loc_44B172
loc_44B16B::
	mov  [ebp+var_68], 6
loc_44B172::
	mov  eax, [ebp+var_68]
	mov  al, byte_4F0A48[eax]
	mov  [ebp+var_10], al
	mov  eax, [ebp+var_48]
	sub  eax, 2
	cmp  eax, [ebp+var_40]
	jg  loc_44B1B7
	mov  eax, [ebp+var_48]
	cmp  [ebp+var_40], eax
	jg  loc_44B1B7
	mov  eax, [ebp+var_30]
	sub  eax, 2
	cmp  eax, [ebp+var_24]
	jg  loc_44B1B7
	mov  eax, [ebp+var_30]
	add  eax, 2
	cmp  eax, [ebp+var_24]
	jge  loc_44B1C1
loc_44B1B7::
	jmp  loc_44BAC1
	jmp  loc_44B355
loc_44B1C1::
	jmp  loc_44B538
loc_44B1C6::
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cl, [eax+9]
	mov  [ebp+var_84], ecx
	jmp  loc_44B26C
loc_44B1D9::
	mov  eax, [ebp+var_58]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [ecx+eax+60A6h]
	mov  [ebp+var_5C], eax
	cmp  [ebp+var_5C], 0
	jl  loc_44B22C
	mov  eax, [ebp+var_5C]
	mov  ecx, eax
	shl  eax, 3
	lea  eax, [eax+eax*8]
	sub  eax, ecx
	shl  eax, 2
	sub  eax, ecx
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [eax+ecx+49Ch]
	mov  [ebp+var_6C], eax
	jmp  loc_44B233
loc_44B22C::
	mov  [ebp+var_6C], 6
loc_44B233::
	mov  eax, [ebp+var_6C]
	mov  al, byte_4F0A48[eax]
	mov  [ebp+var_10], al
	jmp  loc_44B350
loc_44B244::
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cx, [eax]
	xor  eax, eax
	mov  al, ?giGroundToTerrain@@3PAEA[ecx]
	xor  ecx, ecx
	mov  cl, byte_4F0A28[eax]
	add  ecx, 3
	mov  [ebp+var_10], cl
	jmp  loc_44B350
	jmp  loc_44B350
loc_44B26C::
	dec  [ebp+var_84]
	cmp  [ebp+var_84], 9Ch
	ja  loc_44B244
	mov  eax, [ebp+var_84]
	xor  ecx, ecx
	mov  cl, ds:byte_44B2B3[eax]
	jmp  ds:off_44B297[ecx*4]
IFDEF IMPORT_off_44B297
extern off_44B297 : dword
ELSE
off_44B297      dd offset loc_44B1D9, offset loc_44B1D9, offset loc_44B1D9
                dd offset loc_44B1D9, offset loc_44B1D9, offset loc_44B1D9 ; jump table for switch statement
                dd offset loc_44B244
ENDIF
IFDEF IMPORT_byte_44B2B3
extern byte_44B2B3 : dword
ELSE
byte_44B2B3     db      0,     6,     6,     6
                db      6,     6,     6,     6 ; indirect table for switch statement
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     1,     6
                db      6,     6,     6,     6
                db      2,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      3,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     4,     6
                db      6,     6,     6,     6
                db      5
ENDIF
loc_44B350::
	jmp  loc_44B538
loc_44B355::
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cl, [eax+9]
	mov  [ebp+var_88], ecx
	jmp  loc_44B3F6
loc_44B368::
	mov  eax, [ebp+var_58]
	mov  ax, [eax+4]
	shr  ax, 3
	and  eax, 1FFFh
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [ecx+eax+60A6h]
	mov  [ebp+var_5C], eax
	cmp  [ebp+var_5C], 0
	jl  loc_44B3BB
	mov  eax, [ebp+var_5C]
	mov  ecx, eax
	shl  eax, 3
	lea  eax, [eax+eax*8]
	sub  eax, ecx
	shl  eax, 2
	sub  eax, ecx
	mov  ecx, ?gpGame@@3PAVgame@@A
	movsx  eax, byte ptr [eax+ecx+49Ch]
	mov  [ebp+var_70], eax
	jmp  loc_44B3C2
loc_44B3BB::
	mov  [ebp+var_70], 6
loc_44B3C2::
	mov  eax, [ebp+var_70]
	mov  al, byte_4F0A48[eax]
	mov  [ebp+var_10], al
	jmp  loc_44B4DA
loc_44B3D3::
	mov  eax, [ebp+var_58]
	xor  ecx, ecx
	mov  cx, [eax]
	xor  eax, eax
	mov  al, ?giGroundToTerrain@@3PAEA[ecx]
	mov  al, byte_4F0A28[eax]
	mov  [ebp+var_10], al
	jmp  loc_44B4DA
	jmp  loc_44B4DA
loc_44B3F6::
	dec  [ebp+var_88]
	cmp  [ebp+var_88], 9Ch
	ja  loc_44B3D3
	mov  eax, [ebp+var_88]
	xor  ecx, ecx
	mov  cl, ds:byte_44B43D[eax]
	jmp  ds:off_44B421[ecx*4]
IFDEF IMPORT_off_44B421
extern off_44B421 : dword
ELSE
off_44B421      dd offset loc_44B368, offset loc_44B368, offset loc_44B368
                dd offset loc_44B368, offset loc_44B368, offset loc_44B368 ; jump table for switch statement
                dd offset loc_44B3D3
ENDIF
IFDEF IMPORT_byte_44B43D
extern byte_44B43D : dword
ELSE
byte_44B43D     db      0,     6,     6,     6
                db      6,     6,     6,     6 ; indirect table for switch statement
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     1,     6
                db      6,     6,     6,     6
                db      2,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      3,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     6,     6
                db      6,     6,     4,     6
                db      6,     6,     6,     6
                db      5
ENDIF
loc_44B4DA::
	jmp  loc_44B538
	jmp  loc_44B538
loc_44B4E4::
	sub  [ebp+var_80], 16h
	cmp  [ebp+var_80], 1Bh
	ja  loc_44B355
	mov  eax, [ebp+var_80]
	xor  ecx, ecx
	mov  cl, ds:byte_44B51C[eax]
	jmp  ds:off_44B504[ecx*4]
IFDEF IMPORT_off_44B504
extern off_44B504 : dword
ELSE
off_44B504      dd offset loc_44B1C6    ; DATA XREF: advManager__UpdateRadar(int,int)+A7Dr
                dd offset loc_44B1C6    ; jump table for switch statement
                dd offset loc_44B0B8
                dd offset loc_44B1C6
                dd offset loc_44B1C6
                dd offset loc_44B355
ENDIF
IFDEF IMPORT_byte_44B51C
extern byte_44B51C : dword
ELSE
byte_44B51C     db      0,     0,     0,     0
                db      0,     0,     5,     5 ; indirect table for switch statement
                db      5,     1,     1,     1
                db      1,     2,     2,     5
                db      5,     5,     5,     5
                db      3,     3,     3,     5
                db      5,     5,     5,     4
ENDIF
loc_44B538::
	mov  eax, ?MAP_HEIGHT@@3HA
	mov  [ebp+var_8C], eax
	jmp  loc_44B6A5
loc_44B548::
	push  4
	xor  eax, eax
	mov  al, [ebp+var_10]
	push  eax
	mov  eax, [ebp+var_14]
	push  eax
	call  _memset
	add  esp, 0Ch
	push  4
	xor  eax, eax
	mov  al, [ebp+var_10]
	push  eax
	mov  eax, [ebp+var_14]
	add  eax, 320h		;;280h
	push  eax
	call  _memset
	add  esp, 0Ch
	push  4
	xor  eax, eax
	mov  al, [ebp+var_10]
	push  eax
	mov  eax, [ebp+var_14]
	add  eax, 640h		;;500h
	push  eax
	call  _memset
	add  esp, 0Ch
	push  4
	xor  eax, eax
	mov  al, [ebp+var_10]
	push  eax
	mov  eax, [ebp+var_14]
	add  eax, 780h
	push  eax
	call  _memset
	add  esp, 0Ch
	add  [ebp+var_14], 4
	jmp  loc_44B74F
loc_44B5B0::
	push  2
	xor  eax, eax
	mov  al, [ebp+var_10]
	push  eax
	mov  eax, [ebp+var_14]
	push  eax
	call  _memset
	add  esp, 0Ch
	push  2
	xor  eax, eax
	mov  al, [ebp+var_10]
	push  eax
	mov  eax, [ebp+var_14]
	add  eax,  320h		;;280h
	push  eax
	call  _memset
	add  esp, 0Ch
	add  [ebp+var_14], 2
	jmp  loc_44B74F
loc_44B5E6::
	cmp  [ebp+var_C], 0
	jz  loc_44B626
	cmp  [ebp+var_8], 0
	jz  loc_44B60A
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx], al
	inc  [ebp+var_14]
	jmp  loc_44B621
loc_44B60A::
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx], al
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx+280h], al
	inc  [ebp+var_14]
loc_44B621::
	jmp  loc_44B677
loc_44B626::
	cmp  [ebp+var_8], 0
	jz  loc_44B64A
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx], al
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx+1], al
	add  [ebp+var_14], 2
	jmp  loc_44B677
loc_44B64A::
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx], al
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx+1], al
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx+280h], al
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx+281h], al
	add  [ebp+var_14], 2
loc_44B677::
	inc  [ebp+var_C]
	cmp  [ebp+var_C], 2
	jle  loc_44B68B
	mov  [ebp+var_C], 0
loc_44B68B::
	jmp  loc_44B74F
loc_44B690::
	mov  al, [ebp+var_10]
	mov  ecx, [ebp+var_14]
	mov  [ecx], al
	inc  [ebp+var_14]
	jmp  loc_44B74F
	jmp  loc_44B74F
loc_44B6A5::
	sub  [ebp+var_8C], 24h
	cmp  [ebp+var_8C], 6Ch
	ja  loc_44B74F
	mov  eax, [ebp+var_8C]
	xor  ecx, ecx
	mov  cl, ds:byte_44B6E2[eax]
	jmp  ds:off_44B6CE[ecx*4]
IFDEF IMPORT_off_44B6CE
extern off_44B6CE : dword
ELSE
off_44B6CE      dd offset loc_44B548, offset loc_44B5B0, offset loc_44B5E6
                dd offset loc_44B690, offset loc_44B74F ; jump table for switch statement
ENDIF
IFDEF IMPORT_byte_44B6E2
extern byte_44B6E2 : dword
ELSE
byte_44B6E2     db      0,     4,     4,     4
                db      4,     4,     4,     4 ; indirect table for switch statement
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      1,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      2,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      4,     4,     4,     4
                db      3
ENDIF
loc_44B74F::
	jmp  loc_44ADE1
loc_44B754::
	jmp  loc_44ACB1
loc_44B759::
	mov  [ebp+a4], 0FFFFFFFFh
	mov  [ebp+var_44], 0
	cmp  ?gbInViewWorld@@3HA, 0
	jz  loc_44B883
	mov  eax, ?MAP_HEIGHT@@3HA
	mov  [ebp+var_90], eax
	jmp  loc_44B852
loc_44B784::
	mov  [ebp+var_4C], 40800000h
	mov  [ebp+var_44], 1
	jmp  loc_44B87E
loc_44B797::
	mov  [ebp+var_4C], 40000000h
	cmp  ?giViewWorldScale@@3HA, 6
	jg  loc_44B7B7
	mov  [ebp+var_44], 1
	jmp  loc_44B7BE
loc_44B7B7::
	mov  [ebp+a4], 6
loc_44B7BE::
	jmp  loc_44B87E
loc_44B7C3::
	mov  [ebp+var_4C], 3FAA3D71h
	cmp  ?giViewWorldScale@@3HA, 4
	jg  loc_44B7E3
	mov  [ebp+var_44], 1
	jmp  loc_44B803
loc_44B7E3::
	cmp  ?giViewWorldScale@@3HA, 6
	jnz  loc_44B7FC
	mov  [ebp+a4], 9
	jmp  loc_44B803
loc_44B7FC::
	mov  [ebp+a4], 8
loc_44B803::
	jmp  loc_44B87E
loc_44B808::
	mov  [ebp+var_4C], 3F800000h
	cmp  ?giViewWorldScale@@3HA, 4
	jnz  loc_44B828
	mov  [ebp+a4], 7
	jmp  loc_44B848
loc_44B828::
	cmp  ?giViewWorldScale@@3HA, 6
	jnz  loc_44B841
	mov  [ebp+a4], 6
	jmp  loc_44B848
loc_44B841::
	mov  [ebp+a4], 4
loc_44B848::
	jmp  loc_44B87E
	jmp  loc_44B87E
loc_44B852::
	cmp  [ebp+var_90], 24h
	jz  loc_44B784
	cmp  [ebp+var_90], 48h
	jz  loc_44B797
	cmp  [ebp+var_90], 6Ch
	jz  loc_44B7C3
	jmp  loc_44B808
loc_44B87E::
	jmp  loc_44B910
loc_44B883::
	mov  eax, ?MAP_HEIGHT@@3HA
	mov  [ebp+var_94], eax
	jmp  loc_44B8E4
loc_44B893::
	mov  [ebp+a4], 5
	mov  [ebp+var_4C], 40800000h
	jmp  loc_44B910
loc_44B8A6::
	mov  [ebp+a4], 3
	mov  [ebp+var_4C], 40000000h
	jmp  loc_44B910
loc_44B8B9::
	mov  [ebp+a4], 2
	mov  [ebp+var_4C], 3FAA3D71h
	jmp  loc_44B910
loc_44B8CC::
	mov  [ebp+a4], 1
	mov  [ebp+var_4C], 3F800000h
	jmp  loc_44B910
	jmp  loc_44B910
loc_44B8E4::
	cmp  [ebp+var_94], 24h
	jz  loc_44B893
	cmp  [ebp+var_94], 48h
	jz  loc_44B8A6
	cmp  [ebp+var_94], 6Ch
	jz  loc_44B8B9
	jmp  loc_44B8CC
loc_44B910::
	cmp  [ebp+var_44], 0
	jnz  loc_44BA08
	cmp  ?gbInViewWorld@@3HA, 0
	jz  loc_44B996
	push  90h
	push  90h
	push  10h
	push  1E0h
	push  0
	push  0B5h
	mov  eax, [ebp+a4]
	push  eax
	mov  eax, ?iVWMapOriginY@@3HA
	mov  [ebp+var_98], eax
	fild  [ebp+var_98]
	fmul  [ebp+var_4C]
	fadd  ds:flt_4EA2C0
	call  __ftol
	push  eax
	mov  eax, ?iVWMapOriginX@@3HA
	mov  [ebp+var_9C], eax
	fild  [ebp+var_9C]
	fmul  [ebp+var_4C]
	fadd  ds:flt_4EA2C4
	call  __ftol
	push  eax
	mov  eax, [ebp+var_74]
	mov  ecx, [eax+1CEh]
	call  ?ClipFillToBuffer@icon@@QAEXHHHHHHHHH@Z
	jmp  loc_44BA08
loc_44B996::
	push  90h
	push  90h
	push  10h
	push  1E0h
	push  0
	push  0B5h
	mov  eax, [ebp+a4]
	push  eax
	mov  eax, [ebp+var_74]
	mov  eax, [eax+1DAh]
	mov  [ebp+var_A0], eax
	fild  [ebp+var_A0]
	fmul  [ebp+var_4C]
	fadd  ds:flt_4EA2C0
	call  __ftol
	push  eax
	mov  eax, [ebp+var_74]
	mov  eax, [eax+1D6h]
	mov  [ebp+var_A4], eax
	fild  [ebp+var_A4]
	fmul  [ebp+var_4C]
	fadd  ds:flt_4EA2C4
	call  __ftol
	push  eax
	mov  eax, [ebp+var_74]
	mov  ecx, [eax+1CEh]
	call  ?ClipFillToBuffer@icon@@QAEXHHHHHHHHH@Z
loc_44BA08::
	cmp  [ebp+arg_0], 0
	jz  loc_44BABC
	cmp  [ebp+arg_4], 0
	jz  loc_44BAA0
	mov  eax, [ebp+var_34]
	sub  eax, [ebp+var_38]
	inc  eax
	mov  [ebp+var_A8], eax
	fild  [ebp+var_A8]
	fmul  [ebp+var_4C]
	call  __ftol
	push  eax
	mov  eax, [ebp+var_1C]
	sub  eax, [ebp+var_20]
	inc  eax
	mov  [ebp+var_AC], eax
	fild  [ebp+var_AC]
	fmul  [ebp+var_4C]
	call  __ftol
	push  eax
	mov  eax, [ebp+var_38]
	mov  [ebp+var_B0], eax
	fild  [ebp+var_B0]
	fmul  [ebp+var_4C]
	fadd  ds:flt_4EA2C0
	call  __ftol
	push  eax
	mov  eax, [ebp+var_20]
	mov  [ebp+var_B4], eax
	fild  [ebp+var_B4]
	fmul  [ebp+var_4C]
	fadd  ds:flt_4EA2C4
	call  __ftol
	push  eax
	mov  ecx, ?gpWindowManager@@3PAVheroWindowManager@@A
	call  ?UpdateScreenRegion@heroWindowManager@@QAEXHHHH@Z
	jmp  loc_44BABC
loc_44BAA0::
	push  90h
	push  90h
	push  10h
	push  1E0h
	mov  ecx, ?gpWindowManager@@3PAVheroWindowManager@@A
	call  ?UpdateScreenRegion@heroWindowManager@@QAEXHHHH@Z
loc_44BABC::
	jmp  loc_44BAC6
loc_44BAC1::
	jmp  loc_44B355
loc_44BAC6::
	pop  edi
	pop  esi
	pop  ebx
	leave  
	retn  8
?UpdateRadar@advManager@@QAEXHH@Z endp

ENDIF