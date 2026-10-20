#pragma force_active on
typedef unsigned char u8;

struct Fn27Table {
    u8 pad[0x10];
    int base;
    int unk14;
    int *entries;
};

extern "C" {
float fn_27_30B870(Fn27Table *p, int unused, int a, int i)
{
    Fn27Table *q = (Fn27Table *)((u8 *)p + (a - p->base) * 4);
    float *f = (float *)q->entries;
    return f[i];
}
}
