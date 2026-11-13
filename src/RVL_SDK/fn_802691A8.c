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
typedef struct Ctx
{
  u8 pad0[0x30];
  u16 unk30;
  u16 unk32;
  u8 pad1[0x14];
  u32 unk48;
  u32 unk4C;
  u8 pad2[0x14];
  void *unk64;
} Ctx;
void fn_802691A8(Ctx *arg0)
{
  u16 *buf;
  u32 bpr;
  u32 y;
  u32 x;
  bpr = ((u32) arg0->unk48) >> 2;
  buf = (u16 *) arg0->unk64;
  arg0->unk4C++;
  arg0->unk4C--;
  for (y = 0; y < arg0->unk32; y++)
  {
    for (x = arg0->unk30; x < ((u32) arg0->unk48); x++)
    {
      buf[(((((y >> 2) * bpr) + (x >> 2)) * 16) + ((y & 3) << 2)) + (x & 3)] = (u16) 0xFFFF;
    }

  }

  for (y = arg0->unk32; y < arg0->unk4C; y++)
  {
    for (x = 0; x < ((u32) arg0->unk48); x++)
    {
      buf[(((((y >> 2) * bpr) + (x >> 2)) * 16) + ((y & 3) << 2)) + (x & 3)] = (u16) 0xFFFF;
    }

  }

}
