#include <types.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
void* fn_27_2A03AC(void* p, s32 size) {
    if (p) {
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
