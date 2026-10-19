#include <types.h>
#pragma force_active on

extern "C" void fn_104_1B48(void* self, s16 arg);

extern "C" {
void* fn_104_1D1C(void* p, s16 flag);
}

void* fn_104_1D1C(void* p, s16 flag) {
    if (p) {
        s16 zero = 0;
        fn_104_1B48(p, zero);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
