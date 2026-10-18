#include <new>
#pragma force_active on

extern "C" {
void* fn_27_B81C4(void*, short);
void* fn_98_2D78(void*, short);
void* fn_27_198034(void*, short);
}

extern "C" void* fn_98_2CF8(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_B81C4(object + 0xa4, memberDeleting);
        fn_98_2D78(object + 0x48, memberDeleting);
        if (object) fn_27_198034(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
