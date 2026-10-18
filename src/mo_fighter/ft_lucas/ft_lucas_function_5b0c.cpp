#include <types.h>
#pragma force_active on

extern "C" void* fn_114_5B0C(void* p, s16 n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
