#include <types.h>
#pragma force_active on

extern "C" void* fn_27_3854D4(void* p, s32 n) {
    if (p != nullptr) {
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
