#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_63EBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_12F80(void* p, short flags)
{
    if (p != NULL) {
        fn_27_63EBC(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
