
#pragma force_active on
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
extern int fn_803A962C(s8 a);
extern int fn_803AA514(void *obj);
extern int fn_803AA7D0(void *obj, int arg);
extern void fn_803B032C(void *obj);
extern void fn_803B1AA4(void *obj);
extern void fn_803BC090(void *obj);
extern int fn_803C0838(void *obj, int arg);
extern char lbl_8053B248[];
int fn_803C20EC(s8 arg0, int arg1)
{
  s16 temp;
  char *obj;
  char *base;
  int r30;
  int ret;
  r30 = 0;
  temp = fn_803A962C(arg0) - 0x41;
  if ((temp < 0) || (temp >= 0x1A))
  {
    obj = 0;
  }
  else
  {
    base = lbl_8053B248;
    base = base + (temp * 0x1898);
    obj = base + 0x48;
  }
  if (obj == 0)
  {
    *((int *) (lbl_8053B248 + 0x1c)) = 10;
    return 10;
  }
  if (!((*((u16 *) (obj + 0x1878))) & 1))
  {
    *((int *) (lbl_8053B248 + 0x1c)) = 10;
    return 10;
  }
  if ((arg1 != 0) && (!(arg1 & 1)))
  {
    *((int *) (lbl_8053B248 + 0x1c)) = 10;
    *((int *) (obj + 0x186c)) = 10;
    return 10;
  }
  if ((((*((u16 *) (obj + 0x1878))) >> 1) & 1) & fn_803AA514(obj))
  {
    fn_803BC090(obj);
    fn_803B1AA4(obj);
    fn_803B032C(obj);
    if (fn_803AA7D0(obj, 1) == 0)
    {
      if ((*((u16 *) (obj + 0x1878))) & 2)
      {
        *((int *) (obj + 0x1618)) = 0;
      }
      *((u16 *) (obj + 0x1878)) = (*((u16 *) (obj + 0x1878))) & (~2);
    }
    *((int *) (lbl_8053B248 + 0x10)) = (*((int *) (lbl_8053B248 + 0x10))) - 1;
  }
  if (!((*((u16 *) (obj + 0x1878))) & 2))
  {
    return 0;
  }
  if (((*((int *) (obj + 0x15e0))) != 0) || ((*((int *) (obj + 0x15e4))) != 0))
  {
    r30 = 1;
    *((int *) (lbl_8053B248 + 0x1c)) = 0x13;
    *((int *) (obj + 0x186c)) = 0x13;
    if (!(arg1 & 1))
    {
      return 0x13;
    }
  }
  ret = fn_803C0838(obj, arg1);
  if ((ret != 0) && (r30 == 0))
  {
    r30 = 1;
    *((int *) (lbl_8053B248 + 0x1c)) = ret;
    *((int *) (obj + 0x186c)) = ret;
    if (!(arg1 & 1))
    {
      r30 = ret;
    }
  }
  return r30;
}
