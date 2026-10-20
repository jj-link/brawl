#include <types.h>
#pragma force_active on

struct F {
    u32 pad0;
    u32 pad4;
    unsigned bot : 21;
    unsigned value : 1;
    unsigned top : 10;
};

extern "C" u32 fn_27_D039C(const F* p) {
    return p->value;
}
