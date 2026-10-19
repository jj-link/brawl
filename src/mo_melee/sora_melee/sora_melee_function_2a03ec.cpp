#include <types.h>
#pragma force_active on

extern "C" void* fn_27_2A03EC(void* p, s32 n) {
    if (p) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
