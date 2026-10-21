#pragma force_active on

extern "C" {
extern const float lbl_805A4270;
extern const float lbl_805A4274;
void fn_8028E4A4(void*, int, int);
}

struct Context {
    float values[8];
    char pad[0x98];
    int count;
};

struct Work {
    float values[12];
};

extern "C" void fn_802DBFD0(
    void*, void*, void*, void*, Context* ctx, int a, int b)
{
    Work work __attribute__((aligned(16)));

    work.values[0] = ctx->values[0];
    work.values[1] = ctx->values[1];
    work.values[2] = ctx->values[2];
    work.values[3] = ctx->values[3];
    work.values[4] = ctx->values[4];
    work.values[5] = ctx->values[5];
    work.values[6] = ctx->values[6];
    work.values[7] = ctx->values[7];

    work.values[11] = lbl_805A4270;
    work.values[10] = lbl_805A4270;
    work.values[9] = lbl_805A4270;
    work.values[8] = lbl_805A4274;
    fn_8028E4A4(&work, a, b);

    work.values[8] = lbl_805A4270;
    work.values[9] = lbl_805A4274;
    fn_8028E4A4(&work, a, b);

    work.values[9] = lbl_805A4270;
    work.values[10] = lbl_805A4274;
    fn_8028E4A4(&work, a, b);

    ctx->count += 3;
}
