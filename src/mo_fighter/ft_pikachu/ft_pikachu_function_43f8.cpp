#include <new>
#pragma force_active on

extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_98_4480(void*, short);
extern "C" void* fn_98_44C0(char*, short);

extern "C" void* fn_98_43F8(char* object, short deleting) {
    if (object) {
        if (object + 0x24) {
            fn_27_1A262C(object + 0x34, short(-1));
            fn_98_4480(object + 0x24, short(0));
        }
        fn_98_44C0(object, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
