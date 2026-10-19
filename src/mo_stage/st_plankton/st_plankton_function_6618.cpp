#include <types.h>
#pragma force_active on

extern "C" void* fn_74_6618(void* p, s32 n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
