#pragma force_active on

struct Context {
    float values[8];
    float table[0x98 / 4];
    int count;
};

struct Work {
    float values[12];
};

extern "C" {
void fn_8028E4A4(void*, int, int);
}

extern "C" void fn_802DC764(void* a, void** cur, int b, int c, Context* ctx, int d, int e) {
    Work work __attribute__((aligned(16)));
    void* t;
    int idx;
    float* row;

    t = *cur;
    *cur = (char*)t + 4;
    idx = *(int*)*cur;

    row = (float*)((char*)ctx + idx * 16);
    work.values[8] = row[8];
    work.values[9] = row[9];
    work.values[10] = row[10];
    work.values[11] = row[11];

    work.values[0] = ctx->values[0];
    work.values[1] = ctx->values[1];
    work.values[2] = ctx->values[2];
    work.values[3] = ctx->values[3];
    work.values[4] = ctx->values[4];
    work.values[5] = ctx->values[5];
    work.values[6] = ctx->values[6];
    work.values[7] = ctx->values[7];

    fn_8028E4A4(&work, d, e);
    ctx->count += 1;
}
