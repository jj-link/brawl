#include <st/module.h>
#pragma force_active on

extern "C" {
void* fn_27_A0C34(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_107_31F4(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_27_A0C34(arg0, -1);
        if (static_cast<short>(arg1) > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
