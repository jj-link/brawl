#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct Ctx
{
  u16 size;
  u8 pad002[10];
  u32 stride;
  u8 pad010[8];
  u16 flags;
  u8 pad01A[6];
  u8 shift;
  u8 pad021;
  u8 count;
  u8 pad023[5];
  u32 base;
  u8 pad02C[0x1F84 - 0x2C];
  u32 cbArg;
  u8 pad1F88[0x1FC0 - 0x1F88];
  s32 (*cb)(u32);
} Ctx;
typedef struct Buf
{
  u8 pad00[2];
  u16 type;
  u8 pad04[4];
  u8 *data;
  u8 pad0C[12];
  u32 pos;
} Buf;
extern s32 fn_803E8DC0(Ctx *, u8 *, u32, u32, u16);
extern s32 fn_803E9178(Ctx *, u8 *, u32, u32, u16);
inline static u32 rd16(u8 *p)
{
  u16 v = *((u16 *) p);
  return ((v >> 8) & 0xFF) | ((v << 8) & 0xFF00);
}

s32 fn_803E2FB0(Ctx *ctx, s32 idx, u32 *out, Buf *buf)
{
  u32 off = idx * 2;
  long new_var;
  u32 pos;
  u32 n = 1;
  s32 r;
  u16 i;
  pos = (u16) (ctx->base + (off >> ctx->shift));
  if (ctx->flags & 0x80)
  {
    n = ctx->flags & 7;
  }
  if (buf->pos != pos)
  {
    if (buf->type == 1)
    {
      for (i = 0; i < ctx->count; i++)
      {
        fn_803E9178(ctx, buf->data, buf->pos + (i * ctx->stride), 0, ctx->size);
      }

    }
    do
    {
      r = fn_803E8DC0(ctx, buf->data, pos, 0, ctx->size);
      if ((r == 0x1000) && (ctx->cb != 0))
      {
        s32 c = ctx->cb(ctx->cbArg);
        if (c == 0)
        {
          continue;
        }
        if (((c == 1) && (ctx->count >= 2)) && (n < ctx->count))
        {
          n++;
          pos += ctx->stride;
          continue;
        }
      }
      if (r != 0)
      {
        return r;
      }
      buf->pos = pos;
    }
    while (r != 0);
  }
  new_var = ctx->size;
  new_var = off & (new_var - 1);
  *out = rd16(buf->data + new_var);
  return 0;
}
