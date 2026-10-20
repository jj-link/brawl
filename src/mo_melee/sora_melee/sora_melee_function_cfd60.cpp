#include <types.h>
#pragma force_active on

struct BitsCFD60 {
    u32 hi : 14;
    u32 f : 7;
    u32 lo : 11;
};

extern "C" void fn_27_CFD60(void* p, u32 v) {
    BitsCFD60* b = (BitsCFD60*)((char*)p + 8);
    b->f = v;
}
