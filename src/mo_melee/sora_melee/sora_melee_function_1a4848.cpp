#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad0;
    u32 pad1;
    u32 pad2 : 8;
    u32 field : 4;
    u32 rest : 20;
};

extern "C" void fn_27_1A4848(Obj* obj, u32 val) {
    obj->field = val;
}
