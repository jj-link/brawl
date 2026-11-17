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
void *memset(void *, int, unsigned long);
void fn_80260DC4(unsigned int *arg0, int arg1, int arg2, unsigned char *arg3)
{
  unsigned int new_var;
  unsigned char *a;
  unsigned char *b;
  int new_var2;
  unsigned char *c;
  if (arg1 == 0)
  {
    switch (arg2)
    {
      case 0:
        a = arg3 + 0x460;
        b = arg3 + 0x1570;
        c = arg3 + 0x1460;
        arg0[0] = (unsigned int) a;
        arg0[2] = (unsigned int) b;
        arg0[1] = (unsigned int) c;
        arg3[0x1794] = 1;
        memset(a, 0, 0x400);
        memset(arg3 + 0x1570, 0, 0x10);
        memset(arg3 + 0x1460, 0, 0x44);
        break;

      case 1:
        a = arg3 + 0x860;
        b = arg3 + 0x1580;
        c = arg3 + 0x14A4;
        arg0[0] = (unsigned int) a;
        arg0[2] = (unsigned int) b;
        arg0[1] = (unsigned int) c;
        arg3[0x1795] = 1;
        new_var2 = 0x400;
        memset(a, 0, new_var2);
        memset(arg3 + 0x1580, 0, 0x10);
        memset(arg3 + 0x14A4, 0, 0x44);
        break;

    }

  }
  else
  {
    switch (arg2)
    {
      case 0:
        a = arg3 + 0xC60;
        b = arg3 + 0x1590;
        c = arg3 + 0x14E8;
        arg0[0] = (unsigned int) a;
        arg0[2] = (new_var = (unsigned int) b);
        arg0[1] = (unsigned int) c;
        arg3[0x1796] = 1;
        memset(a, 0, 0x400);
        memset(arg3 + 0x1590, 0, 0x100);
        memset(arg3 + 0x14E8, 0, 0x44);
        break;

      case 1:
        a = arg3 + 0x1060;
        b = arg3 + 0x1690;
        c = arg3 + 0x152C;
        arg0[0] = (unsigned int) a;
        arg0[2] = (unsigned int) b;
        arg0[1] = (unsigned int) c;
        arg3[0x1797] = 1;
        memset(a, 0, 0x400);
        memset(arg3 + 0x1690, 0, 0x100);
        memset(arg3 + 0x152C, (float) 0, 0x44);
        break;

    }

  }
}
