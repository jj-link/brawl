#include <types.h>
#pragma force_active on

typedef struct Buffer {
    u16 flags, dirty;
    u32 f4;
    u8 *data;
    u32 fC, f10, f14, addr;
} Buffer;

typedef struct Context {
    u16 size;
    u8 pad02[10];
    u32 stride;
    u8 pad10[12];
    s32 type;
    u8 pad20;
    u8 shift;
    u8 count;
    u8 pad23[0x15];
    u32 freeCount;
    u8 pad3c[0x1f70];
    u16 flags;
} Context;

typedef struct Outer {
    u8 pad[0x34];
    Context *ctx;
} Outer;

typedef struct Entry { u32 a, b, c, d, e; } Entry;
extern Entry lbl_8041B0E0[];
extern s32 fn_803DA454(Context *, s32, Buffer **, s32 *);
extern void fn_803DA55C(Context *, Buffer *);
extern s32 fn_803DF760(Context *, Buffer *, u32);
extern s32 fn_803E0500(Outer *, u32, u32, u32, u32, Buffer *);
extern s32 fn_803E224C(Context *);
extern s32 fn_803E27B4(Context *, u16, u32, Buffer *);
extern s32 fn_803E2A70(Context *, u16, u32 *, Buffer *);
extern s32 fn_803E2EA8(Context *, u32, u32, Buffer *);
extern s32 fn_803E2FB0(Context *, u32, u32 *, Buffer *);
extern s32 fn_803E3350(Context *, u32, u32, Buffer *);
extern s32 fn_803E3490(Context *, u32, u32 *, Buffer *);
extern s32 fn_803E9178(Context *, u8 *, u32, u32, u16);

static inline s32 flush(Context *ctx, Buffer *buf) {
    u16 i;
    u32 cur;
    s32 err;
    err = 0;
    i = 0;
    cur = buf->addr;
    while (i < ctx->count) {
        s32 ret = fn_803E9178(ctx, buf->data, cur, 0, ctx->size);
        if (ret != 0 && err == 0) err = ret;
        cur += ctx->stride;
        i++;
    }
    return err;
}

static inline s32 get_next(Context *ctx, u32 cluster, u32 *next, Buffer *buf) {
    s32 ret;
    switch (ctx->type) {
    case 0: ret = fn_803E2A70(ctx, (u16)cluster, next, buf); break;
    case 1: ret = fn_803E2FB0(ctx, cluster, next, buf); break;
    case 2: ret = fn_803E3490(ctx, cluster, next, buf); break;
    default: ret = 15; break;
    }
    return ret;
}

static inline s32 set_entry(Context *ctx, u32 cluster, u32 value, Buffer *buf) {
    switch (ctx->type) {
    case 0: return fn_803E27B4(ctx, (u16)cluster, value, buf);
    case 1: return fn_803E2EA8(ctx, cluster, value, buf);
    case 2: return fn_803E3350(ctx, cluster, value, buf);
    default: return 15;
    }
}

s32 PFFAT_FreeChain(Outer *arg0, u32 arg1, u32 arg2, u32 arg3) {
    Context *ctx = arg0->ctx;
    u32 next;
    s32 unused;
    Buffer *buf;
    u32 limit;
    u32 remain;
    u32 size;
    s32 ret;

    if (arg1 == 0) return 0;
    limit = lbl_8041B0E0[ctx->type].b;
    if (arg3 != 0) {
        remain = arg3;
        size = ctx->size << ctx->shift;
    } else {
        return 0;
    }
    ret = fn_803DA454(ctx, -1, &buf, &unused);
    if (ret != 0) return ret;
    ret = fn_803DF760(ctx, buf, arg1);
    if (ret != 0) {
        fn_803DA55C(ctx, buf);
        return ret;
    }
    buf->dirty = 1;
    next = arg1;
    while (arg1 < limit) {
        if (arg3 != 0 && remain == 0) break;
        ret = get_next(ctx, arg1, &next, buf);
        if (ret != 0) {
            fn_803DA55C(ctx, buf);
            return ret;
        }
        if (next == 0) {
            ret = flush(ctx, buf);
            if (ret != 0) {
                fn_803DA55C(ctx, buf);
                return ret;
            }
            fn_803DA55C(ctx, buf);
            return 0;
        }
        if ((u32)(arg2 + 0x10000) != 0xffff) {
            ret = fn_803E0500(arg0, arg1, arg2, 0, 1, buf);
            arg2++;
        } else {
            ret = set_entry(ctx, arg1, 0, buf);
        }
        if (ret != 0) {
            fn_803DA55C(ctx, buf);
            return ret;
        }
        if (arg3 != 0 && remain != 0) {
            remain = remain <= size ? 0 : remain - size;
        }
        if ((u32)(ctx->freeCount + 0x10000) != 0xffff) ctx->freeCount++;
        arg1 = next;
    }
    ret = flush(ctx, buf);
    if (ret != 0) {
        fn_803DA55C(ctx, buf);
        return ret;
    }
    fn_803DA55C(ctx, buf);
    if (ctx->type == 2 && (ctx->flags & 2) && fn_803E224C(ctx) != 0) {
        ctx->freeCount = -1;
        ctx->flags &= ~4;
    }
    return 0;
}
