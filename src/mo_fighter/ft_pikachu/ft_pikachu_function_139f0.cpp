#include <new>
#pragma force_active on

extern "C" void* fn_98_4B58(void* object, short deleting);

extern "C" void* fn_98_139F0(void* a1, int a2) {
    if (a1) {
        fn_98_4B58(a1, 0);
        if (static_cast<short>(a2) > 0) operator delete(a1);
    }
    return a1;
}
