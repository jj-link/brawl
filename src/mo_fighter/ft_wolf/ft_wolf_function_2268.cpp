#include <stddef.h>
#pragma force_active on

extern "C" void* fn_125_2268(void* p, short n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
