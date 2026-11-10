
#pragma force_active on
extern void fn_80232020(void *);
extern int fn_8024841C(unsigned int);
extern void fn_8024A2D8(void);
extern unsigned char lbl_8052C9B8[0x408];
int fn_80247B1C(void)
{
  unsigned char *entry;
  unsigned char i;
  if (lbl_8052C9B8[0x400] == 0)
  {
    return 1;
  }
  for (i = 0; i < 0x10; i++)
  {
    if (((lbl_8052C9B8[0x400] != 0) && (i <= 0x10)) && (lbl_8052C9B8[i * 0x34] != 0))
    {
      entry = &lbl_8052C9B8[i * 0x34];
      if (((lbl_8052C9B8[0x400] != 0) && (i <= 0x10)) && (lbl_8052C9B8[i * 0x34] != 0))
      {
        entry[0xC] = 1;
        fn_80232020(entry + 0x1C);
        if (lbl_8052C9B8[(i * 0x34) + 0xA] == 1)
        {
          entry = &lbl_8052C9B8[i * 0x34];
          entry[0xC] = 1;
          fn_8024841C(i);
        }
      }
      entry[0] = 0;
      entry[0x10] = 0;
      *((unsigned short *) (entry + 0x16)) = 0;
      *((unsigned short *) (entry + 0x14)) = 0;
    }
  }

  fn_8024A2D8();
  lbl_8052C9B8[0x400] = 0;
  return 0;
}
