#include <types.h>
#pragma force_active on

void operator delete(void* ptr);

extern "C" {
void* fn_27_385314(void* p, long n);
}

void* fn_27_385314(void* p, long n) {
    if (p != nullptr) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
