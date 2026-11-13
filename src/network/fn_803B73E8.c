
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
s32 fn_803B6A08(void *, void *, s32, u32, s32 *);
s32 fn_803B73E8(u8 *arg0, u32 arg1, s32 *arg2)
{
  s32 temp_r3;
  s32 temp_r8;
  s32 temp_r8_2;
  s32 *new_var;
  s32 temp_r9_2;
  s32 var_r5;
  void *var_r11;
  u32 var_r6;
  u8 temp_r0;
  u32 *temp_r8_5;
  void *temp_r10;
  void **new_var2;
  void *temp_r8_3;
  void *temp_r6;
  var_r6 = arg1;
  *arg2 = 0;
  if (arg0 == 0)
  {
    return 0xA;
  }
  temp_r6 = *((void **) (arg0 + 0x30));
  if (temp_r6 == 0)
  {
    return 0xA;
  }
  temp_r8 = *((s32 *) arg0);
  if (temp_r8 == 0)
  {
    return 0xA;
  }
  if ((*((u32 *) (((u8 *) temp_r6) + 8))) > ((u32) temp_r8))
  {
    return 0xA;
  }
  temp_r10 = *((void **) (arg0 + 0x34));
  temp_r0 = *((u8 *) (((u8 *) temp_r10) + 0x187A));
  if ((((s8) temp_r0) < 0x41) || (((s8) temp_r0) > 0x5A))
  {
    return 0x23;
  }
  temp_r8_5 = *((u32 **) (arg0 + 8));
  var_r11 = *((void **) temp_r8_5);
  if (((u32) var_r11) < 2)
  {
    return 0;
  }
  if ((*((s32 *) (arg0 + 0xC))) != 0)
  {
    *arg2 = (*((s32 *) (arg0 + 0x10))) + 1;
    return 0;
  }
  new_var = (s32 *) (((u8 *) temp_r6) + 4);
  new_var2 = &temp_r6;
  if ((*new_var) != 0)
  {
    temp_r8_2 = *((s32 *) temp_r6);
    temp_r9_2 = temp_r8_2 + 1;
    var_r6 = arg1;
    if (arg1 <= ((u32) (temp_r9_2 << ((*((u8 *) (((u8 *) temp_r10) + 0x20))) + (*((u8 *) (((u8 *) (*((void **) (arg0 + 0x34)))) + 0x21)))))))
    {
      *arg2 = temp_r9_2;
      return 0;
    }
    *arg2 = temp_r8_2;
    temp_r6 = *((void **) (arg0 + 0x30));
    temp_r8_3 = *((void **) (arg0 + 0x34));
    temp_r8 = *((s32 *) temp_r6);
    var_r11 = *((void **) (((u8 *) (*new_var2)) + 4));
    var_r5 = temp_r8 + 1;
    var_r6 = arg1 - (temp_r8 << ((*((u8 *) (((u8 *) temp_r8_3) + 0x20))) + (*((u8 *) (((u8 *) temp_r8_3) + 0x21)))));
  }
  else
  {
    var_r5 = 1;
  }
  temp_r3 = fn_803B6A08(arg0, var_r11, var_r5, var_r6, arg2);
  if (temp_r3 != 0)
  {
    return temp_r3;
  }
  return 0;
}
