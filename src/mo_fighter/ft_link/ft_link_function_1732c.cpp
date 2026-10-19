#include <types.h>
#pragma force_active on

extern "C" void fn_93_17388(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_1732C(void* arg1, short arg2) {
    if (arg1 != NULL) {
        fn_93_17388(arg1, -1);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
