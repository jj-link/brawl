#include <types.h>
#pragma force_active on

struct fn_27_1A3680_bits {
    u32 hi : 10;
    u32 lo : 22;
};

struct fn_27_1A3680_obj {
    u8 pad[8];
    fn_27_1A3680_bits field;
};

extern "C" {
void fn_27_1A3680(fn_27_1A3680_obj* p, u32 v) {
    p->field.hi = v;
}
}
