#pragma force_active on
typedef unsigned int u32;
typedef float f32;

extern char lbl_80466B18[];
extern f32 lbl_805A35D0;
extern f32 lbl_805A35D4;
extern f32 lbl_805A35D8;
extern f32 lbl_805A35DC;
extern f32 lbl_805A35E0;

struct Obj {
    void* m0;
    void* m4;
    u32 m8;
    u32 mc;
    u32 m10;
    f32 m14;
    f32 m18;
    f32 m1c;
    f32 m20;
    f32 m24;
};

extern "C" void fn_801C60C0(Obj* p) {
    f32 e, d, c, b, a;
    a = lbl_805A35D0;
    b = lbl_805A35D4;
    c = lbl_805A35D8;
    d = lbl_805A35DC;
    e = lbl_805A35E0;
    char* base = lbl_80466B18;
    p->m0 = base;
    p->m4 = base + 0xC;
    p->m8 = 0;
    p->m10 = 0x20;
    p->m14 = a;
    p->m18 = b;
    p->m1c = c;
    p->m20 = d;
    p->m24 = e;
}
