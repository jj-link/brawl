#pragma force_active on
typedef int s32;
typedef unsigned char u8;

typedef struct Node { int f0; int f4; int f8; } Node;
typedef struct Context { u8 pad[0x15f0]; Node *f15f0; int f15f4; int f15f8; int f15fc; } Context;

extern s32 fn_803AEA18(Context *, Node **, void *, Node **, s32 *);

s32 fn_803AFD48(Context *ctx, void *arg1, Node **out) {
    s32 found;
    s32 r;

    if (ctx->f15f8 == 0) {
        ctx->f15f0->f4 = ctx->f15fc;
        ctx->f15f0->f8 = ctx->f15fc;
        *out = ctx->f15f0;
        return 0;
    }
    r = fn_803AEA18(ctx, (Node **)&ctx->f15f8, arg1, out, &found);
    return r & ((-r | r) >> 31);
}
