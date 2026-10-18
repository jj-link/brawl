#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_62_5E5C(void* p, int size) {
    if (p != NULL) {
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
