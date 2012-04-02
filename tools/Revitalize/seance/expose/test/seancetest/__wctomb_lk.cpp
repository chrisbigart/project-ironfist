int __cdecl _wctomb_lk(LPSTR lpMultiByteStr, const WCHAR WideCharStr)
{
  int result; // eax@2
  BOOL UsedDefaultChar; // [sp+0h] [bp-4h]@7

  if ( lpMultiByteStr )
  {
    if ( Locale )
    {
      UsedDefaultChar = 0;
      result = WideCharToMultiByte(CodePage, 0x220u, &WideCharStr, 1, lpMultiByteStr, cchMultiByte, 0, &UsedDefaultChar);
      if ( !result || UsedDefaultChar )
      {
        *_errno() = 42;
        result = -1;
      }
    }
    else
    {
      if ( WideCharStr <= 0xFFu )
      {
        *lpMultiByteStr = WideCharStr;
        result = 1;
      }
      else
      {
        *_errno() = 42;
        result = -1;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
