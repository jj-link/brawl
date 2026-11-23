#pragma force_active on
#include <types.h>

typedef struct {
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

typedef struct {
    u8 pad00[8];
    u8 *data;
    u8 pad0C[12];
    u32 position;
} Buffer;

extern s32 fn_803E9178(Context *, u8 *, u32, u32, u16);
extern s32 fn_803E8DC0(Context *, u8 *, u32, u32, u16);

static u32 bswap32(u32 x)
{
    return (x >> 24) | ((x >> 8) & 0xFF00) |
           ((x << 8) & 0xFF0000) | (x << 24);
}

static inline void store_value(Buffer *buffer, u16 within, u32 value)
{
    u32 old = *(u32 *)(buffer->data + within);
    u32 swapped = bswap32(old);
    swapped = (value & 0x0FFFFFFF) | (swapped & 0xF0000000);
    *(u32 *)(buffer->data + within) = bswap32(swapped);
}

static inline s32 do_write(Buffer *buffer, Context *ctx, s32 index, s32 value)
{
    u32 offset = (u32)index << 2;
    u16 i;
    s32 result = 0;
    s32 error = 0;
    u16 position;
    u16 within;

    position = ctx->base + (offset >> ctx->shift);
    within = offset & (ctx->size - 1);

    if (buffer->position != position) {
        for (i = 0; i < ctx->count; i++) {
            s32 current = fn_803E9178(ctx, buffer->data,
                buffer->position + (u16)i * ctx->stride, 0, ctx->size);
            if (current != 0 && error == 0) {
                error = current;
            }
        }

        result = fn_803E8DC0(ctx, buffer->data, position, 0, ctx->size);
        if (result != 0) {
            return result;
        }
        buffer->position = position;
    }

    store_value(buffer, within, value);

    if (result != 0) {
        error = result;
    }
    return error;
}

s32 fn_803E3350(Context *ctx, s32 index, s32 value, Buffer *buffer)
{
    return do_write(buffer, ctx, index, value);
}