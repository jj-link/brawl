
#pragma force_active on
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, int, int);
extern int fn_80398A08(int, int, void *);
extern int lbl_8059FDE8;
extern int lbl_805A1170;
int fn_803A3FA0(int arg0, unsigned int arg1)
{
  unsigned char context[0xA0];
  unsigned char *tbl;
  unsigned char *b0;
  unsigned char *b1;
  unsigned char *new_var;
  unsigned char *b2;
  int *new_var2;
  int result;
  int op_result;
  int close_result;
  unsigned int count;
  tbl = (unsigned char *) lbl_805A1170;
  b0 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
  new_var = tbl;
  if (b0 == 0)
  {
    return -9;
  }
  b1 = (new_var != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
  count = *((unsigned short *) (b1 + 0x14));
  if ((arg1 >= count) || (arg1 == 0xFFFF))
  {
    result = -3;
  }
  else
  {
    b2 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
    result = 0;
    if ((*((int *) ((b2 + ((arg1 * 0x10) & 0xFFFF0)) + 0x80))) == 0)
    {
      result = -0xD;
    }
  }
  if (result < 0)
  {
    return result;
  }
  result = fn_8039832C(context, lbl_8059FDE8, 0xA);
  if (result < 0)
  {
    return result;
  }
  tbl = (unsigned char *) lbl_805A1170;
  b1 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
  count = *((unsigned short *) (b1 + 0x14));
  new_var2 = &arg0;
  if ((count > 0x78) || (arg1 >= count))
  {
    result = -3;
  }
  else
  {
    result = fn_80398818(context, ((arg1 << 9) & 0x01FFFE00) + 0x800, 0);
  }
  if (result < 0)
  {
    op_result = result;
  }
  else
  {
    result = fn_80398A08(*new_var2, 0x200, context);
    op_result = 0;
    if (result < 0)
    {
      op_result = result;
    }
  }
  close_result = fn_80398680(context);
  if (op_result != 0)
  {
    close_result = op_result;
  }
  return close_result;
}
