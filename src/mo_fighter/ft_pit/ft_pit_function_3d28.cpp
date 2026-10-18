#include <stddef.h>
#pragma force_active on

extern "C" void* fn_112_3D28(void* p, short flags) {
    if (p != NULL && flags > 0) {
        operator delete(p);
    }
    return p;
}
