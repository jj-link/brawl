#include <new>
#pragma force_active on

extern "C" {
void* fn_98_33DC(void*, short);
void* fn_98_343C(void*, short);

void* fn_98_3370(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_33DC(object + 0x3f40, memberDeleting);
        fn_98_343C(object + 4, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
