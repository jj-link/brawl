#include <new>
#pragma force_active on

extern "C" {
void* fn_27_689B0(void*, short);
void* fn_27_1985B4(void*, short);
}

extern "C" void* fn_98_66A4(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_689B0(object + 0x7c, memberDeleting);
        if (object) fn_27_1985B4(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
