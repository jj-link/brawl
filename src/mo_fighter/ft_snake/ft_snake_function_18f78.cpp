#include <types.h>
#pragma force_active on

struct ZeroPair
{
    u32 a;
    u32 b;
};

extern "C" u64 fn_122_18F78(void)
{
    ZeroPair x;
    x.a = 0;
    x.b = 0;
    return *(u64 *)&x;
}
