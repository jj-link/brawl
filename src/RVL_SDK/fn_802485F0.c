#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct 
{
  u8 state;
  u8 addr[6];
  u8 pad7;
  u16 unk8;
  u8 pad0A[6];
  u8 unk10;
  u8 unk11;
  u8 unk12;
  u8 pad13;
  u16 unk14;
  u16 unk16;
  u8 pad18[2];
  u16 unk1A;
  u8 pad1C[0x18];
} Entry;
typedef struct 
{
  Entry entries[16];
  u8 pad340[4];
  u8 tail[0xBD];
  u8 level;
  u8 pad402[6];
} Global;
extern Global lbl_8052C9B8;
extern char lbl_80482490[];
extern void fn_802319E4(s32, void *);
extern void fn_802319FC(s32, void *, u8);
extern void fn_80231A14(s32, void *, u32, u32);
extern void fn_802484C0(s32, u8 *, s32);
extern void fn_80240250(void *, u32, u32, u32, s32, void (*)(s32, u8 *, s32), void *);
extern s32 fn_803F6150(void *, void *, u32);
extern void fn_8024A764(void *, u32, u16, u32, u32);
extern void fn_8024A8F4(u16, void *);
void fn_802485F0(u8 *arg0, u16 arg1, u32 arg2, u32 arg3)
{
  char *str = lbl_80482490;
  Entry *e;
  u32 new_var;
  Entry *p;
  s32 ok = 1;
  s32 i;
  if (lbl_8052C9B8.level >= 4)
  {
    new_var = arg2;
    fn_80231A14(0x1E0003, str + 0x58, new_var, arg1);
  }
  p = lbl_8052C9B8.entries;
  for (i = 0; i < 16; i++, p++)
  {
    if ((p->state != 0) && (fn_803F6150(arg0, p->addr, 6) == 0))
    {
      break;
    }
  }

  if (i == 16)
  {
    fn_8024A764(arg0, arg3, arg1, 3, 0);
    return;
  }
  e = &lbl_8052C9B8.entries[i];
  if (arg2 == 0x13)
  {
    if (e->unk14 == 0)
    {
      if (lbl_8052C9B8.level >= 2)
      {
        fn_802319E4(0x1E0001, str + 0x8C);
      }
      ok = 0;
    }
    if (e->unk10 != 2)
    {
      if (lbl_8052C9B8.level >= 2)
      {
        fn_802319FC(0x1E0001, str + 0xC0, e->unk10);
      }
      ok = 0;
    }
  }
  else
    if (e->unk10 != 0)
  {
    if (lbl_8052C9B8.level >= 2)
    {
      fn_802319FC(0x1E0001, str + 0xF0, e->unk10);
    }
    ok = 0;
  }
  if (ok == 0)
  {
    fn_8024A764(arg0, arg3, arg1, 4, 0);
    return;
  }
  if (new_var == 0x11)
  {
    e->unk11 = 0;
    e->unk14 = arg1;
    e->unk12 = arg3;
    e->unk1A = 0x100;
    e->unk10 = 6;
    fn_80240250(e->addr, 0x11, 0, 6, (-((e->unk8 >> 15) & 1)) + 2U, fn_802484C0, e);
    return;
  }
  e->unk10 = 3;
  e->unk16 = arg1;
  fn_8024A764(arg0, arg3, arg1, 0, 0);
  fn_8024A8F4(arg1, lbl_8052C9B8.tail);
  if (lbl_8052C9B8.level >= 4)
  {
    fn_80231A14(0x1E0003, str + 0x120, arg2, arg1);
  }
}
