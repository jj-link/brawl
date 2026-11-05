#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct Buffer { u16 flags, dirty; } Buffer;
typedef struct Context {
    u8 pad[0x1c];
    s32 type;
    u8 pad20[0x14];
    u32 count;
    u32 freeCount;
    u8 pad3c[0x1840];
    u16 flags;
} Context;
extern s32 fn_803AA178(Context *);
extern s32 fn_803AA334(Context *);
extern s32 fn_803B5650(Context *, Buffer **, u32);
extern s32 fn_803B8708(Context *, u16, u32 *, Buffer **);
extern s32 fn_803B9170(Context *, u32, u32 *, Buffer **);
extern s32 fn_803B96F8(Context *, u32, u32 *, Buffer **);

s32 fn_803B7540(Context *ctx, u32 *out) {
    u32 next;
    Buffer *buf;
    u32 i;
    s32 ret;
    if (ctx == 0) return 10;
    if (ctx->type != 0 && ctx->type != 1 && ctx->type != 2) return 15;
    if (ctx->flags & 4) {
        u32 n = ctx->freeCount;
        if (n + 0x10000 != 0xffff) {
            *out = n;
            return 0;
        }
    }
    *out = -1;
    i = 2;
    if ((ctx->flags & 1) && ctx->type == 2) {
        ret = fn_803AA178(ctx);
        if (ret != 0) return ret;
        *out = ctx->freeCount;
    }
    if (*out + 0x10000 == 0xffff) {
        ret = fn_803B5650(ctx, &buf, 2);
        if (ret != 0) return ret;
        buf->dirty = 0;
        while (i >= 2 && i < ctx->count + 2) {
            switch (ctx->type) {
            case 0: ret = fn_803B8708(ctx, (u16)i, &next, &buf); break;
            case 1: ret = fn_803B9170(ctx, i, &next, &buf); break;
            case 2: ret = fn_803B96F8(ctx, i, &next, &buf); break;
            default: ret = 15; break;
            }
            if (ret != 0) return ret;
            if (next == 0) *out += 1;
            i++;
        }
        ctx->freeCount = *out;
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
    }
    ctx->flags |= 4;
    return 0;
}