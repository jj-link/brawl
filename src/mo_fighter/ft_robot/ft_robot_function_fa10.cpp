#include <stddef.h>
#pragma force_active on

extern "C" void* fn_120_FA10(void* p, short flags) {
    if (p != NULL && flags > 0) {
        operator delete(p);
    }
    return p;
}
