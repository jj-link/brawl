#include <types.h>
#pragma force_active on

extern "C" void* fn_62_5420(void* p, s32 n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
