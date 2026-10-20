#include <types.h>
#pragma force_active on

struct FnInner {
    u8 pad[0x1F];
    u8 hi : 5;
    u8 bit : 1;
    u8 lo : 2;
};

extern "C" {
void fn_27_111F98(FnInner** p, u32 v) {
    FnInner* in = *p;
    in->bit = v;
}
}
