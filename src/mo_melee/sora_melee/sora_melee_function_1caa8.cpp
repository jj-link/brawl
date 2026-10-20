#include <types.h>
#pragma force_active on

struct fn_27_1CAA8_Obj {
    u8 pad[0x165];
    u8 hi : 1;
    u8 lo : 7;
};

extern "C" {
void fn_27_1CAA8(fn_27_1CAA8_Obj* p, u32 v) {
    p->hi = v;
}
}
