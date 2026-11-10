
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
typedef struct Obj
{
  char pad0[0xC];
  int unkC;
  int unk10;
  int unk14;
  int unk18;
  int unk1C;
  int unk20;
  char pad24[8];
  int unk2C;
} Obj;
extern Obj *fn_80377D90(Obj *, int, int);
extern int fn_80373FDC(Obj *self, Obj *other, int a2, int a3, int a4, int a5, int a6, int a7);
extern void fn_80374778(Obj *self);
extern int fn_80373AA0(Obj *self, int a1, int a2, int a3);
extern int fn_80373C54(Obj *self, int a1);
int fn_80376CC4(Obj *arg0, int arg1, unsigned char arg2, int arg3)
{
  Obj *temp_r31;
  int flag;
  int has;
  temp_r31 = fn_80377D90(arg0, arg1, arg2);
  has = arg0->unk2C;
  if ((has != 0) && (fn_80373FDC(arg0, temp_r31, arg1, arg2, 1, 0, 0, arg3) == 0))
  {
    return 0;
  }
  if (temp_r31 == 0)
  {
    return 1;
  }
  if (temp_r31->unkC < 5)
  {
    if (temp_r31->unk10 != 0)
    {
      fn_80374778(temp_r31);
      if (fn_80373AA0(temp_r31, 6, 0, 0) == 0)
      {
        flag = 0;
        goto chk;
      }
    }
    else
    {
      if (temp_r31->unkC == 4)
      {
        temp_r31->unk14 = 1;
      }
      fn_80374778(temp_r31);
    }
  }
  else
    if (temp_r31->unkC != 7)
  {
    fn_80374778(temp_r31);
    if (fn_80373C54(temp_r31, 1) == 0)
    {
      flag = 0;
      goto chk;
    }
  }
  flag = 1;
  chk:
  return flag != 0;

}
