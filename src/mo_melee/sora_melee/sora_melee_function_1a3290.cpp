#include <types.h>
#pragma force_active on

struct fn_27_1A3290_Obj {
    u32 unk0;
    u32 unk4;
    u32 a : 10;
    u32 f : 10;
    u32 c : 12;
};

extern "C" void fn_27_1A3290(fn_27_1A3290_Obj* obj, u32 val)
{
    obj->f = val;
}
