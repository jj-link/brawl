#include <types.h>
#pragma force_active on

extern "C" void* fn_27_191FA0(void* p, s32 n) {
    if (p && n > 0) {
        operator delete(p);
    }
    return p;
}
