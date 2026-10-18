#include <stddef.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
void* fn_71_99F0(void* p, int n) {
    if (p != NULL && n > 0) {
        operator delete(p);
    }
    return p;
}
}
