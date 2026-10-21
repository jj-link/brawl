#pragma force_active on
extern float lbl_805A33A0;
extern float lbl_805A33A4;

struct Dst {
    float f0, f4, f8, fC, f10, f14, f18, f1C;
};

struct Src {
    float f0, f4;
};

extern "C" void fn_801A8740(Dst* __restrict arg0, const Src* __restrict arg1) {
    float y = arg1->f4;
    float w = lbl_805A33A4 - y;
    float z = lbl_805A33A0;
    arg0->f4 = z;
    float x = arg1->f0;
    arg0->f0 = x;
    arg0->f8 = z;
    arg0->fC = z;
    arg0->f10 = z;
    arg0->f14 = y;
    arg0->f18 = z;
    arg0->f1C = w;
}
