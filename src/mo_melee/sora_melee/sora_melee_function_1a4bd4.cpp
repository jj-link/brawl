#include <types.h>
#pragma force_active on

struct Flags {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1A4BD4(void* self, u32 val)
{
    Flags* f = (Flags*)((char*)self + 8);
    f->hi = val;
}
