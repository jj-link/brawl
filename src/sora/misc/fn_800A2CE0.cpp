#pragma force_active on

extern float lbl_805A1F18;
extern float lbl_805A1F1C;
extern float lbl_805A1F20;
extern float lbl_805A1F24;
extern float lbl_805A1F28;

struct Obj {
    float f00, f04, f08, f0C, f10, f14, f18, f1C;
    float f20, f24, f28, f2C, f30, f34;
    unsigned char b38;
};

extern "C" void fn_800A2CE0(Obj* p) {
    float e;
    float d;
    float c;
    float b;
    float a;

    a = lbl_805A1F18;
    b = lbl_805A1F1C;
    c = lbl_805A1F20;
    d = lbl_805A1F24;
    e = lbl_805A1F28;

    p->f00 = a;
    p->f04 = b;
    p->f08 = a;
    p->f0C = a;
    p->f10 = b;
    p->f14 = a;
    p->f18 = a;
    p->f1C = c;
    p->f20 = d;
    p->f24 = a;
    p->f28 = c;
    p->f2C = d;
    p->f34 = e;
    p->f30 = e;
    p->b38 = 1;
}
