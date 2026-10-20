#include <types.h>
#pragma force_active on

struct X {
    u32 a;
    u32 pad;
    unsigned int lo : 4;
    unsigned int hi : 28;
};

extern "C" void fn_27_389DBC(X* p, u32 val) {
    p->lo = (val << 28) >> 28;
}