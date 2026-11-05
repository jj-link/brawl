#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Context {
    char pad[0x34];
    u16 limit;
    u16 count;
    u16 remaining;
} Context;

extern u8 lbl_8052CDC0[];
extern void *fn_8024E7C4(u16);
extern void fn_8024CB94(void *, void *, void *);

void fn_8024CFF8(u8 *arg) {
    u8 count = arg[0];
    u8 i;
    u8 *p = arg + 1;
    for (i = 0; i < count; i++) {
        u16 id = p[0] + (p[1] << 8);
        u16 amount = p[2] + (p[3] << 8);
        Context *ctx;
        p += 4;
        ctx = fn_8024E7C4(id);
        if (ctx != 0) {
            u16 v = ctx->count + amount;
            u16 lim;
            ctx->count = v;
            lim = ctx->limit;
            if (v > lim)
                ctx->count = lim;
            if (ctx->remaining > amount)
                ctx->remaining = ctx->remaining - amount;
            else
                ctx->remaining = 0;
            *(u16 *)(lbl_8052CDC0 + 4) = *(u16 *)(lbl_8052CDC0 + 4) + amount;
            fn_8024CB94(ctx, 0, 0);
        }
    }
}
