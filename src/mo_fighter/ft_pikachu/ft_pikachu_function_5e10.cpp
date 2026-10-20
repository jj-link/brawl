#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_98_5E88(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_5E10(void* object, short deleting) {
    if (object) {
        fn_27_1A1B88(static_cast<char*>(object) + 0x218, short(-1));
        if (object) fn_98_5E88(object, short(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
