#include <types.h>
#include <revolution/GX.h>
#pragma force_active on

extern "C" void fn_801B62B8(int, GXColor*);
extern "C" void fn_801B601C(void*, const GXColor*);

extern "C" void fn_8000E710(void* unused, int a, int b, void* out, f32 t) {
    GXColor c0, c1, res, copy;
    register f32 ft;
    register GXColor* p0;
    register GXColor* p1;
    register GXColor* pr;
    register f32 w0, w1, w2, w3;

    ft = t;
    fn_801B62B8(a, &c0);
    fn_801B62B8(b, &c1);
    p0 = &c0;
    p1 = &c1;
    pr = &res;

    asm {
        psq_l w2, 0(p0), 0, 2
        psq_l w0, 0(p1), 0, 2
        psq_l w3, 2(p0), 0, 2
        psq_l w1, 2(p1), 0, 2
        ps_sub w0, w0, w2
        ps_sub w1, w1, w3
        ps_madds0 w2, w0, ft, w2
        ps_madds0 w3, w1, ft, w3
        psq_st w2, 0(pr), 0, 2
        psq_st w3, 2(pr), 0, 2
    }

    *(u32*)&copy = *(u32*)&res;
    fn_801B601C(out, &copy);
}
