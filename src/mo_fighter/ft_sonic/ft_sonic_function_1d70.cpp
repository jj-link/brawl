#include <stddef.h>
#pragma force_active on

extern "C" {
void operator delete(void* p);
}

extern "C" void* fn_123_1D70(void* p, short flag) {
    if (p != NULL && flag > 0) {
        operator delete(p);
    }
    return p;
}
