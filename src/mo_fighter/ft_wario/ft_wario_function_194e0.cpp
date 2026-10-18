#include <stddef.h>
#pragma force_active on

extern "C" void operator delete(void* p);

extern "C" void* fn_110_194E0(void* p, short size) {
    if (p != NULL) {
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
