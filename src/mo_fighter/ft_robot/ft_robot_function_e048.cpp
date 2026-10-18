#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_120_E048(void* p, short n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
