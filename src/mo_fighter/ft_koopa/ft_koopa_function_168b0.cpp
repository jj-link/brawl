#include <stddef.h>
#pragma force_active on

extern "C" void* fn_102_168B0(void* p, short flag) {
    if (p != NULL && flag > 0) {
        operator delete(p);
    }
    return p;
}
