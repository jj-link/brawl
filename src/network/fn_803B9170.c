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
typedef struct Context
{
  u16 size;
  u8 pad02[10];
  u32 stride;
  u8 pad10[8];
  u16 flags;
  u8 pad1a[6];
  u8 shift;
  u8 pad21;
  u8 count;
  u8 pad23[5];
  u32 base;
  u8 pad2c[8];
  u32 total;
  u8 pad38[0x1600 - 0x38];
  u32 span;
  u8 pad1604[0x1870 - 0x1604];
  void *cbarg;
  u8 pad1874[0x1890 - 0x1874];
  s32 (*cb)(void *);
} Context;
typedef struct Buffer
{
  u16 unk0;
  u16 state;
  u8 *start;
  u8 *cur;
  u8 pad0c[12];
  u32 sector;
} Buffer;
extern s32 fn_803B6F80(Context *);
extern s32 fn_803AFEDC(Context *, u32, Buffer **);
s32 fn_803B9170(Context *ctx, u32 index, s32 *out, Buffer **buf)
{
  u8 *cur;
  Buffer *p;
  u32 offset;
  u16 flags;
  u8 shift;
  u32 start;
  s32 result = 0;
  u32 sector;
  u32 retry;
  s32 r;
  u32 value;
  if (ctx == 0)
  {
    return 10;
  }
  if ((((index < 2) || (index >= (ctx->total + 2))) && (index != 0)) && (index != 1))
  {
    return 14;
  }
  flags = ctx->flags;
  offset = index * 2;
  shift = ctx->shift;
  retry = 1;
  sector = (u16) (ctx->base + (offset >> shift));
  if (flags & 0x80)
  {
    retry = flags & 7;
  }
  start = (*buf)->sector;
  p = *buf;
  if ((start > sector) || ((start + ctx->span) <= sector))
  {
    if (p->state == 1)
    {
      r = fn_803B6F80(ctx);
      if (r != 0)
      {
        return r;
      }
    }
    do
    {
      result = fn_803AFEDC(ctx, sector, buf);
      if ((result == 0x1000) && (ctx->cb != 0))
      {
        r = ctx->cb(ctx->cbarg);
        if (r == 0)
        {
          continue;
        }
        if (((r == 1) && (ctx->count >= 2)) && (retry < ctx->count))
        {
          retry++;
          sector += ctx->stride;
          continue;
        }
      }
      if (result != 0)
      {
        return result;
      }
    }
    while (result != 0);
  }
  else
    if (sector != (start + (((cur = p->cur) - p->start) >> shift)))
  {
    p->cur = cur + ctx->size;
  }
  value = ctx->size - 1;
  value = *((u16 *) ((*buf)->cur + (offset & value)));
  *out = ((value >> 8) & 0xFF) | ((value << 8) & 0xFF00);
  return result;
}
