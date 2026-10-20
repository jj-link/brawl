#include <types.h>
#pragma force_active on

struct FnBits {
    u32 pad0 : 10;
    u32 f : 5;
    u32 pad1 : 17;
};

extern "C" void fn_27_D19D8(void* p, u32 v)
{
    FnBits* b = (FnBits*)((char*)p + 8);
    b->f = v;
}
