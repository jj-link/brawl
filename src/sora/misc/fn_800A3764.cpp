#pragma force_active on
extern "C" {
extern char lbl_80454DA0[];
extern const float lbl_805A1F60;
extern const float lbl_805A1F64;
extern const float lbl_805A1F68;
}

struct Obj {
    int a;
    void *b;
    int c;
    int d;
    float f[33];
};

extern "C" void fn_800A3764(Obj *p)
{
    p->a = 0;
    p->b = lbl_80454DA0;
    p->c = 0;
    p->d = 0;
    *(float *)((char *)p + 0x90) = lbl_805A1F60;
    for (int i = 0; i < 4; i++) {
        char *q = (char *)p + i * 0x20;
        *(float *)(q + 0x18) = lbl_805A1F64;
        *(float *)(q + 0x14) = lbl_805A1F64;
        *(float *)(q + 0x10) = lbl_805A1F64;
        *(float *)(q + 0x20) = lbl_805A1F64;
        *(float *)(q + 0x1c) = lbl_805A1F64;
        *(float *)(q + 0x28) = lbl_805A1F64;
        *(float *)(q + 0x24) = lbl_805A1F64;
        *(float *)(q + 0x2c) = lbl_805A1F68;
    }
}
