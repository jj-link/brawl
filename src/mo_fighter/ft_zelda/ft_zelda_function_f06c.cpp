#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_104_F06C(void* p, short n)
{
    if (p != NULL && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
