#pragma force_active on
#include <types.h>

typedef struct Stream {
    s32 a, b;
    int count;
    s32 c;
    u32 total;
    u32 size;
    s32 g;
    u32 pos;
    u32 session;
} Stream;

typedef struct Message {
    u32 first;
    u32 pad;
    u32 length;
} Message;

extern s32 fn_80398818(void *, u32, u32);
extern s32 fn_80398A08(void *, s32, void *);
extern s32 fn_80398BD8(void *, s32, void *);
extern void fn_8039CF40(const Message *, void *);
extern s32 lbl_805A1170;

s32 fn_8039CB7C(Stream *self, const Message *msg, void *ctx)
{
    s32 result;
    u32 pos;
    u32 *block;

    pos = self->pos;
    block = (u32 *)(lbl_805A1170 + 0x1800);

    if (pos == 0)
        return -6;

    if (pos >= self->size || ((pos - 0x80) & 0x7F) != 0)
        return -0xE;

    result = fn_80398818(ctx, pos, 0);
    if (result != 0)
        return result;

    result = fn_80398A08(block, 0x80, ctx);
    if (result != 0)
        return result;

    if (block[3] >= self->size ||
        ((block[3] - 0x80) & 0x7F) != 0)
        return -0xE;

    self->pos = block[3];
    fn_8039CF40(msg, block);

    result = fn_80398818(ctx, pos, 0);
    if (result != 0)
        return result;

    result = fn_80398BD8(block, 0x80, ctx);
    if (result != 0)
        return result;

    if (self->count == 0)
        self->session = msg->first;

    self->count++;
    self->total += msg->length;
    return 0;
}
