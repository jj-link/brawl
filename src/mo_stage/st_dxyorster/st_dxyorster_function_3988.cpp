#include <types.h>
#pragma force_active on

extern "C" {
void* fn_76_3988(void* p, s32 flag) {
    if (p != 0) {
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
