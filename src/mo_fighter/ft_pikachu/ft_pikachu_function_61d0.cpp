#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_98_6248(char*, short);
}

extern "C" void* fn_98_61D0(char* object, short deleting) {
    if (object) {
        fn_27_1A1B88(object + 0x88, short(-1));
        if (object) fn_98_6248(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
