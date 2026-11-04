#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
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

extern s32 fn_803E8DC0(Context *, u8 *, u32, u32, u16);

s32 fn_803E3120(Context *ctx, u32 index, u32 *output)
{
    u32 data;
    u32 offset = index * 4;
    u32 position = (u16)(ctx->base + (offset >> ctx->shift));
    u16 within = offset & (ctx->size - 1);
    s32 result;
    u32 copy = 1;

    if (ctx->flags & 0x80) {
        copy = ctx->flags & 7;
    }
    do {
        result = fn_803E8DC0(ctx, (u8 *)&data, position, within, 4);
        if (result == 0x1000 && ctx->callback != 0) {
            s32 action = ctx->callback(ctx->callbackArg);
            if (action == 0) {
                goto retry;
            }
            if (action == 1 && ctx->count >= 2 && copy < ctx->count) {
                ++copy;
                position += ctx->stride;
                goto retry;
            }
        }
        if (result != 0) {
            *output = -1;
            return result;
        }
retry:
        ;
    } while (result != 0);

    *output = (((data << 24) | ((data << 8) & 0x00FF0000)) |
               ((data >> 24) | ((data >> 8) & 0x0000FF00))) & 0x0FFFFFFF;
    return 0;
}
