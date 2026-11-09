#pragma force_active on

struct Context {
    float values[8];
    float table[0x98 / 4];
    int count;
};

struct Work {
    float a[8];
    float b[4];
    float c[2];
};

extern "C" void fn_8028ED40(Work* w, int a, int b, void* d, void* e);

extern "C" void fn_802DCBD8(void* a, void** arg1, void** arg2, void* unused, Context* ctx, int arg5, int arg6) {
    Work work __attribute__((aligned(16)));
    void* t;
    void* n;
    void* t2;
    int idx;
    float* row;

    t = *arg1;
    n = (char*)t + 4;
    *arg1 = n;
    idx = *(int*)n;

    row = (float*)((char*)ctx + idx * 16);
    work.b[0] = row[8];
    work.b[1] = row[9];
    work.b[2] = row[10];
    work.b[3] = row[11];

    work.a[0] = ctx->values[0];
    work.a[1] = ctx->values[1];
    work.a[2] = ctx->values[2];
    work.a[3] = ctx->values[3];
    work.a[4] = ctx->values[4];
    work.a[5] = ctx->values[5];
    work.a[6] = ctx->values[6];
    work.a[7] = ctx->values[7];

    t2 = *arg2;
    *arg2 = (char*)t2 + 0x10;
    work.c[0] = ((float*)t2)[0];
    work.c[1] = ((float*)t2)[1];

    fn_8028ED40(&work, arg5, arg6, t2, ctx);
    ctx->count += 1;
}
