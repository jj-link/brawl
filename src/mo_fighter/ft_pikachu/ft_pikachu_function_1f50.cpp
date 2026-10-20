#include <new>
#pragma force_active on

extern "C" {
void* fn_98_1FD4(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_98_288C(void*, short);

void* fn_98_1F50(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_1FD4(object + 0x29120, memberDeleting);
        fn_27_C74E8(object + 0x29110, memberDeleting);
        fn_98_288C(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
