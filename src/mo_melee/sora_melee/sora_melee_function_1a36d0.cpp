#include <types.h>
#pragma force_active on

struct Bits {
    u8 pad[8];
    u32 flags : 30;
    u32 bit30 : 1;
    u32 bit31 : 1;
};

extern "C" void fn_27_1A36D0(Bits* p) {
    p->bit30 = 0;
}
