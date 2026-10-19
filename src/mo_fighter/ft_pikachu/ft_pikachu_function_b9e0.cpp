#include <new>
#pragma force_active on

extern "C" {
void* fn_98_B980(void*, short);
void* fn_98_B860(void*, short);
}

extern "C" void* fn_98_B9E0(char* object, short deleting) {
    if (object) {
        fn_98_B980(object + 0x60, short(-1));
        fn_98_B860(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
