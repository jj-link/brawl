#include <types.h>
#pragma force_active on

extern "C" {
void* fn_79_551C(void* p, s32 flags);
}

void* fn_79_551C(void* p, s32 flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
