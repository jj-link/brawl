#include <types.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_27_2A08AC(void* p, s32 n) {
    if (p && n > 0) {
        operator delete(p);
    }
    return p;
}
