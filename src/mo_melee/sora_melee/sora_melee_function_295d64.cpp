#include <types.h>
#pragma force_active on

struct Obj {
    u32 a : 6;
    u32 field : 3;
    u32 rest : 23;
};

extern "C" void fn_27_295D64(void* p, u32 v) {
    Obj* w = (Obj*)((char*)p + 8);
    w->field = v;
}
