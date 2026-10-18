#include <stddef.h>
#pragma force_active on

extern "C" void* fn_112_E43C(void* p, short n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
