#include <types.h>
#pragma force_active on

extern "C" {
    extern void __dl__FPv(void*);

    void* fn_27_2B1BE8(void* p, s32 val) {
        if (p != 0 && val > 0) {
            __dl__FPv(p);
        }
        return p;
    }
}
