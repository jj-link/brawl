#include <st/module.h>
#pragma force_active on

extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_75EC(void* arg1, short arg2) {
    if (arg1) {
        fn_27_66114(arg1, -1);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
