#include <types.h>
#pragma force_active on

struct FlagObj {
    u8 pad[0x1f];
    u8 hi : 7;
    u8 lo : 1;
};

extern "C" {
void fn_27_112D60(FlagObj** self, u32 flag) {
    FlagObj* obj = *self;
    obj->lo = flag;
}
}
