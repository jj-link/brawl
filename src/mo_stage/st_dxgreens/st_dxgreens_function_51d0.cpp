#include <stddef.h>
#pragma force_active on

extern "C" void* fn_79_51D0(void* p, int n) {
    if (p != NULL && n > 0) {
        ::operator delete(p);
    }
    return p;
}
