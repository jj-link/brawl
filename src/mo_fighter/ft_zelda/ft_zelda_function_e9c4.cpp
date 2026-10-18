#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_104_E9C4(void* p, short size) {
    if (p != NULL && size > 0) {
        operator delete(p);
    }
    return p;
}
