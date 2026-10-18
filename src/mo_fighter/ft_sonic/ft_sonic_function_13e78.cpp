#include <stddef.h>
#pragma force_active on

extern "C" {
void operator delete(void* p);
}

extern "C" void* fn_123_13E78(void* p, short n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
