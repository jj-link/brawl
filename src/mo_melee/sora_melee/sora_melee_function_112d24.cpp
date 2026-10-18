#include <types.h>
#pragma force_active on

struct Bits1F {
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
};

extern "C" {
void fn_27_112D24(u8* obj, u32 flag) {
    if (obj[0xA] != 1) {
        return;
    }
    Bits1F* inner = *(Bits1F**)obj;
    ((Bits1F*)((u8*)inner + 0x1F))->b1 = flag;
}
}
