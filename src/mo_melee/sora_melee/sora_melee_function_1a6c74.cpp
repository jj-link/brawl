#include <types.h>
#pragma force_active on

struct __attribute__((packed)) Bitfield {
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" void fn_27_1A6C74(void* p, u16 val) {
    Bitfield* ptr = (Bitfield*)((u8*)p + 8);
    ptr->b = val;
}
