#include <stddef.h>
#pragma force_active on

extern "C" void* fn_93_14B84(void* p, short flags) {
    if (p != NULL) {
        if (flags > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
