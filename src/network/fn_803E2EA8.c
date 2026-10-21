#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

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

s32 fn_803E2EA8(Context *ctx, u32 index, u32 value, Buffer *buffer)
{
    u32 offset = index * 2;
    u16 position = ctx->base + (offset >> ctx->shift);
    u16 within = offset & (ctx->size - 1);
    s32 result = 0;
    u32 i;
    s32 error = 0;

    if (buffer->position != position) {
        for (i = 0; i < ctx->count; i++) {
            s32 current = fn_803E9178(
                ctx, buffer->data,
                buffer->position + i * ctx->stride, 0, ctx->size);

            if (current != 0 && error == 0) {
                error = current;
            }
        }

        buffer->position = position;
        result = fn_803E8DC0(ctx, buffer->data, position, 0, ctx->size);
    }

    buffer->data[within] = value;
    buffer->data[within + 1] = value >> 8;

    if (result != 0) {
        error = result;
    }

    return error;
}
