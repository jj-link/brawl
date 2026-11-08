#include <types.h>
#pragma force_active on
extern "C" void* fn_8016E658(void*, void*);
extern "C" void* fn_8015C1D0(void*, void*);
extern "C" void* fn_8016E9CC(void* arg0, void* arg1, void* arg2) {
    void* result;
    if (arg2 != 0 && (result = fn_8016E658(arg2, arg1)) != 0) {
        return result;
    }
    arg2 = fn_8015C1D0(arg0, 0);
    while (arg2 != 0) {
        result = fn_8016E658(arg2, arg1);
        if (result != 0) {
            return result;
        }
        arg2 = fn_8015C1D0(arg0, arg2);
    }
    return 0;
}