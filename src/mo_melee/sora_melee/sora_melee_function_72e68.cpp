#include <types.h>
#pragma force_active on

struct fn_27_72E68_t {
    u32 w0;
    u32 w1;
    u32 hi : 12;
    u32 mid : 6;
    u32 lo : 14;
};

extern "C" void fn_27_72E68(fn_27_72E68_t* p, u32 v)
{
    p->mid = v;
}
