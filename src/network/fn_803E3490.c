
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
  u8 pad10[8];
  u16 flags;
  u8 pad1A[6];
  u8 shift;
  u8 pad21;
  u8 count;
  u8 pad23[5];
  u32 base;
  u8 pad2C[0x1F84 - 0x2C];
  s32 callbackArg;
  u8 pad1F88[0x1FC0 - 0x1F88];
  s32 (*callback)(s32);
} Context;
typedef struct 
{
  u16 pad0;
  u16 kind;
  u8 pad04[4];
  u8 *data;
  u8 pad0C[12];
  u32 position;
} Buffer;
extern s32 fn_803E9178(Context *, u8 *, u32, u32, u16);
extern s32 fn_803E8DC0(Context *, u8 *, u32, u32, u16);
s32 fn_803E3490(Context *ctx, s32 index, u32 *output, Buffer *buffer)
{
  u32 offset = ((u32) index) << 2;
  u32 position = (u16) (ctx->base + (offset >> ctx->shift));
  u32 copy = 1;
  s32 result;
  u32 i;
  u32 data;
  if ((ctx->flags & 0x80) != 0)
  {
    copy = ctx->flags & 7;
  }
  if (buffer->position != position)
  {
    if (buffer->kind == 1)
    {
 do { for (i = 0; ((u16) i) < ctx->count; i++) { fn_803E9178(ctx, buffer->data, buffer->position + (((u16) i) * ctx->stride), 0, ctx->size); } } while (0);
    }
    do
    {
      result = fn_803E8DC0(ctx, buffer->data, position, 0, ctx->size);
      if ((result == 0x1000) && (ctx->callback != 0))
      {
        s32 action = ctx->callback(ctx->callbackArg);
        if (action == 0)
        {
          continue;
        }
        if (((action == 1) && (ctx->count >= 2)) && (copy < ctx->count))
        {
          copy++;
          position += ctx->stride;
          continue;
        }
      }
      if (result != 0)
      {
        return result;
      }
      buffer->position = position;
    }
    while (result != 0);
  }
  offset = offset & (ctx->size - 1);
  data = *((u32 *) (buffer->data + offset));
  *output = (((data << 24) | ((data << 8) & 0x00FF0000)) | ((data >> 24) | ((data >> 8) & 0x0000FF00))) & 0x0FFFFFFF;
  result = 0;
  return result;
}
