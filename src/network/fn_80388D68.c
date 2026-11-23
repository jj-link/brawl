
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
extern s32 fn_8038A298(const u8 *arg0, s32 arg1);
extern s32 fn_8038A1B0(s32 arg0, const u8 *arg1);
extern void fn_8035B078(void *arg0, s32 *arg1);
extern char lbl_8059FBB4[5];
extern int sprintf(char *, const char *, ...);
extern int fn_803FCAA4(const char *left, const char *right, int count);
extern unsigned long strlen(const char *);
extern char lbl_80490D40[];
void fn_80388D68(void *arg0, u8 *arg1, s32 arg2)
{
  u8 *key;
  s32 type;
  s32 kind;
  u8 *field;
  char *new_var;
  s32 item;
  char name[128];
  s32 pairA[2];
  s32 pairB[2];
  s32 n;
  u32 b;
  kind = 0;
  if (((s8) (*arg1)) == 0)
  {
    return;
  }
  n = fn_8038A298(arg1, arg2);
  if (n < 0)
  {
    return;
  }
  field = arg1;
  arg1 += n;
  arg2 -= n;
  if (fn_803FCAA4(lbl_80490D40, (const char *) field, (int) strlen(lbl_80490D40)) != 0)
  {
    return;
  }
  if (arg2 < 1)
  {
    return;
  }
  b = *arg1;
  new_var = ((char *) arg0) + 0x18;
  arg1++;
  arg2--;
  if ((b & 0x80) == 0x80)
  {
    kind = 1;
    b ^= 0x80;
  }
  if (b > 7)
  {
    return;
  }
  if (kind == 1)
  {
    ((u8 *) arg0)[0x28] = (u8) (((u8 *) arg0)[0x28] | ((s8) (0xff << b)));
  }
  else
  {
    ((u8 *) arg0)[0x28] = (u8) (((u8 *) arg0)[0x28] | (1 << b));
  }
  if (arg2 < 1)
  {
    return;
  }
  while (arg2 > 0)
  {
    type = *((s8 *) arg1);
    arg1++;
    arg2--;
    if (type < 0)
    {
      return;
    }
    if (type > 2)
    {
      return;
    }
    while (((s8) (*arg1)) != 0)
    {
      n = fn_8038A298(arg1, arg2);
      if (n < 0)
      {
        return;
      }
      field = arg1;
      arg1 += n;
      arg2 -= n;
      if (type == 0)
      {
        n = fn_8038A298(arg1, arg2);
        if (n < 0)
        {
          return;
        }
        key = arg1;
        arg1 += n;
        arg2 -= n;
        pairA[0] = fn_8038A1B0(0, field);
        pairA[1] = fn_8038A1B0(0, key);
        fn_8035B078(*((void **) new_var), pairA);
      }
      else
      {
        if (arg2 < 1)
        {
          return;
        }
        item = *((s8 *) arg1);
        arg1++;
        arg2--;
        while (((s8) (*arg1)) != 0)
        {
          n = fn_8038A298(arg1, arg2);
          if (n < 0)
          {
            return;
          }
          key = arg1;
          arg1 += n;
          arg2 -= n;
          sprintf(name, lbl_8059FBB4, field, item);
          pairB[0] = fn_8038A1B0(0, (const u8 *) name);
          pairB[1] = fn_8038A1B0(0, key);
          fn_8035B078(*((void **) new_var), pairB);
          item++;
        }

        if (arg2 > 0)
        {
          arg1++;
          arg2--;
        }
      }
    }

    if (arg2 > 0)
    {
      if (((s8) (*arg1)) != 0)
      {
        return;
      }
      arg1++;
      arg2--;
    }
  }

}
