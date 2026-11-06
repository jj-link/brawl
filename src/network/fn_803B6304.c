#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct Buffer { u16 flags, dirty; } Buffer;
typedef struct Context {
    u8 pad0[0x10];
    u32 field10;
    u8 pad14[8];
    s32 type;
    u8 pad20[0x18];
    u32 freeCount;
    u32 field3c;
    u8 pad40[0x183c];
    u16 flags;
} Context;
typedef struct Outer {
    u8 pad0[0xc];
    u32 fieldc;
    u32 field10;
    u8 pad14[0x20];
    Context *ctx;
} Outer;
typedef struct Entry { u32 a,b,c,d,e; } Entry;
extern Entry lbl_804169B0[];
extern s32 fn_803B5780(Context *, u32, u32, u32, u32 *, u32 *);
extern s32 fn_803B5650(Context *, Buffer **, u32);
extern s32 fn_803B60DC(Outer *, u32, u32, u32, u32, Buffer **);
extern s32 fn_803B000C(Context *, Buffer *);
extern s32 fn_803AA334(Context *);
s32 fn_803B6304(Outer *outer, u32 arg1, u32 arg2, u32 *first, u32 *last)
{
    Context *ctx = outer->ctx;
    u32 start;
    u32 end;
    Buffer *buf;
    u32 limit;
    Entry *entry;
    u32 i;
    s32 ret;

    entry = &lbl_804169B0[ctx->type];
    *first = -1;
    *last = -1;
    end = -1;
    limit = entry->c;
    ret = fn_803B5780(ctx, ctx->field3c, -1, arg1, &start, &end);
    if (ret != 0) return ret;
    if ((u32)(start + 0x10000) == 0xffff) return 0;
    ret = fn_803B5650(ctx, &buf, start);
    if (ret != 0) return ret;
    buf->dirty = 0;
    for (i = start; i < end; i++) {
        ret = fn_803B60DC(outer, i, arg2, i + 1, 1, &buf);
        if (ret != 0) return ret;
        if (ctx->flags & 4) {
            if ((u32)(ctx->freeCount + 0x10000) != 0xffff && ctx->freeCount != 0 &&
                (ctx->type != 2 || end != ctx->field10))
                ctx->freeCount--;
        }
        if ((u32)(*first + 0x10000) == 0xffff) *first = i;
        *last = i;
        arg2++;
    }
    if ((u32)(end + 0x10000) != 0xffff) {
        ret = fn_803B60DC(outer, end, arg2, limit, 1, &buf);
        if (ret != 0) return ret;
        if ((u32)(*first + 0x10000) == 0xffff) *first = i;
        *last = i;
        if ((u32)(ctx->freeCount + 0x10000) != 0xffff && ctx->freeCount != 0 &&
            (ctx->type != 2 || end != ctx->field10))
            ctx->freeCount--;
    }
    ctx->field3c = end + 1;
    outer->fieldc = end;
    outer->field10 = arg2;
    *last = end;
    ret = 0;
    if ((buf->flags & 2) == 2) ret = fn_803B000C(ctx, buf);
    if (ret != 0) return ret;
    if (ctx->type == 2 && (ctx->flags & 2)) {
        ret = 0;
        if (ctx->type != 2) ret = 12;
        else if (!(ctx->flags & 2)) ret = 36;
        else if (ctx->flags & 4) ret = fn_803AA334(ctx);
        if (ret != 0) {
            ctx->freeCount = -1;
            ctx->flags &= ~4;
        }
    }
    return 0;
}