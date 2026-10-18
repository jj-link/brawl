#include <new>
#pragma force_active on

extern "C" {
void* fn_61_A1F8(void* p, int n) {
    if (p) {
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
}
