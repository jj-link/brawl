#include <new>
#pragma force_active on

extern "C" {
void fn_27_57BA0(void*, short);
void* fn_98_1E98(void*, short);
void* fn_98_1EF4(void*, short);
}

extern "C" void* fn_98_1E18(char* object, short deleting) {
    if (object) {
        if (object + 0x20) fn_27_57BA0(object + 0x20, 0);
        fn_98_1E98(object + 0x14, 0);
        fn_98_1EF4(object + 8, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
