#include <so/so_module_accesser.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
void* fn_115_2B84(void*, short);
void* fn_115_2BE0(void*, short);
void* fn_115_2C3C(void*, short);
void* fn_115_2C98(void*, short);
void* fn_115_2CF4(void*, short);
void* fn_115_2D50(void*, short);
void* fn_115_2E2C(void*, short);
void* fn_115_2E88(void*, short);
void* fn_115_2EE4(void*, short);
void* fn_115_2F58(void*, short);
void* fn_115_2FF0(void*, short);
void* fn_115_304C(void*, short);
void* fn_115_319C(void*, short);
void* fn_115_478C(void*, short);
void* fn_115_47EC(void*, short);
void* fn_115_4938(void*, short);
void* fn_115_54A8(void*, short);
void* fn_115_3CF8(void*, short);
void* fn_115_5584(void*, short);
void* fn_115_55F8(void*, short);
void* fn_115_56D4(void*, short);
void* fn_115_5730(void*, short);
void* fn_115_579C(void*, short);
void* fn_115_5848(void*, short);
void* fn_115_58BC(void*, short);
void* fn_115_5918(void*, short);
void* fn_115_5974(void*, short);
void* fn_115_59D0(void*, short);
void* fn_115_5A2C(void*, short);
void* fn_115_5AA0(void*, short);
void* fn_115_5B0C(void*, short);
void* fn_115_5B9C(void*, short);
void* fn_115_5C2C(void*, short);
void* fn_115_5CB0(void*, short);
void* fn_115_5D34(void*, short);
void* fn_115_5E68(void*, short);
void* fn_115_5EC4(void*, short);
void* fn_115_5F30(void*, short);
void* fn_115_5FA4(void*, short);
void* fn_115_6368(void*, short);
void* fn_115_643C(void*, short);
void* fn_115_64B4(void*, short);
void* fn_115_3DD4(void*, short);
void* fn_115_6510(void*, short);
}

extern "C" void* fn_115_28E4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_115_2B84(members + 0x24954, memberDeleting);
        fn_115_2BE0(members + 0x24918, memberDeleting);
        fn_115_2C3C(members + 0x248B0, memberDeleting);
        fn_115_2C98(members + 0x24864, memberDeleting);
        fn_115_2CF4(members + 0x24710, memberDeleting);
        fn_115_2D50(members + 0x24600, memberDeleting);
        fn_115_2E2C(members + 0x245B8, memberDeleting);
        fn_115_2E88(members + 0x24538, memberDeleting);
        fn_115_2EE4(members + 0x24474, memberDeleting);
        fn_115_2F58(members + 0x24100, memberDeleting);
        fn_115_2FF0(members + 0x240D0, memberDeleting);
        fn_115_304C(members + 0x23F2C, memberDeleting);
        fn_115_319C(members + 0x5B2C, memberDeleting);
        fn_115_478C(members + 0x5948, memberDeleting);
        fn_115_47EC(members + 0x5640, memberDeleting);
        fn_115_4938(members + 0x4714, memberDeleting);
        fn_115_54A8(members + 0x4620, memberDeleting);
        fn_115_3CF8(members + 0x45EC, memberDeleting);
        fn_115_5584(members + 0x4578, memberDeleting);
        fn_115_55F8(members + 0x3E54, memberDeleting);
        fn_115_56D4(members + 0x3E24, memberDeleting);
        fn_115_5730(members + 0x3C8C, memberDeleting);
        fn_115_579C(members + 0x3C1C, memberDeleting);
        fn_115_5848(members + 0x3B84, memberDeleting);
        fn_115_58BC(members + 0x3B4C, memberDeleting);
        fn_115_5918(members + 0x3B28, memberDeleting);
        fn_115_5974(members + 0x3AF4, memberDeleting);
        fn_115_59D0(members + 0x3A90, memberDeleting);
        fn_115_5A2C(members + 0x38E0, memberDeleting);
        fn_115_5AA0(members + 0x367C, memberDeleting);
        fn_115_5B0C(members + 0x2C10, memberDeleting);
        fn_115_5B9C(members + 0x29F8, memberDeleting);
        fn_115_5C2C(members + 0x209C, memberDeleting);
        fn_115_5CB0(members + 0x19E0, memberDeleting);
        fn_115_5D34(members + 0x196C, memberDeleting);
        fn_115_5E68(members + 0x1930, memberDeleting);
        fn_115_5EC4(members + 0x1888, memberDeleting);
        fn_115_5F30(members + 0x17D4, memberDeleting);
        fn_115_5FA4(members + 0x1440, memberDeleting);
        fn_115_6368(members + 0x1180, memberDeleting);
        fn_115_643C(members + 0x115C, memberDeleting);
        fn_115_64B4(members + 0xAC8, memberDeleting);
        fn_115_3DD4(members + 0xAB0, memberDeleting);
        reinterpret_cast<soModuleAccesser*>(members + 0x9D0)->soModuleAccesser::~soModuleAccesser();
        fn_115_6510(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
