#include <types.h>
#pragma force_active on

extern "C" {
void* fn_76_3A48(void* p, long n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
