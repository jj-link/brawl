#pragma force_active on
extern "C" void fn_80281FB0(void*, int, int);
extern "C" char lbl_80487F50[];
extern "C" const float lbl_805A43B0;

struct S {
    void* vt;
    short pad;
    short s6;
    char b8;
    char pad2[0xB3];
    float bc, c0;
    char pad3[0x1C];
    float e0, e4, e8, ec, f0, f4, f8, fc;
};

extern "C" S* fn_802E4338(S* p, int a, int b) {
    float z = lbl_805A43B0;
    p->s6 = 1;
    p->vt = lbl_80487F50;
    p->ec = z;
    p->e8 = z;
    p->e4 = z;
    p->e0 = z;
    p->fc = z;
    p->f8 = z;
    p->f4 = z;
    p->f0 = z;
    fn_80281FB0((char*)p + 0x10, a, b);
    z = lbl_805A43B0;
    p->b8 = 0;
    p->bc = z;
    p->c0 = z;
    return p;
}
