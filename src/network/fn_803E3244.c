#include <types.h>
#pragma force_active on
typedef struct { u16 size; u8 pad02[10]; u32 stride; u8 pad10[16]; u8 shift; u8 pad21; u8 count; u8 pad23[5]; u32 base; } Context;
extern s32 fn_803E8DC0(Context *, void *, u32, u32, u16);
extern s32 fn_803E9178(Context *, void *, u32, u32, u16);
s32 fn_803E3244(Context *ctx, u32 index, u32 value)
{
    u32 data;
    u32 offset = index * 4;
    u32 position = (u16)(ctx->base + (offset >> ctx->shift));
    u16 within = offset & (ctx->size - 1);
    s32 result = fn_803E8DC0(ctx, &data, position, within, 4);
    u32 i;
    s32 error;
    u32 word;
    if (result != 0) return result;
    error = 0;
    i = 0;
    word = ((data << 24) | ((data << 8) & 0xff0000)) | ((data >> 24) | ((data >> 8) & 0xff00));
    word = (value & 0x0fffffff) | (word & 0xf0000000);
    data = ((word << 24) | ((word << 8) & 0xff0000)) | ((word >> 24) | ((word >> 8) & 0xff00));
    for (; (u16)i < ctx->count; i++) {
        result = fn_803E9178(ctx, &data, position, within, 4);
        if (result != 0 && error == 0) error = result;
        position += ctx->stride;
    }
    return error;
}