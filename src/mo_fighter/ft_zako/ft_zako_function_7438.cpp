#include <stddef.h>
#pragma force_active on

extern "C" void* fn_126_7438(void* p, short n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
