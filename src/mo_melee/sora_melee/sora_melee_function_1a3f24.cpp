#include <types.h>
#pragma force_active on

struct SFlags {
    u32 a : 20;
    u32 b : 10;
};

struct SObj {
    u32 pad[2];
    SFlags flags;
};

extern "C" void fn_27_1A3F24(SObj* obj, u32 val) {
    obj->flags.b = val;
}
