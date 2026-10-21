#pragma force_active on
struct FnCtx {
    int field0;
    int field4;
    void (*fn)(int, int, int, int, int, int);
};

void fn_80335C14(void* unused, int a, int b, int c, int d, int e, struct FnCtx* ctx) {
    if (ctx->fn != 0) {
        ctx->fn(a, b, c, d, e, ctx->field0);
    }
}
