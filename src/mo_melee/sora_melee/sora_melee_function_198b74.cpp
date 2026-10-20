#include <types.h>
#pragma force_active on

struct FnBits {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" void fn_27_198B74(FnBits* p, u32 v)
{
    FnBits* w = (FnBits*)((u8*)p + 8);
    w->b = v;
}
