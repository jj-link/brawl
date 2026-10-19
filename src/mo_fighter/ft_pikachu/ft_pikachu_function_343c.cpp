#include <new>
#pragma force_active on

extern "C" {
void* fn_98_33DC(void*, short);
void* fn_98_34A8(void*, short);
}

extern "C" void* fn_98_343C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_33DC(object + 0x1fa4, memberDeleting);
        fn_98_34A8(object + 4, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
