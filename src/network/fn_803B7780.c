#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Buffer {
    u16 flags;
    u16 dirty;
    u8 pad[20];
    u32 sector;
} Buffer;
typedef struct Context {
    u16 size;
    u8 pad02[26];
    s32 type;
    u8 pad20;
    u8 shift;
    u8 pad22[18];
    u32 count;
    u32 freeCount;
    u8 pad3c[0x1840];
    u16 flags;
} Context;
typedef struct Outer {
    u8 pad[0x34];
    Context *ctx;
} Outer;
typedef struct Entry { u32 a,b,c,d,e; } Entry;
extern Entry lbl_804169B0[];
extern s32 fn_803B5650(Context *, Buffer **, u32);
extern s32 fn_803B8708(Context *, u16, u32 *, Buffer **);
extern s32 fn_803B9170(Context *, u32, u32 *, Buffer **);
extern s32 fn_803B96F8(Context *, u32, u32 *, Buffer **);
extern s32 fn_803B8B80(Context *, u16, u32, Buffer **);
extern s32 fn_803B93C4(Context *, u32, u32, Buffer **);
extern s32 fn_803B99E4(Context *, u32, u32, Buffer **);
extern s32 fn_803B60DC(Outer *, u32, s32, u32, u32, Buffer **);
extern s32 fn_803B000C(Context *, Buffer *);
extern s32 fn_803AA334(Context *);

s32 fn_803B7780(Outer *arg0, u32 arg1, s32 arg2, u32 arg3) {
    Context *ctx = arg0->ctx;
    u32 limit;
    u32 remain;
    u32 size;
    u32 old;
    s32 ret;
    u32 next;
    Buffer *buf;

    if (ctx == 0) return 10;
    if ((arg1 < 2 || arg1 >= ctx->count + 2) && arg1 != 0) return 14;
    if (arg1 == 0) return 0;
    limit = lbl_804169B0[ctx->type].b;
    if (arg3 != 0) {
        remain = arg3;
        size = ctx->size << ctx->shift;
    } else {
        return 0;
    }
    ret = fn_803B5650(ctx, &buf, arg1);
    if (ret != 0) return ret;
    buf->dirty = 1;
    next = arg1;
    while (arg1 < limit) {
        if (arg3 != 0 && remain == 0) break;
        old = buf->sector;
        switch (ctx->type) {
        case 0: ret = fn_803B8708(ctx, (u16)arg1, &next, &buf); break;
        case 1: ret = fn_803B9170(ctx, arg1, &next, &buf); break;
        case 2: ret = fn_803B96F8(ctx, arg1, &next, &buf); break;
        default: ret = 15; break;
        }
        if (ret != 0) return ret;
        if (next == 0) {
            ret = 0;
            if ((buf->flags & 2) == 2) ret = fn_803B000C(ctx, buf);
            if (ret != 0) return ret;
            return 0;
        }
        if (old != buf->sector) {
            ret = fn_803B5650(ctx, &buf, arg1);
            if (ret != 0) return ret;
        }
        if ((u32)(arg2 + 0x10000) != 0xffff) {
            ret = fn_803B60DC(arg0, arg1, arg2, 0, 1, &buf);
            arg2++;
        } else {
            switch (ctx->type) {
            case 0: ret = fn_803B8B80(ctx, (u16)arg1, 0, &buf); break;
            case 1: ret = fn_803B93C4(ctx, arg1, 0, &buf); break;
            case 2: ret = fn_803B99E4(ctx, arg1, 0, &buf); break;
            default: ret = 15; break;
            }
        }
        if (ret != 0) return ret;
        if (arg3 != 0 && remain != 0) {
            remain = remain <= size ? 0 : remain - size;
        }
        if ((u32)(ctx->freeCount + 0x10000) != 0xffff) ctx->freeCount++;
        arg1 = next;
    }
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