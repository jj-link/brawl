#include <st/module.h>
#pragma force_active on

extern "C" void* fn_125_1EAC(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_1E50(void* ptr, short count) {
    if (ptr != 0) {
        fn_125_1EAC(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
