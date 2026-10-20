#include <types.h>
#pragma force_active on

typedef struct {
    u32 hi : 8;
    u32 rest : 24;
} Flags;

extern "C" void fn_27_CE028(void* p, u32 v)
{
    Flags* f = (Flags*)((char*)p + 8);
    f->hi = v;
}
