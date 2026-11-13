#pragma force_active on

typedef enum _va_arg_type
{
  arg_ARGPOINTER,
  arg_WORD,
  arg_DOUBLEWORD,
  arg_ARGREAL
} _va_arg_type;
typedef struct __va_list_struct
{
  char gpr;
  char fpr;
  char *input_arg_area;
  char *reg_save_area;
} va_list[1];
void *__va_arg(va_list argp, int type);
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef intptr_t ptrdiff_t;
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef double f64;
typedef int UNKWORD;
typedef void UNKTYPE;
enum 
{
  FALSE,
  TRUE
};
typedef int BOOL;
typedef void (*funcptr_t)(void);
extern unsigned char lbl_804FB4A0[];
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_80234C5C(unsigned char, unsigned char);
extern void fn_8023D97C(unsigned char, void *, short *);
typedef struct 
{
  unsigned char b[0x60];
} Entry;
typedef struct 
{
  unsigned char pad[0xE4];
  Entry a[10];
  Entry b[6];
} Mgr;
inline static unsigned char getByte(int off)
{
  int level = OSDisableInterrupts();
  unsigned char v = lbl_804FB4A0[off];
  OSRestoreInterrupts(level);
  return v;
}

inline static unsigned char *getEntry(int i)
{
  unsigned char *p;
  int level = OSDisableInterrupts();
  Mgr *m = (Mgr *) lbl_804FB4A0;
  if ((i >= 0) && (i < 10))
    p = m->a[i].b;
  else
    p = m->b[i - 10].b;
  OSRestoreInterrupts(level);
  return p;
}

inline unsigned char *inline_fn(int arg0)
{
  return getEntry(arg0);
}

int fn_80229B68(void)
{
  int level;
  int i;
  unsigned char *base = lbl_804FB4A0;
  unsigned char *entry;
  struct 
  {
    short info[4];
    signed char tail;
  } d;
  level = OSDisableInterrupts();
  base[0x6EB] = 0;
  base[0x6EA] = 0;
  OSRestoreInterrupts(level);
  fn_80234C5C(0, 0);
  if (((signed char) base[0x6E8]) == 0)
  {
    return 14;
  }
  if (getByte(0x6E5) == 4)
  {
    if (getByte(0x6E4) == 4)
    {
      return 14;
    }
  }
  if (base[0x6E7] != 0)
  {
    for (i = 0; i < 16; i++)
    {
      entry = inline_fn(i);
      if (entry[0x59] == 9)
      {
        d.tail = 0;
        d.info[0] = 0;
        d.info[1] = 0;
        d.info[2] = 1;
        d.info[3] = 0;
        fn_8023D97C(lbl_804FB4A0[0x70A], entry + 0x40, d.info);
        return 1;
      }
    }

  }
  if (((signed char) base[0x6E8]) > 0)
  {
    base[0x6E8] -= 1;
  }
  *((unsigned short *) (base + 0x748)) = 0x32;
  return 29;
}
