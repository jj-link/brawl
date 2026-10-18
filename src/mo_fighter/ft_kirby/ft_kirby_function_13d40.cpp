#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_96_13D40(void* p, short size) {
    if (p != NULL && size > 0) {
        operator delete(p);
    }
    return p;
}
