#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_63_93DC(void* p, int n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
