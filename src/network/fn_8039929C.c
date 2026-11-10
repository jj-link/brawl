
#pragma force_active on
typedef unsigned int u32;
typedef long long s64;
extern void OSSleepTicks(s64);
extern int fn_8020AB58(void *, int, int);
extern int fn_803C39BC(int, int, int);
extern int fn_803C3F48(const char *);
extern int lbl_805A1170;
extern char lbl_8059FCC8[4];
int fn_8039929C(char *arg0)
{
  int size = *((int *) (arg0 + 8));
  int buf = lbl_805A1170 + 0xb00;
  int ret = 0;
  int p;
  int r;
  u32 i;
  if (size == 0)
  {
    return 0;
  }
  ;
  while (size & 0x1f)
  {
    *((char *) (buf + size)) = 0;
    size++;
    p++;
  }

  if ((*((int *) (arg0 + 4))) & 0x100)
  {
    r = fn_803C39BC(*((int *) (arg0 + 0x98)), buf, size);
    if (r != 0)
    {
      if (r == 5)
      {
        switch (fn_803C3F48(lbl_8059FCC8))
        {
          case -5:

          case -15:
            ret = -0x2E;
            break;

          case -4:
            ret = -0x26;
            break;

          default:
            ret = -0x13;
            break;

        }

      }
      else
      {
        ret = -0x13;
      }
    }
    return ret;
  }
  i = 0;
  do
  {
    r = fn_8020AB58(arg0 + 0xc, buf, size);
    if (((u32) (r + 3)) > 1)
    {
      break;
    }
    OSSleepTicks(1000 * ((s64) (((*((u32 *) 0x800000F8)) / 4) / 1000)));
    i++;
  }
  while (i < 3);
  if (r == (-4))
  {
    return -0x26;
  }
  if (((u32) r) != ((u32) size))
  {
    ret = -0x13;
  }
  return ret;
}
