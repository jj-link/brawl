#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Entry {
    u16 a;
    u16 b;
    u32 c;
} Entry;

typedef struct Ctx {
    char pad[0xa0];
    u32 *table;
    Entry *src;
    u8 count;
} Ctx;

extern Ctx *fn_803CD2E0(void);
extern s32 fn_803CD32C(void);
extern void fn_803CD298(void *p);
extern void fn_803CD410(s32 e);
extern void fn_803CD710(void);
extern s32 fn_803CF870(s32 a, void *b, s32 c, void *d, s32 e, void *f, void *g);
extern void fn_803CFBE4(s32 a, void *b);

void fn_803CD710(void) {
    u16 i;
    Ctx *ctx;
    s32 error;
    void *extra;
    Entry *dst;
    Entry *src;
    u32 *p;
    s32 result;

    ctx = fn_803CD2E0();
    error = 0;
    extra = 0;
    if (fn_803CD32C() == 0) {
        i = ctx->count;
        p = ctx->table;
        if (i < 0x12) {
            src = ctx->src;
            dst = (Entry *)((char *)ctx + i * 8);
            p = p + (i + 1);
            dst->a = src->a;
            dst->b = src->b;
            dst->c = p[0] + 4;
            ctx->count++;
            result = fn_803CF870(1, ctx->src, 0x20, fn_803CD710, p[1], p, src);
            if (result != 6 && (result >= 6 || result != 0)) {
                error = 1;
            }
        } else {
            error = 1;
            extra = 0;
        }
    } else {
        error = 1;
        fn_803CD410(2);
    }
    if (error != 0) {
        fn_803CD298(ctx->table);
        ctx->table = 0;
        fn_803CD298(ctx->src);
        ctx->src = 0;
        fn_803CFBE4(1, extra);
    }
}
