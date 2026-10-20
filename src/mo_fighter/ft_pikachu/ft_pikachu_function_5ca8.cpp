#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_98_5D20(void*, short);
}

extern "C" void* fn_98_5CA8(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_1A15B8(object + 0x2fc, memberDeleting);
        if (object) fn_98_5D20(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
