#include <types.h>
#pragma force_active on

void operator delete(void* p);

extern "C" {
void* fn_27_1A5BC8(void* p, long n);
}

void* fn_27_1A5BC8(void* p, long n) {
    if (p != nullptr && n > 0) {
        operator delete(p);
    }
    return p;
}
