#include <new>
#pragma force_active on

extern "C" {
void* fn_98_33DC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_34A8(void* object, short deleting) {
    if (object) {
        fn_98_33DC(static_cast<char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
