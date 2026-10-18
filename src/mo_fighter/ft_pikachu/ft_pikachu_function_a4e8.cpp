#include <new>
#pragma force_active on

extern "C" {
void* fn_98_C3D4(void*, short);
void __dl__FPv(void*);

void* fn_98_A4E8(void* object, short deleting) {
    if (object) {
        fn_98_C3D4(static_cast<char*>(object) + 4, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
