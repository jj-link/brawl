#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);

void* fn_27_2ADF54(void* p, s32 n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
