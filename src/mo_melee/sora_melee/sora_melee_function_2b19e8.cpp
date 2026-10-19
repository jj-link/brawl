#include <types.h>
#pragma force_active on

extern "C" {
void operator delete(void* p);

void* fn_27_2B19E8(void* p, s32 n) {
    if (p != nullptr && n > 0) {
        operator delete(p);
    }
    return p;
}
}
