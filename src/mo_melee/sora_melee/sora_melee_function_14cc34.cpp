#include <types.h>
#pragma force_active on

struct fnElem {
    float f[0x1c8 / 4];
};

extern "C" {
float fn_27_14CC34(u8* p1, u32 p2, u32 p3) {
    fnElem* e = (fnElem*)(p1 - 0x2ecc);
    return e[p2].f[p3];
}
}
