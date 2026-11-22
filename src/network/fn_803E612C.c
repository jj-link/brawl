#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char lbl_805644C0[];
extern u8 lbl_8041B080[];
typedef struct 
{
  u8 *p;
  u8 *end;
  int unused;
  u32 mode;
} Input;
inline static u32 reverse_and_flag(u16 *out)
{
  (*((u32 (**)(u16 *, u16 *)) (lbl_805644C0 + 0x4c)))(out, out);
  return 1;
}

inline static u16 upper(u16 in, u16 *out)
{
  if ((in >= 0xff41) && (in <= 0xff5a))
  {
    *out = in - 0x20;
    return 1;
  }
  return 0;
}

u16 fn_803E612C(Input *input, int wide)
{
  u32 *new_var;
  u8 buf[3];
  u16 value;
  u16 temp;
  u16 result;
  int islower;
  u32 ch;
  u32 f;
  u32 g;
  if (input->mode == 1)
  {
    u8 *p = input->p;
    input->p = p + 1;
    buf[0] = *p;
    buf[1] = 0;
    if ((((s8) buf[0]) == 0) || (input->end < input->p))
    {
      return 0;
    }
    if ((*((int (**)(int, int)) (lbl_805644C0 + 0x54)))((s8) buf[0], 1))
    {
      buf[1] = *(input->p++);
      value = (buf[0] << 8) + buf[1];
    }
    else
      if ((((*((u32 *) (lbl_805644C0 + 0x38))) & 0x10000) || (buf[0] >= 0x80)) || ((buf[0] >= 0x20) && (lbl_8041B080[buf[0] - 0x20] & 2)))
    {
      value = (s8) buf[0];
    }
    else
    {
      value = 0x5f;
    }
    if (wide)
    {
      (*((void (**)(void *, void *)) (lbl_805644C0 + 0x48)))(buf, &value);
    }
  }
  else
  {
    buf[0] = *((u16 *) input->p);
    buf[1] = (*((u16 *) input->p)) >> 8;
    input->p += 2;
    buf[2] = 0;
    if (((((s8) buf[0]) == 0) && (((s8) buf[1]) == 0)) || (input->end < input->p))
    {
      return 0;
    }
    value = (buf[1] << 8) + buf[0];
    if (!wide)
    {
      (*((u32 (**)(u16 *, u16 *)) (lbl_805644C0 + 0x4c)))(&value, &temp);
      if ((*((int (**)(int, int)) (lbl_805644C0 + 0x54)))(temp >> 8, 1))
      {
        value = temp;
      }
      else
        if ((((*((u32 *) (lbl_805644C0 + 0x38))) & 0x10000) || (buf[0] >= 0x80)) || ((buf[0] >= 0x20) && (lbl_8041B080[buf[0] - 0x20] & 2)))
      {
        value = (s8) buf[0];
      }
      else
      {
        value = 0x5f;
      }
    }
  }
  ch = value;
  islower = 0;
  if ((ch >= 0x61) && (ch <= 0x7a))
  {
    islower = 1;
  }
  new_var = &ch;
  if (islower)
  {
    ch -= 0x20;
  }
  value = *new_var;
  if (wide)
  {
    if (upper(ch, &result) == 1)
    {
      value = result;
    }
  }
  else
  {
    (*((void (**)(void *, void *)) (lbl_805644C0 + 0x48)))(&value, &result);
    f = upper(result, &result);
    if (f == 1)
    {
      ch = reverse_and_flag(&result);
    }
    else
    {
      ch = 0;
    }
    if ((*new_var) == 1)
    {
      value = result;
    }
  }
  return value;
}
