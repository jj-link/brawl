#include <new>
#pragma force_active on

extern "C" {
void* fn_98_B740(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_B7A0(void* object, short deleting) {
    if (object) {
        fn_98_B740(static_cast<char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
