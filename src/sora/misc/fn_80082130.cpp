#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;
extern "C" void fn_801EC158(void*);
extern "C" void fn_801EC41C(const void*, void*);
extern "C" void fn_801EC1B8(const void*, const void*, void*);
extern float lbl_805A1BB4;
typedef union { float f; unsigned int i; } FloatBits;
#define IS_NAN(u, x) ((u.f = (x)), ((u.i >> 23 & 255) == 255) && (u.i & 0x7fffff))
extern "C" void fn_80082130(char* self) {
    FloatBits u11, u10, u9, u8, u7, u6, u5, u4, u3, u2, u1, u0;
    _MTX34 ident;
    _MTX34 m;
    fn_801EC158(&ident);
    if (lbl_805A1BB4 != *(float*)(self + 0xb0)) {
        fn_801EC41C(*(char**)(*(char**)(self + 0x1f8)) + 0x13c, &m);
        int bad = IS_NAN(u0, m.a[0]);
        if (!bad) bad = IS_NAN(u1, m.a[1]);
        if (!bad) bad = IS_NAN(u2, m.a[2]);
        if (!bad) bad = IS_NAN(u3, m.a[3]);
        if (!bad) bad = IS_NAN(u4, m.a[4]);
        if (!bad) bad = IS_NAN(u5, m.a[5]);
        if (!bad) bad = IS_NAN(u6, m.a[6]);
        if (!bad) bad = IS_NAN(u7, m.a[7]);
        if (!bad) bad = IS_NAN(u8, m.a[8]);
        if (!bad) bad = IS_NAN(u9, m.a[9]);
        if (!bad) bad = IS_NAN(u10, m.a[10]);
        if (!bad) bad = IS_NAN(u11, m.a[11]);
        if (bad) {
            *(_MTX34*)(self + 0x16c) = ident;
        } else {
            fn_801EC1B8(&m, self + 0x13c, self + 0x16c);
        }
    }
}