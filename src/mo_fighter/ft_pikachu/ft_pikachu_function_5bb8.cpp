#include <new>
#pragma force_active on

extern "C" {
void fn_27_1A18A0(void*, short);
void* fn_98_5C30(void*, short);
}

extern "C" void* fn_98_5BB8(char* object, short deleting) {
    if (object) {
        fn_27_1A18A0(object + 0x354, short(-1));
        if (object) fn_98_5C30(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
