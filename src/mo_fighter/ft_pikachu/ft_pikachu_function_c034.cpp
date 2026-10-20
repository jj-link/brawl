#include <new>
#pragma force_active on

extern "C" void* fn_98_BFD4(void*, short);
extern "C" void* fn_98_BE9C(void*, short);

extern "C" void* fn_98_C034(char* object, short deleting) {
    if (object) {
        fn_98_BFD4(object + 0x17c, short(-1));
        if (object) fn_98_BE9C(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
