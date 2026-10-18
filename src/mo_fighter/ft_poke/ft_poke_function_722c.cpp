#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_116_722C(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
