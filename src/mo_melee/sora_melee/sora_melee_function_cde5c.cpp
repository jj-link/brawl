#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad[2];
    u32 hi : 2;
    u32 lo : 30;
};

extern "C" void fn_27_CDE5C(Obj* p, u32 v)
{
    p->hi = v;
}
