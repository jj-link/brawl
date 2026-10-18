#include <types.h>
#pragma force_active on

struct Blk {
    u32 w[51];
};

extern "C" void fn_15_4AF4(u8* p) {
    u32 first = *(u32*)(p + 0x618);
    *(u32*)(p + 0xD54) = 0x3C;
    *(u32*)(p + 0x548) = first;
    *(Blk*)(p + 0x54C) = *(Blk*)(p + 0x61C);
}
