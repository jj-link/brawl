#include <new>
#pragma force_active on

extern "C" void* fn_94_1CBA8(void* p, short n);

extern "C" void* fn_94_1CB4C(void* p, short n) {
    if (p != 0) {
        fn_94_1CBA8(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
