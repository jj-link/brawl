#include <stddef.h>
#pragma force_active on

extern "C" void fn_27_1A61E0(void* p, short n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_13BE0(void* arg1, short arg2) {
    if (arg1) {
        fn_27_1A61E0(arg1, -1);
        if (arg2 > 0)
            __dl__FPv(arg1);
    }
    return arg1;
}
