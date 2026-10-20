#include <types.h>
#pragma force_active on

struct FefBits {
    u8 pad[8];
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" void fn_27_FEF40(FefBits* p, u32 v)
{
    p->b = v;
}
