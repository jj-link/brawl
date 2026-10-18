#include <stddef.h>
#pragma force_active on

extern "C" void* fn_122_5B14(void* p, short n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
