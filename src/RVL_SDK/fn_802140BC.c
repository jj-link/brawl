
#pragma force_active on
typedef unsigned int u32;
typedef struct Request
{
  void *unk0;
  int unk4;
  void *unk8;
  int unkC;
  int unk10;
  int unk14;
  void *unk18;
  int unk1C;
} Request;
extern int lbl_8059ECD0;
extern int lbl_805A0C1C;
extern u32 fn_80211AF8(const char *, u32);
extern Request *fn_802137A4(int, int, int);
extern void fn_802137A8(int, void *);
extern int fn_80213090(int, int, int, int, void *);
extern void *memcpy(void *, const void *, unsigned int);
int fn_802140BC(const char *name, int arg1, int *arg2)
{
  char *buf;
  Request *request = 0;
  int result;
  Request *new_var;
  u32 length;
  int r5;
  int r6;
  int *buf2;
  if (((((name == 0) || (arg2 == 0)) || (lbl_8059ECD0 < 0)) || (arg1 & 0x1F)) || ((length = fn_80211AF8(name, 0x40)) == 0x40))
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
      buf = ((char *) request) + 0x20;
      buf = (char *) ((((u32) buf) + 0x1F) & 0xFFFFFFE0);
      new_var = request;
      memcpy(buf, name, length + 1);
      new_var->unk0 = buf;
      new_var->unk4 = 0x40;
      buf2 = (int *) (buf + 0x40);
      buf2 = (int *) ((((u32) buf2) + 0x1F) & 0xFFFFFFE0);
      request->unk8 = buf2;
      new_var->unkC = 4;
      if (arg1 != 0)
      {
        r5 = 2;
        r6 = 2;
        *buf2 = *arg2;
        request->unk10 = arg1;
        request->unk14 = (*arg2) * 0xD;
        request->unk18 = buf2;
        new_var->unk1C = 4;
      }
      else
      {
        r5 = 1;
        r6 = 1;
      }
      result = fn_80213090(lbl_8059ECD0, 4, r5, r6, new_var);
      if (result == 0)
      {
        *arg2 = *buf2;
      }
    }
  }
  if (new_var != 0)
  {
    if (request != 0)
    {
      fn_802137A8(lbl_805A0C1C, request);
    }
  }
  return result;
}
