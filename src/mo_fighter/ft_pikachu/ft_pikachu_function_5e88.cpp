#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_98_5F00(void*, short);
}

extern "C" void* fn_98_5E88(void* object, short deleting) {
    if (object) {
        fn_27_1A15B8((char*)object + 0x1fc, short(-1));
        if (object) fn_98_5F00(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
