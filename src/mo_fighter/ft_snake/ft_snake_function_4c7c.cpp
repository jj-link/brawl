#include <new>
#pragma force_active on

extern "C" void* fn_122_4C7C(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
