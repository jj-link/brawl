#include <new>
#pragma force_active on

extern "C" {
void fn_93_1E9C(void*, short);
void fn_93_1B18(void*, short);
void* fn_93_198C(void*, short);
void* fn_93_9374(void*, short);
void* fn_27_125E20(void*, short);

void* fn_93_93F8(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_93_1E9C(static_cast<char*>(object) + 0x1A2A0, memberDeleting);
        fn_93_1B18(static_cast<char*>(object) + 0x19DE8, memberDeleting);
        fn_93_198C(static_cast<char*>(object) + 0x19DAC, memberDeleting);
        fn_93_9374(static_cast<char*>(object) + 0x194, memberDeleting);
        fn_27_125E20(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
