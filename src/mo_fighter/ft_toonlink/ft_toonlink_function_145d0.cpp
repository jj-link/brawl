#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_121_145D0(void* p, short flags) {
    if (p != NULL && flags > 0) {
        operator delete(p);
    }
    return p;
}
