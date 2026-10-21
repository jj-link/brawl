#pragma force_active on

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Work {
    char pad[0x10];
    Vec4 value;
};

struct Context {
    char pad[0x68];
    Work* work;
    char pad6C[0xC];
    int pending;
    int count;
    char pad80[4];
    signed char flag;
};

extern "C" void fn_802F1480(void*, void*, Context*);
extern "C" void fn_802F2758(void*, void*, void*, Work*, void*);
extern "C" void fn_802EFE70(Context*);

extern "C" void fn_802F2650(
    void* a, void* b, void* c, Context* ctx, const Vec4* value, void* d)
{
    Work* work = ctx->work;
    Vec4 saved;

    work->value = *value;
    saved = *value;
    ++ctx->count;

    fn_802F1480(b, c, ctx);
    fn_802F2758(a, b, c, work, d);

    if (--ctx->count == 0 && ctx->pending != 0 && ctx->flag == 0) {
        fn_802EFE70(ctx);
    }

    work->value = saved;
}
