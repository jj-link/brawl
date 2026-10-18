#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
void* fn_122_21B4(void* p, short n);
}

extern "C" void* fn_122_21B4(void* p, short n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
