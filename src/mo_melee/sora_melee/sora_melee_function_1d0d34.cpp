#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u8 pad[8];
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_1D0D34(Fn27Obj *obj, u32 val)
{
    obj->b = val;
}
