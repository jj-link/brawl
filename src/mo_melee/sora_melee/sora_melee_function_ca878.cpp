#include <types.h>
#pragma force_active on

struct FieldWord {
    u32 hi : 5;
    u32 f : 5;
    u32 lo : 22;
};

struct Holder {
    u32 pad[2];
    FieldWord w;
};

extern "C" void fn_27_CA878(Holder* p, u32 v)
{
    p->w.f = v;
}
