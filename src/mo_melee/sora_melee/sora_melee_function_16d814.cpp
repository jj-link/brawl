#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_16D814(void* p, s32 n) {
    if (p && n > 0) {
        ::operator delete(p);
    }
    return p;
}
}
