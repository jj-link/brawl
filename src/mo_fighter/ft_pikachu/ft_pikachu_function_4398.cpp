#include <new>
#pragma force_active on

extern "C" {
void* fn_98_3F10(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_4398(void* object, short deleting) {
    if (object) {
        fn_98_3F10(static_cast<char*>(object) + 0x14, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
