#include <types.h>
#pragma force_active on

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 pad : 8;
    u32 field : 4;
    u32 rest : 20;
};

extern "C" void fn_27_1A76B4(Obj* obj, u32 val) {
    obj->field = val;
}
