#include "base.h"
#include "adventure/adv.h"
#include "combat/combat.h"
#include "game/game.h"
#include "artifacts.h"
#include "skills.h"
#include "resource/resourceManager.h"
#include "sound/sound.h"
#include "spell/spells.h"

#include <cmath>

//extern int* gArmyEffected[];
extern signed char gArmyEffected[][20];

typedef DWORD _DWORD;

void army::PowEffect(int animIdx, int a3, int a4, int a5)
	{
	int tmp1; // eax@35
	int tmp2; // eax@37
	int tmp3; // eax@39
	int tmp4; // eax@43
	int tmp5; // eax@45
	int tmp6; // eax@47
	int v11; // eax@70
	int v12; // eax@72
	int v13; // eax@74
	int v14; // eax@76
	int v15; // eax@79
	int v16; // eax@81
	signed int v17; // eax@83
	signed int v18; // eax@85
	IconEntry *animICNHeader; // [sp+20h] [bp-44h]@70
	int maxAnyCreatureAnimLen; // [sp+24h] [bp-40h]@45
	int maxAnyCreatureAnimLena; // [sp+24h] [bp-40h]@47
	signed int i; // [sp+28h] [bp-3Ch]@10
	signed int k; // [sp+28h] [bp-3Ch]@25
	signed int m; // [sp+28h] [bp-3Ch]@51
	signed int jj; // [sp+28h] [bp-3Ch]@88
	signed int mm; // [sp+28h] [bp-3Ch]@110
	signed int i1; // [sp+28h] [bp-3Ch]@161
	signed int i3; // [sp+28h] [bp-3Ch]@173
	signed int i5; // [sp+28h] [bp-3Ch]@210
	signed int i7; // [sp+28h] [bp-3Ch]@220
	signed int i9; // [sp+28h] [bp-3Ch]@229
	int fromAnimLen; // [sp+2Ch] [bp-38h]@1
	int maxOneWayAnimLen; // [sp+30h] [bp-34h]@1
	army *othstack; // [sp+38h] [bp-2Ch]@29
	army *thisc; // [sp+38h] [bp-2Ch]@92
	army *thisd; // [sp+38h] [bp-2Ch]@114
	char *thise; // [sp+38h] [bp-2Ch]@165
	char *thisf; // [sp+38h] [bp-2Ch]@177
	army *thisg; // [sp+38h] [bp-2Ch]@224
	signed int v41; // [sp+3Ch] [bp-28h]@171
	int j; // [sp+40h] [bp-24h]@12
	int l; // [sp+40h] [bp-24h]@27
	int n; // [sp+40h] [bp-24h]@53
	signed int ii; // [sp+40h] [bp-24h]@68
	int kk; // [sp+40h] [bp-24h]@90
	int nn; // [sp+40h] [bp-24h]@112
	int i2; // [sp+40h] [bp-24h]@163
	int i4; // [sp+40h] [bp-24h]@175
	int i6; // [sp+40h] [bp-24h]@212
	int i8; // [sp+40h] [bp-24h]@222
	int i10; // [sp+40h] [bp-24h]@231
	signed int doCreatureEffect; // [sp+44h] [bp-20h]@1
	int ll; // [sp+48h] [bp-1Ch]@108
	int oneWayAnimLen; // [sp+4Ch] [bp-18h]@1
	int maxToAnimLen; // [sp+50h] [bp-14h]@1
	int maxFromAnimLen; // [sp+54h] [bp-10h]@1
	int toAnimLen; // [sp+58h] [bp-Ch]@1
	signed int specialCaseOverlapWeirdness; // [sp+5Ch] [bp-8h]@1
	int creatureEffectNumFrames; // [sp+60h] [bp-4h]@1
	int maxAnimLen; // [sp+60h] [bp-4h]@49

	maxToAnimLen = 0;
	maxFromAnimLen = 0;
	maxOneWayAnimLen = 0;
	creatureEffectNumFrames = 0;
	toAnimLen = 0;
	fromAnimLen = 0;
	oneWayAnimLen = 0;
	doCreatureEffect = 0;
	specialCaseOverlapWeirdness = 1;
	if(this->creatureIdx == CREATURE_PALADIN || this->creatureIdx == CREATURE_CRUSADER)
		specialCaseOverlapWeirdness = 0;
	if(this->creatureIdx == CREATURE_DWARF || this->creatureIdx == CREATURE_BATTLE_DWARF)
		specialCaseOverlapWeirdness = 2;
	if(a4 == -1)
		{
		if(animIdx != -1)
			{
			for(i = 0; i < 2; ++i)
				{
				for(j = 0; gpCombatManager->numCreatures[i] > j; ++j)
					{
					if(gpCombatManager->creatures[i][j].probablyIsNeedDrawSpellEffect)
						doCreatureEffect = 1;
					}
				}
			}
		}
	else
		{
		doCreatureEffect = 1;
		}
	if(!gbNoShowCombat && animIdx != -1 && doCreatureEffect && animIdx != gCurLoadedSpellEffect)
		{
		gpResourceManager->Dispose((resource *)gCurLoadedSpellIcon);
		gCurLoadedSpellIcon = gpResourceManager->GetIcon(gCombatFxNames[animIdx]);
		gCurLoadedSpellEffect = animIdx;
		}
	if(doCreatureEffect)
		creatureEffectNumFrames = giNumPowFrames[gCurLoadedSpellEffect];
	for(k = 0; k < 2; ++k)
		{
		for(l = 0; gpCombatManager->numCreatures[k] > l; ++l)
			{
			othstack = &gpCombatManager->creatures[k][l];
			if(gpCombatManager->creatures[k][l].mightBeIsAttacking)
				{
				toAnimLen = othstack->frameInfo.animationLengths[this->mightBeAttackAnimIdx];
				fromAnimLen = othstack->frameInfo.animationLengths[this->mightBeAttackAnimIdx + 1] + 1;
				}
			else if(gpCombatManager->creatures[k][l].dead)
				{
				oneWayAnimLen = gpCombatManager->creatures[k][l].frameInfo.animationLengths[13];
				}
			else if(gpCombatManager->creatures[k][l].damageTakenDuringSomeTimePeriod)
				{
				oneWayAnimLen = gpCombatManager->creatures[k][l].frameInfo.animationLengths[15]
					+ gpCombatManager->creatures[k][l].frameInfo.animationLengths[14]
					+ 1;
				}
			tmp1 = maxToAnimLen;
			if(maxToAnimLen <= toAnimLen)
				tmp1 = toAnimLen;
			maxToAnimLen = tmp1;
			tmp2 = maxFromAnimLen;
			if(maxFromAnimLen <= fromAnimLen)
				tmp2 = fromAnimLen;
			maxFromAnimLen = tmp2;
			tmp3 = maxOneWayAnimLen;
			if(maxOneWayAnimLen <= oneWayAnimLen)
				tmp3 = oneWayAnimLen;
			maxOneWayAnimLen = tmp3;
			}
		}
	tmp4 = maxOneWayAnimLen + maxToAnimLen - specialCaseOverlapWeirdness;
	if(tmp4 <= maxFromAnimLen + maxToAnimLen)
		tmp4 = maxFromAnimLen + maxToAnimLen;
	maxAnyCreatureAnimLen = tmp4;
	tmp5 = maxOneWayAnimLen;
	if(maxOneWayAnimLen <= maxAnyCreatureAnimLen)
		tmp5 = maxAnyCreatureAnimLen;
	maxAnyCreatureAnimLena = tmp5;
	tmp6 = creatureEffectNumFrames;
	if(creatureEffectNumFrames <= maxAnyCreatureAnimLena)
		tmp6 = maxAnyCreatureAnimLena;
	maxAnimLen = tmp6;
	if(a3)
		gpCombatManager->ResetLimitCreature();
	for(m = 0; m < 2; ++m)
		{
		for(n = 0; gpCombatManager->numCreatures[m] > n; ++n)
			{
			gpCombatManager->creatures[m][n].animatingRangedAttack = gpCombatManager->creatures[m][n].animationType == ANIMATION_TYPE_RANGED_ATTACK_UPWARDS
				|| gpCombatManager->creatures[m][n].animationType == ANIMATION_TYPE_RANGED_ATTACK_FORWARDS
				|| gpCombatManager->creatures[m][n].animationType == ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS;
			if((gpCombatManager->creatures[m][n].damageTakenDuringSomeTimePeriod
				|| gpCombatManager->creatures[m][n].mightBeIsAttacking
				|| gpCombatManager->creatures[m][n].animatingRangedAttack)
				&& !gpCombatManager->limitCreature[m][n])
				++gpCombatManager->limitCreature[m][n];
			}
		}
	gpCombatManager->DrawFrame(0, 1, 0, 1, 75, 1, 1);
	if(a4 != -1)
		{
		for(ii = 0; gCurLoadedSpellIcon->numSprites > ii; ++ii)
			{
			animICNHeader = &gCurLoadedSpellIcon->headersAndImageData[ii];
			v11 = a4 + animICNHeader->offsetX;
			if(v11 >= giMinExtentX)
				v11 = giMinExtentX;
			giMinExtentX = v11;
			v12 = a5 + animICNHeader->offsetY;
			if(v12 >= giMinExtentY)
				v12 = giMinExtentY;
			giMinExtentY = v12;
			v13 = a4 + animICNHeader->offsetX + animICNHeader->width - 1;
			if(v13 <= giMaxExtentX)
				v13 = giMaxExtentX;
			giMaxExtentX = v13;
			v14 = a5 + animICNHeader->height + animICNHeader->offsetY - 1;
			if(v14 <= giMaxExtentY)
				v14 = giMaxExtentY;
			giMaxExtentY = v14;
			}
		v15 = giMinExtentX;
		if(giMinExtentX <= 0)
			v15 = 0;
		giMinExtentX = v15;
		v16 = giMinExtentY;
		if(giMinExtentY <= 0)
			v16 = 0;
		giMinExtentY = v16;
		v17 = giMaxExtentX;
		if(giMaxExtentX >= 639)
			v17 = 639;
		giMaxExtentX = v17;
		v18 = giMaxExtentY;
		if(giMaxExtentY >= 442)
			v18 = 442;
		giMaxExtentY = v18;
		}
	for(jj = 0; jj < 2; ++jj)
		{
		for(kk = 0; gpCombatManager->numCreatures[jj] > kk; ++kk)
			{
			thisc = &gpCombatManager->creatures[jj][kk];
			gpCombatManager->creatures[jj][kk].field_3 = -1;
			thisc->field_4 = -1;
			*(_DWORD *)&thisc->effectStrengths[15] = 0;
			if(thisc->damageTakenDuringSomeTimePeriod || thisc->mightBeIsAttacking)
				{
				if(thisc->mightBeIsAttacking)
					{
					thisc->field_3 = this->mightBeAttackAnimIdx;
					thisc->field_4 = this->mightBeAttackAnimIdx + 1;
					}
				else if(thisc->dead)
					{
					thisc->field_3 = ANIMATION_TYPE_DYING;
					}
				else
					{
					thisc->field_3 = ANIMATION_TYPE_WINCE;
					thisc->field_4 = ANIMATION_TYPE_WINCE_RETURN;
					}
				if(thisc->field_3 == 13)
					thisc->field_5 = thisc->frameInfo.animationLengths[13];
				else
					thisc->field_5 = thisc->frameInfo.animationLengths[thisc->field_3]
					+ thisc->frameInfo.animationLengths[thisc->field_3 + 1];
				if(thisc->field_3 == thisc->animationType)
					--thisc->field_5;
				if(this->field_6 < 2)
					this->field_6 = 2;
				}
			}
		}
	for(ll = 0; maxAnimLen > ll; ++ll)
		{
		for(mm = 0; mm < 2; ++mm)
			{
			for(nn = 0; gpCombatManager->numCreatures[mm] > nn; ++nn)
				{
				thisd = &gpCombatManager->creatures[mm][nn];
				if(gpCombatManager->creatures[mm][nn].animatingRangedAttack)
					{
					if(gpCombatManager->creatures[mm][nn].animationType != ANIMATION_TYPE_RANGED_ATTACK_UPWARDS
						&& gpCombatManager->creatures[mm][nn].animationType != ANIMATION_TYPE_RANGED_ATTACK_FORWARDS
						&& gpCombatManager->creatures[mm][nn].animationType != ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS)
						{
						if(gpCombatManager->creatures[mm][nn].animationType != ANIMATION_TYPE_STANDING)
							{
							if(gpCombatManager->creatures[mm][nn].frameInfo.animationLengths[gpCombatManager->creatures[mm][nn].animationType] <= gpCombatManager->creatures[mm][nn].animationFrame + 1)
								{
								gpCombatManager->creatures[mm][nn].animationType = ANIMATION_TYPE_STANDING;
								thisd->animationFrame = 0;
								}
							else
								{
								++gpCombatManager->creatures[mm][nn].animationFrame;
								}
							}
						}
					else
						{
						++gpCombatManager->creatures[mm][nn].animationType;
						thisd->animationFrame = 0;
						}
					}
				if(thisd->field_3 != -1
					&& !*(_DWORD *)&thisd->effectStrengths[15]
					&& (thisd->mightBeIsAttacking
						|| thisd->field_5 >= maxAnimLen - ll - 1
						|| maxToAnimLen && maxToAnimLen - 1 <= ll
						|| !maxToAnimLen
						&& thisd->animationType != 15
						&& (thisd->animationType != 14
							|| thisd->frameInfo.animationLengths[thisd->animationType] > thisd->animationFrame + 1)))
					{
					if(thisd->field_3 == thisd->animationType || thisd->field_4 == thisd->animationType)
						{
						if(thisd->frameInfo.animationLengths[thisd->animationType] <= thisd->animationFrame + 1)
							{
							if(thisd->field_4 == thisd->animationType || thisd->field_4 == -1)
								{
								if(thisd->animationType != 7 && thisd->animationType != 13)
									{
									thisd->animationType = 7;
									thisd->animationFrame = 0;
									*(_DWORD *)&thisd->effectStrengths[15] = 1;
									}
								}
							else
								{
								thisd->animationType = thisd->field_4;
								thisd->animationFrame = 0;
								}
							}
						else
							{
							++thisd->animationFrame;
							//DelayMilli(1250);
							}
						}
					else
						{
						if(!gbNoShowCombat && thisd->field_3 == 14)

							gpSoundManager->MemorySample(
								gpCombatManager->creatures[mm][nn].combatSounds[2]);
						if(!gbNoShowCombat && thisd->field_3 == 13)

							gpSoundManager->MemorySample(
								gpCombatManager->creatures[mm][nn].combatSounds[4]);
						thisd->animationType = thisd->field_3;
						thisd->animationFrame = 0;
						}
					}
				}
			}
		glTimers = (signed __int64)((double)KBTickCount() + (double)120 * gfCombatSpeedMod[giCombatSpeed]);
		if(doCreatureEffect && giNumPowFrames[gCurLoadedSpellEffect] > ll)
			gCurSpellEffectFrame = ll;
		gpCombatManager->DrawFrame(0, 1, 0, 0, 75, 1, 1);
		if(a4 != -1 && giNumPowFrames[gCurLoadedSpellEffect] > ll)

			gCurLoadedSpellIcon->CombatClipDrawToBuffer(
				a4,
				a5 + this->field_FA,
				gCurSpellEffectFrame,
				(SLimitData*)&this->effectAnimationBounds,
				0,
				0,
				0,
				0);

		//DelayMilli(250);
		gpWindowManager->UpdateScreenRegion(
			giMinExtentX,
			giMinExtentY,
			giMaxExtentX - giMinExtentX + 1,
			giMaxExtentY - giMinExtentY + 1);
		}
	if(!gbNoShowCombat)
		WaitSample(1);
	for(i1 = 0; i1 < 2; ++i1)
		{
		for(i2 = 0; gpCombatManager->numCreatures[i1] > i2; ++i2)
			{
			thise = (char *)&gpCombatManager->creatures[i1][i2];
			if(gpCombatManager->creatures[i1][i2].damageTakenDuringSomeTimePeriod
				&& gpCombatManager->creatures[i1][i2].spellEnemyCreatureAbilityIsCasting != -1
				&& gpCombatManager->creatures[i1][i2].spellEnemyCreatureAbilityIsCasting != 101)
				{

				gpCombatManager->CastSpell(
					(Spell)gpCombatManager->creatures[i1][i2].spellEnemyCreatureAbilityIsCasting,
					gpCombatManager->creatures[i1][i2].occupiedHex,
					1,
					-1);
				*(_DWORD *)(thise + 226) = -1;
				}
			}
		}
	v41 = 1;
	while(v41)
		{
		v41 = 0;
		for(i3 = 0; i3 < 2; ++i3)
			{
			for(i4 = 0; gpCombatManager->numCreatures[i3] > i4; ++i4)
				{
				thisf = (char *)&gpCombatManager->creatures[i3][i4];
				if(gpCombatManager->creatures[i3][i4].animationType != 14
					&& gpCombatManager->creatures[i3][i4].animationType != 16
					&& gpCombatManager->creatures[i3][i4].animationType != 20
					&& gpCombatManager->creatures[i3][i4].animationType != 24
					&& gpCombatManager->creatures[i3][i4].animationType != 18
					&& gpCombatManager->creatures[i3][i4].animationType != 22
					&& gpCombatManager->creatures[i3][i4].animationType != 26
					&& gpCombatManager->creatures[i3][i4].animationType != 28
					&& gpCombatManager->creatures[i3][i4].animationType != 30
					&& gpCombatManager->creatures[i3][i4].animationType != 32)
					{
					if(gpCombatManager->creatures[i3][i4].animationType == 13
						|| gpCombatManager->creatures[i3][i4].animationType == 15
						|| gpCombatManager->creatures[i3][i4].animationType == 17
						|| gpCombatManager->creatures[i3][i4].animationType == 21
						|| gpCombatManager->creatures[i3][i4].animationType == 25
						|| gpCombatManager->creatures[i3][i4].animationType == 19
						|| gpCombatManager->creatures[i3][i4].animationType == 23
						|| gpCombatManager->creatures[i3][i4].animationType == 27
						|| gpCombatManager->creatures[i3][i4].animationType == 29
						|| gpCombatManager->creatures[i3][i4].animationType == 31
						|| gpCombatManager->creatures[i3][i4].animationType == 33)
						{
						if(gpCombatManager->creatures[i3][i4].frameInfo.animationLengths[gpCombatManager->creatures[i3][i4].animationType] <= gpCombatManager->creatures[i3][i4].animationFrame + 1)
							{
							if(gpCombatManager->creatures[i3][i4].animationType != 13)
								{
								gpCombatManager->creatures[i3][i4].animationType = 7;
								*(_DWORD *)(thisf + 130) = 0;
								v41 = 1;
								}
							}
						else
							{
							++gpCombatManager->creatures[i3][i4].animationFrame;
							v41 = 1;
							}
						}
					}
				else
					{
					++gpCombatManager->creatures[i3][i4].animationType;
					*(_DWORD *)(thisf + 130) = 0;
					v41 = 1;
					}
				}
			}
		if(v41)
			{
			glTimers = (signed __int64)((double)KBTickCount() + (double)120 * gfCombatSpeedMod[giCombatSpeed]);
			gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
			DelayMilli(1250);
			}
		}
	if(a3)
		gpCombatManager->ResetLimitCreature();
	memset(gpCombatManager->shouldVanish, 0, 0x28u);
	gpCombatManager->anyStacksShouldVanish = 0;
	for(i5 = 0; i5 < 2; ++i5)
		{
		for(i6 = 0; gpCombatManager->numCreatures[i5] > i6; ++i6)
			{
			if(gpCombatManager->creatures[i5][i6].dead)
				(&gpCombatManager->creatures[i5][i6])->ProcessDeath(0);
			}
		}
	if(gpCombatManager->anyStacksShouldVanish)
		gpCombatManager->MakeCreaturesVanish();
	for(i7 = 0; i7 < 2; ++i7)
		{
		for(i8 = 0; gpCombatManager->numCreatures[i7] > i8; ++i8)
			{
			thisg = &gpCombatManager->creatures[i7][i8];
			if(gpCombatManager->creatures[i7][i8].damageTakenDuringSomeTimePeriod
				&& gpCombatManager->creatures[i7][i8].spellEnemyCreatureAbilityIsCasting == 101)
				{

				gpCombatManager->CastSpell(
					(Spell)gpCombatManager->creatures[i7][i8].spellEnemyCreatureAbilityIsCasting,
					gpCombatManager->creatures[i7][i8].occupiedHex,
					1,
					-1);
				thisg->spellEnemyCreatureAbilityIsCasting = -1;
				}
			thisg->probablyIsNeedDrawSpellEffect = 0;
			thisg->damageTakenDuringSomeTimePeriod = 0;
			thisg->hasTakenLosses = 0;
			thisg->field_6 = 1;
			thisg->mightBeIsAttacking = 0;
			thisg->previousQuantity = -1;
			}
		}
	gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
	for(i9 = 0; i9 < 2; ++i9)
		{
		for(i10 = 0; gpCombatManager->numCreatures[i9] > i10; ++i10)
			WaitSample(2);
		}
	}

void army::SpecialAttack()
	{
	int v1; // ebx@0
	double xDiff; // st6@0
	int v3; // eax@12
	int v4; // ST64_4@42
	double v5; // st7@51
	char *v7; // [sp+40h] [bp-1ACh]@132
	char *v8; // [sp+44h] [bp-1A8h]@127
	char *v9; // [sp+48h] [bp-1A4h]@124
	bitmap *thisb; // [sp+54h] [bp-198h]@55
	int v11; // [sp+58h] [bp-194h]@0
	army *targ; // [sp+5Ch] [bp-190h]@113
	int projStartX; // [sp+60h] [bp-18Ch]@16
	float angleDeg; // [sp+64h] [bp-188h]@24
	char v15; // [sp+68h] [bp-184h]@103
	int yDiff; // [sp+6Ch] [bp-180h]@20
	int startY; // [sp+70h] [bp-17Ch]@49
	int v18; // [sp+74h] [bp-178h]@46
	int damageDone; // [sp+78h] [bp-174h]@1
	int totXDiff; // [sp+7Ch] [bp-170h]@18
	int v21; // [sp+80h] [bp-16Ch]@43
	signed int startX; // [sp+84h] [bp-168h]@47
	int v23; // [sp+88h] [bp-164h]@46
	int creaturesKilled; // [sp+8Ch] [bp-160h]@1
	int v25; // [sp+90h] [bp-15Ch]@43
	int offsetY; // [sp+94h] [bp-158h]@46
	signed int i; // [sp+98h] [bp-154h]@25
	int offsetX; // [sp+9Ch] [bp-150h]@46
	bitmap *bmp; // [sp+A0h] [bp-14Ch]@56
	int v30; // [sp+A4h] [bp-148h]@43
	int y; // [sp+A8h] [bp-144h]@58
	int origFacingRight; // [sp+ACh] [bp-140h]@1
	army *target; // [sp+B0h] [bp-13Ch]@1
	float slope; // [sp+B4h] [bp-138h]@25
	int v35; // [sp+B8h] [bp-134h]@49
	int x; // [sp+BCh] [bp-130h]@58
	char targRow; // [sp+C0h] [bp-12Ch]@1
	int v38; // [sp+C4h] [bp-128h]@43
	signed int endY; // [sp+C8h] [bp-124h]@49
	int v40; // [sp+CCh] [bp-120h]@53
	int v41; // [sp+D0h] [bp-11Ch]@55
	int targMidY; // [sp+D4h] [bp-118h]@12
	int attackDirectionAnimationIdx; // [sp+D8h] [bp-114h]@33
	signed int endX; // [sp+DCh] [bp-110h]@49
	int v45; // [sp+E0h] [bp-10Ch]@49
	int v46; // [sp+E4h] [bp-108h]@53
	int v47; // [sp+E8h] [bp-104h]@55
	char targCol; // [sp+ECh] [bp-100h]@1
	char thisRow; // [sp+F0h] [bp-FCh]@1
	int v50; // [sp+F4h] [bp-F8h]@49
	int animIdx; // [sp+F8h] [bp-F4h]@103
	int a5; // [sp+FCh] [bp-F0h]@103
	char thisCol; // [sp+100h] [bp-ECh]@1
	char firingLeft; // [sp+104h] [bp-E8h]@18
	int v55; // [sp+108h] [bp-E4h]@49
	int v56; // [sp+10Ch] [bp-E0h]@58
	int a4; // [sp+110h] [bp-DCh]@103
	char message[256]; // [sp+114h] [bp-D8h]@135
	int projStartY; // [sp+1DCh] [bp-10h]@18
	int targMidX; // [sp+1E0h] [bp-Ch]@12
	int missleSpriteIdx; // [sp+1E4h] [bp-8h]@22
	int v62; // [sp+1E8h] [bp-4h]@58

	damageDone = 0;
	creaturesKilled = 0;
	origFacingRight = this->facingRight;
	this->field_125 = 0;
	target = &gpCombatManager->creatures[this->targetOwner][this->targetStackIdx];
	targCol = target->occupiedHex % 13;
	targRow = target->occupiedHex / 13;
	thisCol = this->occupiedHex % 13;
	thisRow = this->occupiedHex / 13;
	origFacingRight = this->facingRight;
	this->facingRight = targCol > thisCol || !(thisRow & 1) && targCol == thisCol;
	if(this->facingRight != origFacingRight)
		{
		if(this->creature.creature_flags & TWO_HEXER)
			{
			if(this->facingRight == 1)
				--this->occupiedHex;
			else
				++this->occupiedHex;
			}
		gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
		}
	CheckLuck();
	gpSoundManager->MemorySample(this->combatSounds[3]);
	gpCombatManager->ResetLimitCreature();
	v3 = 80 * this->owningSide + 4 * this->stackIdx;
	++*(signed int *)((char *)gpCombatManager->limitCreature[0] + v3);
	gpCombatManager->DrawFrame(0, 1, 0, 1, 75, 1, 1);
	targMidX = target->MidX();
	targMidY = target->MidY();
	if(this->creatureIdx == CREATURE_LICH || this->creatureIdx == CREATURE_POWER_LICH)
		{
		targMidX = gpCombatManager->combatGrid[target->occupiedHex].centerX;
		targMidY = gpCombatManager->combatGrid[target->occupiedHex].occupyingCreatureBottomY - 17;
		}
	if(this->facingRight == 1)
		projStartX = this->frameInfo.projectileStartOffset[1][0] + gpCombatManager->combatGrid[this->occupiedHex].centerX;
	else
		projStartX = gpCombatManager->combatGrid[this->occupiedHex].centerX - this->frameInfo.projectileStartOffset[1][0];
	projStartY = this->frameInfo.projectileStartOffset[1][1]
		+ gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY;
	totXDiff = targMidX - projStartX;
	firingLeft = 0;
	if(targMidX - projStartX < 0)
		{
		firingLeft = 1;
		totXDiff = -totXDiff;
		}
	yDiff = targMidY - projStartY;
	if(totXDiff)
		{
		xDiff = (double)totXDiff;
		slope = (double)-yDiff / xDiff;
		angleDeg = atan(slope) * 180.0 / 3.14159;
		for(i = 1;
			this->frameInfo.numMissileDirs > i
			&& (*(float *)((char *)this->frameInfo.projectileStartOffset[i + 2] + 1) + this->frameInfo.projDirAngle[i]) / 2.0 >= angleDeg;
			++i)
			;
		if(this->frameInfo.numMissileDirs <= i)
			missleSpriteIdx = this->frameInfo.numMissileDirs - 1;
		else
			missleSpriteIdx = i - 1;
		}
	else
		{
		if(yDiff <= 0)
			missleSpriteIdx = 0;
		else
			missleSpriteIdx = this->frameInfo.numMissileDirs - 1;
		angleDeg = (double)(yDiff <= 0 ? 90 : -90);
		}
	if(angleDeg <= 25.0)
		{
		if(angleDeg <= -25.0)
			{
			this->animationType = ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS;
			attackDirectionAnimationIdx = 2;
			}
		else
			{
			this->animationType = ANIMATION_TYPE_RANGED_ATTACK_FORWARDS;
			attackDirectionAnimationIdx = 1;
			}
		}
	else
		{
		this->animationType = ANIMATION_TYPE_RANGED_ATTACK_UPWARDS;
		attackDirectionAnimationIdx = 0;
		}
	for(this->animationFrame = 0;
		this->frameInfo.animationLengths[this->animationType] > this->animationFrame;
		++this->animationFrame)
		{
		if(this->frameInfo.animationLengths[this->animationType] - 1 == this->animationFrame)
			gpCombatManager->DrawFrame(0, 1, 0, 0, 75, 1, 1);
		else
			gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
		v4 = KBTickCount();
		xDiff = (double)this->frameInfo.shootingTime
			* gfCombatSpeedMod[giCombatSpeed]
			/ (double)this->frameInfo.animationLengths[this->animationType];
		glTimers = (signed __int64)((double)v4 + xDiff);
		}
	this->animationFrame = this->frameInfo.animationLengths[this->animationType] - 1;
	v30 = 25;
	v21 = 25;
	v38 = 31;
	v25 = 25;
	if(this->creatureIdx == CREATURE_LICH || this->creatureIdx == CREATURE_POWER_LICH)
		{
		v38 = 26;
		v25 = 7;
		v30 = 10;
		v21 = 10;
		}
	v23 = 0;
	offsetX = 639;
	v18 = 0;
	offsetY = 479;
	if(this->facingRight == 1)
		startX = gpCombatManager->combatGrid[this->occupiedHex].centerX
		+ this->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][0];
	else
		startX = gpCombatManager->combatGrid[this->occupiedHex].centerX
		- this->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][0];
	startY = gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY
		+ this->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][1];
	endX = target->MidX();
	endY = target->MidY();
	v45 = endX - startX;
	v50 = endY - startY;
	v35 = (signed __int64)sqrt((double)(v50 * v50 + (endX - startX) * (endX - startX)));
	v55 = (v35 + (v38 >> 1)) / v38;
	if(this->creatureIdx != CREATURE_MAGE && this->creatureIdx != CREATURE_ARCHMAGE)
		{
		if(v55 <= 1)
			{
			v46 = v45;
			v40 = v50;
			}
		else
			{
			v46 = v45 / (v55 - 1);
			v40 = v50 / (v55 - 1);
			}
		v47 = startX;
		v41 = startY;
		bmp = new bitmap(33, 2 * v30, 2 * v21);
		
		bmp->GrabBitmapCareful(gpWindowManager->screenBuffer, v47 - v30, v41 - v21);
		v62 = v47;
		v56 = v41;
		x = 0;
		y = 0;
		for(i = 0; i < v55; ++i)
			{
			if(v62 - v30 < offsetX)
				offsetX = v62 - v30;
			if(offsetX < 0)
				offsetX = 0;
			if(v30 + v62 > v23)
				v23 = v30 + v62;
			if(v23 > 639)
				v23 = 639;
			if(v56 - v21 < offsetY)
				offsetY = v56 - v21;
			if(offsetY < 0)
				offsetY = 0;
			if(v21 + v56 > v18)
				v18 = v21 + v56;
			if(v18 > 442)
				v18 = 442;
			if(i)
				{
				bmp->DrawToBufferCareful(x, y);
				}
			else
				{
				if(giMinExtentX > offsetX)
					giMinExtentX = offsetX;
				if(v23 > giMaxExtentX)
					giMaxExtentX = v23;
				if(offsetY < giMinExtentY)
					giMinExtentY = offsetY;
				if(v18 > giMaxExtentY)
					giMaxExtentY = v18;
				}
			x = v47 - v30;
			if(v47 - v30 < 0)
				x = 0;
			if(x + bmp->width > 640)
				x = 640 - bmp->width;
			y = v41 - v21;
			if(v41 - v21 < 0)
				y = 0;
			if(y + bmp->height > 640)
				y = 640 - bmp->height;
			bmp->GrabBitmapCareful(gpWindowManager->screenBuffer, x, y);
			this->missileIcon->DrawToBuffer(v47, v41, missleSpriteIdx, firingLeft);
			if(i)
				{
				DelayTil(&glTimers);
				gpWindowManager->UpdateScreenRegion(offsetX, offsetY, v23 - offsetX + 1, v18 - offsetY + 1);
				}
			else
				{

				gpWindowManager->UpdateScreenRegion(
					giMinExtentX,
					giMinExtentY,
					giMaxExtentX - giMinExtentX + 1,
					giMaxExtentY - giMinExtentY + 1);
				}
			glTimers = (signed __int64)((double)KBTickCount() + (double)v25 * gfCombatSpeedMod[giCombatSpeed]);
			v62 = v47;
			v56 = v41;
			v47 += v46;
			v41 += v40;
			offsetX = v47 - v30;
			v23 = v30 + v47;
			offsetY = v41 - v21;
			v18 = v21 + v41;
			}
		bmp->DrawToBuffer(x, y);
		gpWindowManager->UpdateScreenRegion(v62 - v30, v56 - v21, 2 * v30, 2 * v21);
		if(bmp)
			delete bmp;
		}
	else
		{

		gpWindowManager->UpdateScreenRegion(
			giMinExtentX,
			giMinExtentY,
			giMaxExtentX - giMinExtentX + 1,
			giMaxExtentY - giMinExtentY + 1);
		v5 = gfCombatSpeedMod[giCombatSpeed] * 115.0;
		DelayMilli((signed __int64)v5);

		gpCombatManager->DoBolt(
			v1,
			xDiff,
			v5,
			1,
			startX,
			startY,
			endX,
			endY,
			0,
			0,
			5,
			4,
			302,
			0,
			0,
			v35 / 15 + 15,
			1);//,
			/*0,
			10,
			0);*/
		}
	if(!gpCombatManager->heroes[this->owningSide]
		|| !gpCombatManager->heroes[this->owningSide]->HasArtifact(ARTIFACT_AMMO_CART))
		--this->creature.shots;
	v15 = this->creature.attack;
	animIdx = -1;
	a4 = -1;
	a5 = -1;
	if(this->creatureIdx != CREATURE_LICH && this->creatureIdx != CREATURE_POWER_LICH)
		{
		this->DamageEnemy(target, &damageDone, &creaturesKilled, 1, 0);
		}
	else
		{
		gpCombatManager->ClearEffects();
		for(i = 0; i < 7; ++i)
			{
			if(i >= 6)
				v11 = target->occupiedHex;
			else
				v11 = target->GetAdjacentCellIndex(target->occupiedHex, i);
			if(v11 != -1)
				{
				if(gpCombatManager->combatGrid[v11].unitOwner != -1)
					{
					targ = &gpCombatManager->creatures[gpCombatManager->combatGrid[v11].unitOwner][gpCombatManager->combatGrid[v11].stackIdx];
					if(!gArmyEffected[gpCombatManager->creatures[gpCombatManager->combatGrid[v11].unitOwner][gpCombatManager->combatGrid[v11].stackIdx].owningSide][gpCombatManager->creatures[gpCombatManager->combatGrid[v11].unitOwner][gpCombatManager->combatGrid[v11].stackIdx].stackIdx])
						{
						if(!(targ->creature.creature_flags & CREATURE_FLAGS::UNDEAD) && (target != targ || i == 6))
							{
							gArmyEffected[gpCombatManager->creatures[gpCombatManager->combatGrid[v11].unitOwner][gpCombatManager->combatGrid[v11].stackIdx].owningSide][gpCombatManager->creatures[gpCombatManager->combatGrid[v11].unitOwner][gpCombatManager->combatGrid[v11].stackIdx].stackIdx] = 1;
							this->DamageEnemy(targ, &damageDone, &creaturesKilled, 1, 0);
							}
						}
					}
				}
			}
		this->field_FA = 0;
		animIdx = 20;
		a4 = gpCombatManager->combatGrid[v11].centerX;
		a5 = gpCombatManager->combatGrid[v11].occupyingCreatureBottomY - 17;
		gpSoundManager->MemorySample(this->combatSounds[5]);
		}
	this->creature.attack = v15;
	if(creaturesKilled <= 0)
		{
		if(this->quantity <= 1)
			v7 = gArmyNames[this->creatureIdx];
		else
			v7 = gArmyNamesPlural[this->creatureIdx];
		sprintf(gText, "%s %s %d %s.", v7, this->quantity > 1 ? "does" : "do", damageDone, "damage");
		gText[0] -= 32;
		}
	else if(damageDone == -1)
		{
		sprintf(gText, "The mirror image is destroyed!");
		}
	else
		{
		if(creaturesKilled <= 1)
			v9 = gArmyNames[target->creatureIdx];
		else
			v9 = gArmyNamesPlural[target->creatureIdx];
		if(this->quantity <= 1)
			v8 = gArmyNames[this->creatureIdx];
		else
			v8 = gArmyNamesPlural[this->creatureIdx];
		sprintf(
			gText,
			"%s %s %d %s.\n%d %s %s.",
			v8,
			this->quantity > 1 ? "does" : "do",
			damageDone,
			"damage",
			creaturesKilled,
			v9,
			creaturesKilled > 1 ? "perishes" : "perish");
		gText[0] -= 32;
		}
	strcpy(message, gText);
	if(this->creatureIdx == CREATURE_ARCHMAGE
		&& SRandom(1, 100) < 20
		&& target
		&& target->SpellCastWorks(SPELL_ARCHMAGI_DISPEL))
		target->spellEnemyCreatureAbilityIsCasting = SPELL_ARCHMAGI_DISPEL;
	this->PowEffect(animIdx, 0, a4, a5);
	gpCombatManager->CombatMessage(message, 1, 1, 0);
	WaitSample(3);
	if(this->facingRight != origFacingRight)
		{
		if(this->creature.creature_flags & 1)
			{
			if(this->facingRight == 1)
				++this->occupiedHex;
			else
				--this->occupiedHex;
			}
		this->facingRight = origFacingRight;
		}
	if(!bSecondAttack
		&& (this->creatureIdx == CREATURE_ELF
			|| this->creatureIdx == CREATURE_GRAND_ELF
			|| this->creatureIdx == CREATURE_RANGER)
		&& target->quantity > 0)
		{
		bSecondAttack = 1;
		this->SpecialAttack();
		bSecondAttack = 0;
		}
	if(this->effectStrengths[5] || this->effectStrengths[7])
		{
		this->CancelSpellType(CREATURE_TOOK_TURN_EVENT_CODE);
		gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
		}
	}
// 5134A8: using guessed type int bSecondAttack;
// 5240A8: using guessed type int gpSoundManager;
// 524734: using guessed type int giMaxExtentX;
// 524738: using guessed type int giMaxExtentY;
