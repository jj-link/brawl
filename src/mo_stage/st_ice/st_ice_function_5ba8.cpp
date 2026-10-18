#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);

void* fn_62_5BA8(void* p, s32 n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
