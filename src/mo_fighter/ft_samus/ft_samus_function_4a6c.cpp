#include <stddef.h>
#pragma force_active on

extern "C" void* fn_94_4A6C(void* p, short n) {
    if (p != NULL && n > 0) {
        ::operator delete(p);
    }
    return p;
}
