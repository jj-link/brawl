#include <new>
#pragma force_active on

extern "C" {
void* fn_27_150488(void*, short);
void* fn_98_64D4(void*, short);
void* fn_27_199A54(void*, short);
}

extern "C" void* fn_98_6454(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_150488(object + 0x5b8, memberDeleting);
        fn_98_64D4(object + 0x584, memberDeleting);
        if (object) fn_27_199A54(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
