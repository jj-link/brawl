#include <stddef.h>
#pragma force_active on

extern "C" {
void* fn_122_1AE6C(void* p, short size) {
    if (p != NULL) {
        if (size > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
}
