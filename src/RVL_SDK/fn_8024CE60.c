
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
#pragma force_active on
extern unsigned char lbl_8052CDC0[];
extern char lbl_804839F0[];
extern void fn_80231A74(int, const char *, unsigned short, int, int, int, int, int);
void fn_8024CE60(void)
{
  u16 count;
  u16 num;
  u16 i;
  u16 val;
  u16 scaled;
  unsigned char *entry;
  u16 d;
  u16 ratio;
  int flag;
  unsigned char *base = lbl_8052CDC0;
  flag = 0;
  count = *((u16 *) (base + 0x7B8));
  if (count != 0)
  {
    if ((base[8] != 0) && (base[0x62] == 1))
    {
      flag = 1;
    }
    if ((base[0x64] != 0) && (base[0xBE] == 1))
    {
      flag += 1;
    }
    if ((base[0xC0] != 0) && (base[0x11A] == 1))
    {
      flag += 1;
    }
    if ((((long long) base[0x11C]) != 0) && (base[0x176] == 1))
    {
      flag += 1;
    }
    entry = lbl_8052CDC0 + 8;
    num = *((u16 *) (lbl_8052CDC0 + 2));
    ratio = (num / count) + 1;
    for (i = 0; i < 4; i++)
    {
      if (entry[0] != 0)
      {
        if ((flag == 0) || (entry[0x5A] == 1))
        {
          *((u16 *) (entry + 0x34)) = ratio;
          *((u16 *) (entry + 0x36)) = ratio;
        }
        else
        {
          *((u16 *) (entry + 0x34)) = 3U;
          *((u16 *) (entry + 0x36)) = 3U;
        }
        val = *((u16 *) (entry + 0x34));
        scaled = (val * 120) / 100;
        *((u16 *) (entry + 0x3A)) = scaled;
        d = (3 < scaled) ? (scaled - 3) : (0);
        *((u16 *) (entry + 0x3C)) = d;
        *((u16 *) (entry + 0x3E)) = scaled + 2;
        if (lbl_8052CDC0[0] >= 5)
        {
          fn_80231A74(0x80004, lbl_804839F0, i, entry[0x5A], *((u16 *) (entry + 0x36)), *((u16 *) (entry + 0x3A)), *((u16 *) (entry + 0x3C)), *((u16 *) (entry + 0x3E)));
        }
      }
      entry += 0x5C;
    }

  }
}
