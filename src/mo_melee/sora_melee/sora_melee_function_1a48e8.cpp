#include <types.h>
#pragma force_active on

struct fn_27_1A48E8_Bits {
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

struct fn_27_1A48E8_Obj {
    u8 pad[8];
    fn_27_1A48E8_Bits bits;
};

extern "C" {
void fn_27_1A48E8(fn_27_1A48E8_Obj* obj, u32 value)
{
    obj->bits.b = value;
}
}
