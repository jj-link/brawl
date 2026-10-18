#include <stddef.h>
#pragma force_active on

extern "C" void* fn_47_2C0C(void* p, int flags) {
    if (p != NULL && flags > 0) {
        operator delete(p);
    }
    return p;
}
