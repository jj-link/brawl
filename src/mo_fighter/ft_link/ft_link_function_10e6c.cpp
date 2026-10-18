#include <stddef.h>
#pragma force_active on

extern "C" void* fn_93_10E6C(void* p, short size) {
    if (p != NULL && size > 0) {
        operator delete(p);
    }
    return p;
}
