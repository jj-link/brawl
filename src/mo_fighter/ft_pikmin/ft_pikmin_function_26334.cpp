#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
void* fn_113_26334(void* p, short flags);
}

void* fn_113_26334(void* p, short flags) {
    if (p != NULL && flags > 0) {
        operator delete(p);
    }
    return p;
}
