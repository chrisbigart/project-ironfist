signed int __thiscall CombatManager::sphereOfNegationInEffect(CombatManager *this)
{
  CombatManager *thisa; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  thisa = this;
  for ( i = 0; i < 2; ++i )
  {
    if ( thisa->heroes[i] && Hero::hasArtifact(thisa->heroes[i], ARTIFACT_SPHERE_OF_NEGATION) )
      return 1;
  }
  return 0;
}
