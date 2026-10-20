#include <types.h>
#pragma force_active on

struct Fld {
    u32 a : 14;
    u32 f : 7;
    u32 b : 11;
};

extern "C" void fn_27_1D0CF8(void* p, u32 v)
{
    Fld* w = (Fld*)((char*)p + 8);
    w->f = v;
}
