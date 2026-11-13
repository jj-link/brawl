
#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
extern s32 __cntlzw(u32);
s32 fn_80392994(u8 *arg0, s32 arg1)
{
  s32 val;
  s32 seen;
  s32 prev;
  s32 i;
  u8 *p;
  s32 y;
  s32 sign;
  s32 mask;
  s32 c;
  if (arg1 > 8)
  {
    return -1;
  }
  mask = ((u32) __cntlzw((u32) (arg1 - 8))) >> 5;
  sign = (s8) (*arg0);
  c = sign;
  y = c ^ 0x37;
  sign = y >> 1;
  sign = ((u32) (sign - ((seen = c) & y))) >> 31;
  if (mask & sign)
  {
    return -1;
  }
  val = 0;
  seen = 0;
  p = arg0;
  for (i = arg1; i > 0; i--, p++)
  {
    c = (s8) (*p);
    if ((c >= 0x41) & (c <= 0x5A))
    {
      c += 0x20;
    }
    c = (s8) c;
    if ((c >= 0x30) && (c <= 0x39))
    {
      seen = 1;
      val = (c + (val * 16)) - 0x30;
    }
    else
      if ((c >= 0x61) && (c <= 0x66))
    {
      seen = 1;
      val = (c + (val * 16)) - 0x57;
    }
    else
    {
      if (seen != 0)
      {
        if ((c == 0x20) || (c == 0))
        {
          break;
        }
      }
      if ((seen == 0) && (c == 0x20))
      {
        continue;
      }
      return -1;
    }
  }

  return val;
}
