#include <stddef.h>
#pragma force_active on

extern "C" void* fn_78_5218(void* p, int n) {
    if (p != NULL) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
