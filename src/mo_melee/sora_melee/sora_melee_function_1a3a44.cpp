#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1A3A44(void* p, long n) {
    if (p != nullptr && n > 0) {
        operator delete(p);
    }
    return p;
}
}
