#include <types.h>
#pragma force_active on

struct Fn27Word {
    u32 a : 4;
    u32 f : 4;
    u32 b : 24;
};

extern "C" void fn_27_122A90(void* p, u32 v)
{
    Fn27Word* w = (Fn27Word*)((char*)p + 8);
    w->f = v;
}
