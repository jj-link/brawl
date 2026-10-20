#include <types.h>
#pragma force_active on

extern "C" {
    extern void* lbl_805A03A0;

    void fn_27_254CE8(void (*func)(void*)) {
        lbl_805A03A0 = (void*)func;
    }
}
