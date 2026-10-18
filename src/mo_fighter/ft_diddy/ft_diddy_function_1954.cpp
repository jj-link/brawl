#include <st/module.h>
#pragma force_active on

extern "C" {
void* fn_115_19F4(void*, short);
void* fn_115_1DD4(void*, short);
void* fn_115_1E70(void*, short);
void* fn_115_1FA8(void*, short);
void fn_27_125E20(void*, short);
}

extern "C" void* fn_115_1954(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_115_19F4(static_cast<unsigned char*>(object) + 0x267c8, memberDeleting);
        fn_115_1DD4(static_cast<unsigned char*>(object) + 0x26310, memberDeleting);
        fn_115_1E70(static_cast<unsigned char*>(object) + 0x262d4, memberDeleting);
        fn_115_1FA8(static_cast<unsigned char*>(object) + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
