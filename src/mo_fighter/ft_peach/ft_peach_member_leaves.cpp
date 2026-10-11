#include <types.h>

struct PeachLeafOwner {
    u8 unknown0[0xFE00];
    u8 flag;
    u8 unknown1[0x18154 - 0xFE01];
    u8 member;
};

extern "C" {
s32 fn_103_B328(const PeachLeafOwner*) {
    return 3;
}

void fn_103_B330(PeachLeafOwner* fighter, u8 flag) {
    fighter->flag = flag;
}

void* fn_103_B33C(PeachLeafOwner* fighter) {
    return &fighter->member;
}
}
