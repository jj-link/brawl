#include <new>
#pragma force_active on

extern "C" {
void* fn_98_398C(void*, short);
void* fn_98_13724(void*, short);
void* __dl__FPv(void*);
}

extern "C" void* fn_98_136B4(void* object, short deleting) {
    if (object) {
        fn_98_398C(static_cast<char*>(object) + 0x1a84, short(-1));
        fn_98_13724(object, short(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
