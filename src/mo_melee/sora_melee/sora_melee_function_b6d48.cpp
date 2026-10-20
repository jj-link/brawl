#include <types.h>
#pragma force_active on

struct Flags44 {
    u8 hi : 3;
    u8 bit : 1;
    u8 lo : 4;
};

extern "C" {
void fn_27_B6D48(Flags44* self, u32 flag) {
    self[0x44].bit = flag;
}
}
