
#pragma force_active on
typedef unsigned int u32;
typedef struct Request
{
  void *unk0;
  int unk4;
  void *unk8;
  int unkC;
  void *unk10;
  int unk14;
} Request;
extern int lbl_8059ECD0;
extern int lbl_805A0C1C;
extern u32 fn_80211AF8(const char *, u32);
extern Request *fn_802137A4(int, int, int);
extern void fn_802137A8(int, void *);
extern int fn_80213090(int, int, int, int, void *);
extern void *memcpy(void *, const void *, unsigned int);
int fn_80214A98(const char *name, int *a, int *b)
{
  const char *n = name;
  Request *new_var;
  int result;
  u32 p1;
  int *p2;
  Request *request;
  u32 buf;
  u32 length;
  request = 0;
  if (((((n == 0) || (lbl_8059ECD0 < 0)) || (a == 0)) || (b == 0)) || ((length = fn_80211AF8(n, 0x40)) == 0x40))
  {
    result = -101;
  }
  else
  {
    request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (request == 0)
    {
      result = -22;
    }
    else
    {
      new_var = request;
      buf = (((u32) request) + 0x37) & 0xFFFFFFE0;
      memcpy((void *) buf, n, length + 1);
      new_var->unk0 = (void *) buf;
      new_var->unk4 = 0x40;
      p1 = (buf + 0x5F) & 0xFFFFFFE0;
      new_var->unk8 = (void *) p1;
      p2 = (int *) ((p1 + 0x23) & 0xFFFFFFE0);
      new_var->unkC = 4;
      new_var->unk10 = p2;
      new_var->unk14 = 4;
      result = fn_80213090(lbl_8059ECD0, 0xC, 1, 2, request);
      if (result == 0)
      {
        *a = *((int *) p1);
        *b = *p2;
      }
    }
  }
  if (request != 0)
  {
    if (new_var != 0)
    {
      fn_802137A8(lbl_805A0C1C, request);
    }
  }
  return result;
}
