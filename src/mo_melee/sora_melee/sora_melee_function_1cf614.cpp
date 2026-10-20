#include <types.h>
#pragma force_active on

struct Flags {
    u32 top : 3;
    u32 rest : 29;
};

extern "C" {
void fn_27_1CF614(u8* p, u32 v)
{
    Flags* f = (Flags*)(p + 8);
    f->top = v;
}
}
