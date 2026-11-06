#include <so/so_module_accesser.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
void* fn_102_2B20(void*, short);
void* fn_102_2B7C(void*, short);
void* fn_102_2BD8(void*, short);
void* fn_102_2C34(void*, short);
void* fn_102_2C90(void*, short);
void* fn_102_2CEC(void*, short);
void* fn_102_2DC8(void*, short);
void* fn_102_2E24(void*, short);
void* fn_102_2E80(void*, short);
void* fn_102_11730(void*, short);
void* fn_102_2F8C(void*, short);
void* fn_102_2FE8(void*, short);
void* fn_102_117B4(void*, short);
void* fn_102_42FC(void*, short);
void* fn_102_435C(void*, short);
void* fn_102_122D8(void*, short);
void* fn_102_5020(void*, short);
void* fn_102_3DF8(void*, short);
void* fn_102_50FC(void*, short);
void* fn_102_5170(void*, short);
void* fn_102_524C(void*, short);
void* fn_102_52A8(void*, short);
void* fn_102_5314(void*, short);
void* fn_102_53C0(void*, short);
void* fn_102_5434(void*, short);
void* fn_102_5490(void*, short);
void* fn_102_54EC(void*, short);
void* fn_102_5548(void*, short);
void* fn_102_55A4(void*, short);
void* fn_102_5618(void*, short);
void* fn_102_5684(void*, short);
void* fn_102_5714(void*, short);
void* fn_102_57A4(void*, short);
void* fn_102_5828(void*, short);
void* fn_102_58AC(void*, short);
void* fn_102_3E94(void*, short);
void* fn_102_3EF0(void*, short);
void* fn_102_3F5C(void*, short);
void* fn_102_123D0(void*, short);
void* fn_102_5DA4(void*, short);
void* fn_102_5E78(void*, short);
void* fn_102_5F30(void*, short);
void* fn_102_3FD0(void*, short);
void* fn_102_5F8C(void*, short);
}

extern "C" void* fn_102_11490(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_2B20(members + 0x1204C, memberDeleting);
        fn_102_2B7C(members + 0x12010, memberDeleting);
        fn_102_2BD8(members + 0x11FA8, memberDeleting);
        fn_102_2C34(members + 0x11F5C, memberDeleting);
        fn_102_2C90(members + 0x11E08, memberDeleting);
        fn_102_2CEC(members + 0x11CF8, memberDeleting);
        fn_102_2DC8(members + 0x11CB0, memberDeleting);
        fn_102_2E24(members + 0x11C30, memberDeleting);
        fn_102_2E80(members + 0x11B6C, memberDeleting);
        fn_102_11730(members + 0x11A60, memberDeleting);
        fn_102_2F8C(members + 0x11A30, memberDeleting);
        fn_102_2FE8(members + 0x1188C, memberDeleting);
        fn_102_117B4(members + 0x5A90, memberDeleting);
        fn_102_42FC(members + 0x58AC, memberDeleting);
        fn_102_435C(members + 0x55A4, memberDeleting);
        fn_102_122D8(members + 0x4714, memberDeleting);
        fn_102_5020(members + 0x4620, memberDeleting);
        fn_102_3DF8(members + 0x45EC, memberDeleting);
        fn_102_50FC(members + 0x4578, memberDeleting);
        fn_102_5170(members + 0x3E54, memberDeleting);
        fn_102_524C(members + 0x3E24, memberDeleting);
        fn_102_52A8(members + 0x3C8C, memberDeleting);
        fn_102_5314(members + 0x3C1C, memberDeleting);
        fn_102_53C0(members + 0x3B84, memberDeleting);
        fn_102_5434(members + 0x3B4C, memberDeleting);
        fn_102_5490(members + 0x3B28, memberDeleting);
        fn_102_54EC(members + 0x3AF4, memberDeleting);
        fn_102_5548(members + 0x3A90, memberDeleting);
        fn_102_55A4(members + 0x38E0, memberDeleting);
        fn_102_5618(members + 0x367C, memberDeleting);
        fn_102_5684(members + 0x2C10, memberDeleting);
        fn_102_5714(members + 0x29F8, memberDeleting);
        fn_102_57A4(members + 0x209C, memberDeleting);
        fn_102_5828(members + 0x19E0, memberDeleting);
        fn_102_58AC(members + 0x196C, memberDeleting);
        fn_102_3E94(members + 0x1930, memberDeleting);
        fn_102_3EF0(members + 0x1888, memberDeleting);
        fn_102_3F5C(members + 0x17D4, memberDeleting);
        fn_102_123D0(members + 0x1440, memberDeleting);
        fn_102_5DA4(members + 0x1180, memberDeleting);
        fn_102_5E78(members + 0x115C, memberDeleting);
        fn_102_5F30(members + 0xAC8, memberDeleting);
        fn_102_3FD0(members + 0xAB0, memberDeleting);
        reinterpret_cast<soModuleAccesser*>(members + 0x9D0)->soModuleAccesser::~soModuleAccesser();
        fn_102_5F8C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
