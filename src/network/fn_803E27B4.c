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

s32 fn_803E27B4(Context *ctx, s32 index, u32 value, Buffer *buffer)
{
    u16 offset = index + (index >> 1);
    u16 position = ctx->base + ((s32)offset >> ctx->shift);
    u16 within = offset & (ctx->size - 1);
    s32 result = 0;
    s32 error = 0;
    u32 i;

    if (buffer->position != position) {
        for (i = 0; (u16)i < ctx->count; i++) {
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
    if (index & 1) {
        buffer->data[within] = (buffer->data[within] & 0xF) | ((value << 4) & 0xF0);
        if (within == (u32)(ctx->size - 1)) {
            for (i = 0; (u16)i < ctx->count; i++) {
                s32 current = fn_803E9178(ctx, buffer->data,
                    buffer->position + (u16)i * ctx->stride, 0, ctx->size);
                if (current != 0 && error == 0) {
                    error = current;
                }
            }
            i = position + 1;
            result = fn_803E8DC0(ctx, buffer->data, i, 0, ctx->size);
            if (result != 0) {
                return result;
            }
            buffer->position = i;
            buffer->data[0] = (u8)(value >> 4);
        } else {
            buffer->data[within + 1] = (u8)(value >> 4);
        }
    } else {
        buffer->data[within] = value;
        if (within == (u32)(ctx->size - 1)) {
            for (i = 0; (u16)i < ctx->count; i++) {
                s32 current = fn_803E9178(ctx, buffer->data,
                    buffer->position + (u16)i * ctx->stride, 0, ctx->size);
                if (current != 0 && error == 0) {
                    error = current;
                }
            }
            i = position + 1;
            result = fn_803E8DC0(ctx, buffer->data, i, 0, ctx->size);
            if (result != 0) {
                return result;
            }
            buffer->position = i;
            buffer->data[0] = (buffer->data[0] & 0xF0) | (u8)(value >> 8);
        } else {
            buffer->data[within + 1] = (u8)(value >> 8) | (buffer->data[within + 1] & 0xF0);
        }
    }
    if (result != 0) {
        error = result;
    }
    return error;
}
