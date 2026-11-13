#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Callback)(void);
extern void fn_8026E9B4(void);
extern void fn_8026EEF8(void);
extern void fn_8026EBE4(void);
extern void fn_8026F0E0(void);
extern void fn_8026ED68(void);
extern void fn_8026F2CC(void);
inline char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

int fn_8026E8C0(void *arg0, void *arg1)
{
  switch (*((u8 *) (inline_fn(arg1) + 0x2E)))
  {
    case 0:
      *((Callback *) (inline_fn(arg0) + 0xAC)) = fn_8026E9B4;
      *((Callback *) (inline_fn(arg0) + 0xB0)) = fn_8026EEF8;
      break;

    case 1:
      *((Callback *) (inline_fn(arg0) + 0xAC)) = fn_8026EBE4;
      *((Callback *) (inline_fn(arg0) + 0xB0)) = fn_8026F0E0;
      break;

    case 2:
      *((Callback *) (inline_fn(arg0) + 0xAC)) = fn_8026ED68;
      *((Callback *) (inline_fn(arg0) + 0xB0)) = fn_8026F2CC;
      break;

    default:
      return -112;

  }

  {
    u16 w = *((u16 *) (inline_fn(arg1) + 0x30));
    u16 h = *((u16 *) (inline_fn(arg1) + 0x32));
    int hq = h / 4;
    int hr = (h % 4) != 0;
    *((int *) (inline_fn(arg1) + 0x48)) = ((w / 4) + ((w % 4) != 0)) * 4;
    *((int *) (inline_fn(arg1) + 0x4C)) = hr;
    *((int *) (inline_fn(arg1) + 0x4C)) = ((*((int *) (inline_fn(arg1) + 0x4C))) + hq) * 4;
  }
  return 0;
}
