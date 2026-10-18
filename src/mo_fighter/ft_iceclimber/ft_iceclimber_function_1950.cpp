#include <new>
#pragma force_active on

extern "C" {
void* fn_105_19F0(void*, short);
void* fn_105_1DD0(void*, short);
void* fn_105_1E6C(void*, short);
void* fn_105_1FA4(void*, short);
void fn_27_125E20(void*, short);

void* fn_105_1950(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_105_19F0(static_cast<char*>(object) + 0x1FD90, memberDeleting);
        fn_105_1DD0(static_cast<char*>(object) + 0x1F8D8, memberDeleting);
        fn_105_1E6C(static_cast<char*>(object) + 0x1F89C, memberDeleting);
        fn_105_1FA4(static_cast<char*>(object) + 0x194, memberDeleting);
        fn_27_125E20(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
