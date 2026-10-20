#include <types.h>
#pragma force_active on

struct Bits8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern "C" void fn_27_9ECC8(void* self, u32 flag) {
    Bits8* p = (Bits8*)((u8*)self + 0x135);
    p->b5 = flag;
}
