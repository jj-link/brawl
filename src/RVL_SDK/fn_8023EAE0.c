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
extern unsigned char lbl_80529CF8[];
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_8023EF88(unsigned short, void *);
void fn_8023EAE0(unsigned short arg0, void *arg1, short arg2, void *arg3)
{
  unsigned char *entry;
  int i;
  unsigned short status;
  unsigned short *new_var;
  unsigned short flag;
  int addr;
  unsigned short b;
  unsigned short a;
  struct 
  {
    unsigned short x;
    unsigned short y;
    unsigned char z;
  } temp;
  *((unsigned short *) (lbl_80529CF8 + 0x18F6)) = arg0;
  entry = lbl_80529CF8 + 0x1854;
  flag = 0;
  i = 0;
  for (;;)
  {
    status = *((unsigned short *) (entry + 8));
    if (((unsigned short) (status + 0xFFFF)) > 2)
    {
      goto next;
    }
    if ((*((unsigned char *) (entry + 0xD))) == 0)
    {
      goto next;
    }
    if ((arg1 != 0) && (fn_803F6150(entry + 0x28, arg1, 6) != 0))
    {
      goto next;
    }
    if (arg0 != 0)
    {
      if (status == 3)
      {
        if (arg0 == 0x23)
        {
          return;
        }
        *((unsigned short *) (entry + 8)) = 0;
        addr = *((int *) (entry + 4));
        ((void (*)(int)) addr)((unsigned short) i);
        return;
      }
      *((unsigned short *) (entry + 8)) = 1;
      return;
    }
    if (status == 1)
    {
      flag = 1;
    }
    *((unsigned short *) (entry + 8)) = 4;
    *((unsigned short *) (entry + 0xA)) = (unsigned short) arg2;
    if (lbl_80529CF8[0x1908] == 0)
    {
      *((unsigned char *) (entry + 0x2E)) = 0;
      if (flag != 0)
      {
        temp.y = *((unsigned short *) (entry + 0x20));
        temp.x = *((unsigned short *) (entry + 0x1C));
        temp.z = *((unsigned char *) (entry + 0x22));
        fn_8023EF88((unsigned short) i, &temp);
      }
    }
    else
      if (arg3 != 0)
    {
      a = *((unsigned short *) (((unsigned char *) arg3) + 0));
      b = *((unsigned short *) (((unsigned char *) arg3) + 2));
      *((unsigned short *) (entry + 0x24)) = a;
      *((unsigned short *) (entry + 0x26)) = b;
      a = *((unsigned short *) (((unsigned char *) arg3) + 4));
      b = a;
      a = *((unsigned short *) (((unsigned char *) arg3) + 6));
      new_var = (unsigned short *) (entry + 0x2A);
      *((unsigned short *) (entry + 0x28)) = b;
      *new_var = a;
      *((unsigned short *) (entry + 0x2C)) = *((unsigned short *) (((unsigned char *) arg3) + 8));
      *((unsigned short *) (entry + 0x2E)) = *((unsigned short *) (((unsigned char *) arg3) + 0xA));
      *((unsigned short *) (entry + 0x30)) = *((unsigned short *) (((unsigned char *) arg3) + 0xC));
    }
    addr = *((int *) entry);
    ((void (*)(int)) addr)((unsigned short) i);
    return;
    next:
    i++;

    entry += 0x34;
    if (((unsigned) i) >= 3U)
    {
      return;
    }
  }

}
