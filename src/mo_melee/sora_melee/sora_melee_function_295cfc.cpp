#include <types.h>
#pragma force_active on

struct Dst {
    u32 pad0;
    u32 pad4;
    u32 x : 3;
    u32 y : 3;
    u32 z : 26;
};

extern "C" void fn_27_295CFC(Dst* obj, u32 val) {
    obj->y = val;
}
