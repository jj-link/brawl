#include <types.h>
#pragma force_active on

extern "C" void* fn_1_139A0(void* p, s32 n);

extern "C" void* fn_1_7B10(void* p, s32 n) {
    if (p != nullptr) {
        fn_1_139A0(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
