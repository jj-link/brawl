
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
extern u16 fn_80238E78(const void *arg0);
extern void fn_80231A14(s32, const char *, s32, u8);
extern void fn_80231A74(s32, const char *, s32, s32, u16, u16, u8, u16);
extern void fn_80239A24(s32);
extern u8 fn_80244BEC(u16, s32);
extern u8 fn_8024567C(u16, s32, s32, u16, u16, u8, u16);
extern char lbl_80529CF8[];
extern char lbl_804812A4[];
extern char lbl_80481254[];
void fn_8023E774(s32 arg0, u32 arg1, s32 arg2)
{
  u32 i;
  u8 *e;
  unsigned char new_var2;
  s32 r;
  u16 v;
  u32 status;
  u16 new_var;
  u16 new_var3;
  u16 handle;
  i = 0;
  e = (u8 *) (lbl_80529CF8 + 0x1854);
  while (i < 3)
  {
    if ((((*((u16 *) (((u8 *) e) + 8))) == 6) && (arg2 == 0)) && (arg0 == 0))
    {
      handle = fn_80238E78(e + 0x28);
      if (arg1 == handle)
      {
        if ((*((u8 *) (((u8 *) lbl_80529CF8) + 0x27C0))) >= 3)
        {
          fn_80231A14(0xD0002, lbl_804812A4, (s32) handle, *((u8 *) (((u8 *) lbl_80529CF8) + 0x1909)));
        }
        fn_80239A24(1);
        if ((*((u8 *) (((u8 *) lbl_80529CF8) + 0x1908))) == 0)
        {
          if (fn_80244BEC(handle, ((*((u16 *) (((u8 *) e) + 0x20))) << 5) & 0xE0) == 0)
          {
            status = 3;
          }
          else
          {
            goto store_v;
          }
        }
        else
        {
          new_var2 = 0x20;
          new_var = *((u16 *) (((u8 *) lbl_80529CF8) + 0x656));
          new_var3 = *((u16 *) (((u8 *) e) + new_var2));
          v = (new_var3 & new_var) & 0x3F;
          if ((*((u8 *) (((u8 *) lbl_80529CF8) + 0x636))) >= 3)
          {
            v |= (new_var3 | new_var) & 0x3C0;
          }
          if ((*((u8 *) (((u8 *) lbl_80529CF8) + 0x27C0))) >= 3)
          {
            fn_80231A74(0xD0002, lbl_80481254, *((s32 *) (((u8 *) e) + 0x14)), *((s32 *) (((u8 *) e) + 0x18)), *((u16 *) (((u8 *) e) + 0x1C)), *((u16 *) (((u8 *) e) + 0x1E)), *((u8 *) (((u8 *) e) + 0x22)), v);
          }
          if (fn_8024567C(handle, *((s32 *) (((u8 *) e) + 0x14)), *((s32 *) (((u8 *) e) + 0x18)), *((u16 *) (((u8 *) e) + 0x1C)), *((u16 *) (((u8 *) e) + 0x1E)), *((u8 *) (((u8 *) e) + 0x22)), (u32) v) == 0)
          {
            status = 3;
          }
          else
          {
            *((u16 *) (((u8 *) e) + new_var2)) = v;
            store_v:
            status = 1;

          }
        }
        if (status == 1)
        {
          *((u16 *) (((u8 *) e) + 8)) = 3;
        }
      }
    }
    i++;
    e += 0x34;
  }

}
