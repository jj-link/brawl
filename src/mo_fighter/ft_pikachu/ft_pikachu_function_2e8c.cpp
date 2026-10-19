#include <new>
#pragma force_active on

extern "C" {
void* fn_27_10424(void*, short);
void* fn_27_19A97C(void*, short);
}

extern "C" void* fn_98_2E8C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_10424(object + 0x7C, memberDeleting);
        if (object) fn_27_19A97C(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
