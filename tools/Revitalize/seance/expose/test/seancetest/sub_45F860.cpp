__int16 __stdcall sub_45F860(void *a1)
{
  __int16 result; // ax@2
  int v2; // ST20_4@3

  sub_45F910();
  if ( dword_4ED2E4 == dword_4ED2E0 )
  {
    result = 0;
  }
  else
  {
    v2 = *((_DWORD *)dword_4ED2EC + dword_4ED2E4);
    memcpy(a1, *((const void **)dword_4ED2E8 + dword_4ED2E4), *((_DWORD *)dword_4ED2EC + dword_4ED2E4));
    KBFree(*((void **)dword_4ED2E8 + dword_4ED2E4), (int)"F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511CBC + 9);
    dword_4ED2E4 = (dword_4ED2E4 + 1) % 200;
    result = v2;
  }
  return result;
}
