
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
typedef struct 
{
  u16 size;
  u8 pad02[10];
  u32 stride;
  u8 pad10[16];
  u8 shift;
  u8 pad21;
  u8 count;
  u8 pad23[5];
  u32 base;
} Context;
extern s32 fn_803E8DC0(Context *, void *, u32, u32, u16);
extern s32 fn_803E9178(Context *, void *, u32, u32, u16);
inline int inline_fn(Context *arg0)
{
  return arg0->size - 1;
}

s32 fn_803E25FC(Context *ctx, s32 index, u32 value)
{
  u8 data[2];
  u16 offset;
  u16 within = inline_fn(ctx) & (offset = index + (index >> 1));
  u16 position = ctx->base + (((s32) offset) >> ctx->shift);
  u32 i;
  s32 result;
  s32 error;
  u16 word;
  offset = (s32) offset;
  if (index & 1)
  {
    result = fn_803E8DC0(ctx, data, position, within, 1);
    if (result != 0)
    {
      return result;
    }
    word = (((u16) value) << 4) + (data[0] & 0xF);
  }
  else
  {
    result = fn_803E8DC0(ctx, data, (u16) (ctx->base + ((offset + 1) >> ctx->shift)), (u16) ((offset + 1) & inline_fn(ctx)), 1);
    if (result != 0)
    {
      return result;
    }
    word = ((data[0] << 8) & 0xF000) + (value & 0xFFF);
  }
  within = (u16) within;
  __sthbrx(word, data, 0);
  error = 0;
  i = 0;
  for (; ((u16) i) < ctx->count; i++)
  {
    if (within < inline_fn(ctx))
    {
      result = fn_803E9178(ctx, data, position, within, 2);
      if ((result != 0) && (error == 0))
      {
        error = result;
      }
    }
    else
    {
      result = fn_803E9178(ctx, data, position, within, 1);
      if ((result != 0) && (error == 0))
      {
        error = result;
      }
      result = fn_803E9178(ctx, &data[1], position + 1, 0, 1);
      if ((result != 0) && (error == 0))
      {
        error = result;
      }
    }
    position += ctx->stride;
  }

  return error;
}
