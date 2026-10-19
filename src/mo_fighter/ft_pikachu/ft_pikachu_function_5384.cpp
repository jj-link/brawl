#include <new>
#pragma force_active on

extern "C" {
void* fn_27_B21D0(void*, short);
void* fn_27_CB4A0(void*, short);
}

extern "C" void* fn_98_5384(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_B21D0(object + 0x50, memberDeleting);
        if (object) fn_27_CB4A0(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
