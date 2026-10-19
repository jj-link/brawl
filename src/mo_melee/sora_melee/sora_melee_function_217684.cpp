#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* ptr);

void* fn_27_217684(void* p, long n) {
    if (p != nullptr && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
