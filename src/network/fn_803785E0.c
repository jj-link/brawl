
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
typedef struct Inner
{
  u8 pad0[0xC];
  void *unkC;
  void *unk10;
} Inner;
typedef struct Obj
{
  u8 pad0[0x8];
  Inner *unk8;
  s32 unkC;
  s32 unk10;
  s32 unk14;
  u8 pad18[0xC];
  s32 unk24;
} Obj;
extern s32 fn_8035A590(void *);
extern u32 *fn_8035A598(void *, s32);
extern void fn_8035A918(void *, s32);
extern void fn_8035B120(void *, void *);
extern s32 fn_80374584(Obj *, u32);
s32 fn_803785E0(Obj **arg0, u32 *arg1)
{
  u32 new_var[2];
  void *sp8;
  Obj *temp_r29 = *arg0;
  s32 n;
  new_var[0] = *arg1;
  if ((temp_r29->unkC != 7) && (fn_80374584(temp_r29, new_var[0]) == 0))
  {
    return 0;
  }
  if (((temp_r29->unkC == 7) && (temp_r29->unk14 == 0)) && (temp_r29->unk24 == 0))
  {
    sp8 = temp_r29;
    if ((temp_r29->unk14 == 0) && (temp_r29->unk24 == 0))
    {
      if (temp_r29->unkC == 7)
      {
        n = fn_8035A590(temp_r29->unk8->unk10);
        for (new_var[1] = 0; ((s32) new_var[1]) < n; new_var[1]++)
        {
          if ((*fn_8035A598(((Obj *) sp8)->unk8->unk10, (s32) new_var[1])) == ((u32) sp8))
          {
            fn_8035A918(((Obj *) sp8)->unk8->unk10, (s32) new_var[1]);
            break;
          }
        }

      }
      else
      {
        fn_8035B120(temp_r29->unk8->unkC, &sp8);
      }
    }
  }
  return 1;
}
