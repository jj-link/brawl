#include <stddef.h>
#pragma force_active on

extern "C" {
void* fn_102_185E8(void* p, short n) {
    if (p != NULL && n > 0) {
        ::operator delete(p);
    }
    return p;
}
}
