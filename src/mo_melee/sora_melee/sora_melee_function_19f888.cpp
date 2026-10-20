#include <types.h>
#pragma force_active on

struct FnBits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" void fn_27_19F888(void* p, u32 v)
{
    FnBits* w = (FnBits*)((char*)p + 8);
    w->b = v;
}
