#include <types.h>
#pragma force_active on

extern "C" {
void* fn_78_51D8(void* p, s32 n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
