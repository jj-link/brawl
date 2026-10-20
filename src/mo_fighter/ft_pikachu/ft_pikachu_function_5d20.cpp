#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_98_5D98(void*, short);
}

extern "C" void* fn_98_5D20(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_1A1B88(object + 0x2d0, memberDeleting);
        if (object) fn_98_5D98(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
