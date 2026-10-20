#include <new>
#pragma force_active on

extern "C" {
void* fn_98_BB10(void*, short);
void* fn_98_B9E0(char*, short);
}

extern "C" void* fn_98_BB70(char* object, short deleting) {
    if (object) {
        fn_98_BB10(object + 0x94, short(-1));
        if (object)
            fn_98_B9E0(object, short(0));
        if (deleting > 0)
            operator delete(object);
    }
    return object;
}
