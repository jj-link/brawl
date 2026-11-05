#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Context {
    u16 size;               /* 0x00 */
    u8 pad02[10];
    u32 stride;             /* 0x0C */
    u8 pad10[8];
    u16 flags;              /* 0x18 */
    u8 pad1A[6];
    u8 shift;               /* 0x20 */
    u8 pad21;
    u8 count;               /* 0x22 */
    u8 pad23[5];
    u32 base;               /* 0x28 */
    u8 pad2C[0x1F84 - 0x2C];
    void *cbArg;            /* 0x1F84 */
    u8 pad1F88[0x1FC0 - 0x1F88];
    s32 (*cb)(void *);      /* 0x1FC0 */
} Context;

extern s32 fn_803E8DC0(Context *, u16 *, u32, u32, u16);

s32 fn_803E2CDC(Context *ctx, s32 index, s32 *out)
{
    u16 value;
    u32 position = (u16)(ctx->base + (((u32)index << 1) >> ctx->shift));
    u16 within = (((u32)index << 1)) & (ctx->size - 1);
    s32 result;
    u32 retry = 1;

    if (ctx->flags & 0x80) {
        retry = ctx->flags & 7;
    }

    do {
        result = fn_803E8DC0(ctx, &value, position, within, 2);
        if (result == 0x1000 && ctx->cb != 0) {
            s32 r = ctx->cb(ctx->cbArg);
            if (r == 0) {
                continue;
            }
            if (r == 1 && ctx->count >= 2 && retry < ctx->count) {
                retry++;
                position += ctx->stride;
                continue;
            }
        }
        if (result != 0) {
            *out = -1;
            return result;
        }
    } while (result != 0);
    *out = ((value >> 8) & 0xFF) | ((value & 0xFF) << 8);
    return 0;
}
