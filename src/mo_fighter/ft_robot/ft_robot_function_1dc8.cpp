#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_120_1DC8(void* p, short size) {
    if (p != NULL) {
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
