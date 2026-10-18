#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_40_16860(void* p, int n) {
    if (p != NULL) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
