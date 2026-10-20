#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_98_49EC(void*, short);

void* fn_98_4974(void* object, int deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_13C90(static_cast<char*>(object) + 0x9c, memberDeleting);
        fn_27_21038(static_cast<char*>(object) + 0x88, memberDeleting);
        fn_98_49EC(object, memberDeleting);
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
}
