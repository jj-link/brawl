#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
void* fn_110_181A4(void* p, short flags);
}

extern "C" void* fn_110_181A4(void* p, short flags) {
    if (p != NULL && flags > 0) {
        operator delete(p);
    }
    return p;
}
