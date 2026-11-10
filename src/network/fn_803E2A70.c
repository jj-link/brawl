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

typedef struct Buffer {
    u8 pad00[2];
    u16 mode;               /* 0x02 */
    u8 pad04[4];
    u8 *data;               /* 0x08 */
    u8 pad0C[12];
    u32 position;           /* 0x18 */
} Buffer;

extern s32 fn_803E9178(Context *, u8 *, u32, u32, u16);
extern s32 fn_803E8DC0(Context *, u8 *, u32, u32, u16);

s32 fn_803E2A70(Context *ctx, u32 index, u32 *out, Buffer *buf)
{
    u32 offset;
    u32 within;
    u32 copy;
    s32 result;
    u32 i;

    offset = (u16)(index + ((index >> 1) & 0x7FFF));
    within = (u16)(ctx->base + (offset >> ctx->shift));
    copy = 1;
    if (ctx->flags & 0x80) {
        copy = ctx->flags & 7;
    }
    result = 0;
    for (;;) {
        if (result == 0x1000 && ctx->cb != 0) {
            s32 cbr = ctx->cb(ctx->cbArg);
            if (cbr == 0) {
                result = 0;
                continue;
            }
            if (cbr != 1 || ctx->count < 2 || copy >= ctx->count) {
                break;
            }
            result = 0;
            copy++;
            within += ctx->stride;
            continue;
        }
        if (buf->position != within) {
            if (buf->mode == 1) {
                for (i = 0; (u16)i < ctx->count; i++) {
                    fn_803E9178(ctx, buf->data, buf->position + (u16)i * ctx->stride, 0, ctx->size);
                }
            }
            result = fn_803E8DC0(ctx, buf->data, within, 0, ctx->size);
            if (result != 0) {
                continue;
            }
            buf->position = within;
        }
        offset &= ctx->size - 1;
        if (offset == ctx->size - 1) {
            *out = buf->data[offset];
            if (buf->mode == 1) {
                for (i = 0; (u16)i < ctx->count; i++) {
                    fn_803E9178(ctx, buf->data, buf->position + (u16)i * ctx->stride, 0, ctx->size);
                }
            }
            result = fn_803E8DC0(ctx, buf->data, within + 1, 0, ctx->size);
            if (result != 0) {
                continue;
            }
            buf->position = within + 1;
            *out += buf->data[0] << 8;
        } else {
            *out = ((buf->data + offset)[1] << 8) + buf->data[offset];
        }
        break;
    }
    if (result != 0) {
        *out = -1;
        return result;
    }
    if (index & 1) {
        *out = *out >> 4;
    } else {
        *out &= 0xFFF;
    }
    return 0;
}
