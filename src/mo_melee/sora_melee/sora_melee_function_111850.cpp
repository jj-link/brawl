#include <types.h>
#pragma force_active on

struct X {
    u32 m0;
    u32 m1;
    u32 m2;
    u32 m3;
    u32 m4;
    u32 m5;
    u32 m6;
    u32 m7;
    u32 m8;
    float m9;
};

extern "C" float fn_27_111850(X* const* p) {
    return (*p)->m9;
}
