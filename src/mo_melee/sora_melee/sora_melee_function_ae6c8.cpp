#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 4;
    u32 f : 2;
    u32 lo : 26;
};

extern "C" void fn_27_AE6C8(Fn27Obj* obj, u32 val)
{
    obj->f = val;
}
