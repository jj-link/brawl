
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
inline static void swap(u8 *a, u8 *b)
{
  u8 t = *a;
  *a = *b;
  *b = t;
}

void fn_803A9958(u8 *p, u32 n)
{
  u8 *new_var2[2];
  u32 i;
  for (i = 0; i < n; i += 2)
  {
    new_var2[0] = p + i;
    new_var2[1] = new_var2[0] + 1;
    swap(new_var2[0], new_var2[1]);
  }

}
