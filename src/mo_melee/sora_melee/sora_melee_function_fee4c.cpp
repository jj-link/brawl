#include <types.h>
#pragma force_active on

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 top:12;
    u32 field:6;
    u32 low:14;
};

extern "C" void fn_27_FEE4C(Obj* obj, u32 val)
{
    obj->field = val;
}
