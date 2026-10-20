#include <types.h>
#pragma force_active on

struct FnBits {
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" void fn_27_199620(void *p, u32 v)
{
    FnBits *f = (FnBits *)((char *)p + 8);
    f->b = v;
}
