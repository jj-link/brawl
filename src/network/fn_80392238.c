#pragma force_active on

extern int fn_803A75E4(int a, int b, int c, int d);
extern void fn_8039272C(void *a, char *b, int c);
extern void fn_80392738(void *a, int b);
struct NetworkState
{
  char pad[0x8040];
  int field_8040;
  int field_8044;
};
inline int *inline_fn(struct NetworkState *arg0)
{
  return (int *) (((char *) arg0) + 0x8040);
}

int fn_80392238(struct NetworkState *arg0, int arg1, void *arg2, unsigned int arg3, int arg4, int arg5)
{
  unsigned char *base;
  int ret;
  int result;
  int new_var2;
  unsigned int new_var;
  base = ((unsigned char *) arg0) + 0x40;
  result = 0;
  if (((int) arg3) > 0)
  {
    if (arg0->field_8044 == 0)
    {
      ret = fn_803A75E4(arg1, (int) base, 0x8000, arg4);
      if (ret > 0)
      {
        arg0->field_8044 = ret;
        arg0->field_8040 = 0;
      }
      else
      {
        return ret;
      }
    }
    if (arg0->field_8044 != 0)
    {
      if (arg3 > ((unsigned) arg0->field_8044))
      {
        arg3 = (unsigned) arg0->field_8044;
      }
      new_var2 = (int) arg3;
      fn_8039272C(arg2, (char *) ((*inline_fn(arg0)) + base), new_var2);
      arg0->field_8044 -= new_var2;
      if (arg0->field_8044 == 0)
      {
        fn_80392738(base, 0x8000);
        arg0->field_8040 = 0;
      }
      else
      {
        arg0->field_8040 += new_var2;
      }
      result = new_var2;
    }
  }
  if (!(new_var = arg3))
  {
  }
  return result;
}
