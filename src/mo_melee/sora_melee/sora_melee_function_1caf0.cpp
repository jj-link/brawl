#include <types.h>
#pragma force_active on

struct FnBits {
    u8 pad[0x164];
    u8 hi : 6;
    u8 b1 : 1;
    u8 lo : 1;
};

extern "C" void fn_27_1CAF0(FnBits* self, u32 flag) {
    self->b1 = flag;
}
