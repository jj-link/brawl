#include <types.h>
#pragma force_active on

extern "C" {

void __dl__FPv(void*);

void* fn_92_CF20(void* arg0, s16 arg1) {
    if (arg0 != NULL && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}

}
