#include <so/so_module_accesser.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
void* fn_94_2B4C(void*, short);
void* fn_94_2BA8(void*, short);
void* fn_94_2C04(void*, short);
void* fn_94_2C60(void*, short);
void* fn_94_2CBC(void*, short);
void* fn_94_2D18(void*, short);
void* fn_94_2DF4(void*, short);
void* fn_94_2E50(void*, short);
void* fn_94_2EAC(void*, short);
void* fn_94_13EDC(void*, short);
void* fn_94_2FB8(void*, short);
void* fn_94_3014(void*, short);
void* fn_94_13F74(void*, short);
void* fn_94_4E7C(void*, short);
void* fn_94_4EDC(void*, short);
void* fn_94_16438(void*, short);
void* fn_94_5BA0(void*, short);
void* fn_94_4B58(void*, short);
void* fn_94_5C7C(void*, short);
void* fn_94_5CF0(void*, short);
void* fn_94_5DCC(void*, short);
void* fn_94_16530(void*, short);
void* fn_94_5E94(void*, short);
void* fn_94_5F40(void*, short);
void* fn_94_5FB4(void*, short);
void* fn_94_6010(void*, short);
void* fn_94_606C(void*, short);
void* fn_94_60C8(void*, short);
void* fn_94_6124(void*, short);
void* fn_94_6198(void*, short);
void* fn_94_6204(void*, short);
void* fn_94_6294(void*, short);
void* fn_94_6324(void*, short);
void* fn_94_63A8(void*, short);
void* fn_94_642C(void*, short);
void* fn_94_4BF4(void*, short);
void* fn_94_6560(void*, short);
void* fn_94_4C50(void*, short);
void* fn_94_1659C(void*, short);
void* fn_94_6934(void*, short);
void* fn_94_6A08(void*, short);
void* fn_94_6A80(void*, short);
void* fn_94_4D60(void*, short);
void* fn_94_16650(void*, short);
}

extern "C" void* fn_94_13C3C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_2B4C(members + 0x17DF0, memberDeleting);
        fn_94_2BA8(members + 0x17DB4, memberDeleting);
        fn_94_2C04(members + 0x17D4C, memberDeleting);
        fn_94_2C60(members + 0x17D00, memberDeleting);
        fn_94_2CBC(members + 0x17BAC, memberDeleting);
        fn_94_2D18(members + 0x17A9C, memberDeleting);
        fn_94_2DF4(members + 0x17A54, memberDeleting);
        fn_94_2E50(members + 0x179D4, memberDeleting);
        fn_94_2EAC(members + 0x17910, memberDeleting);
        fn_94_13EDC(members + 0x17578, memberDeleting);
        fn_94_2FB8(members + 0x17548, memberDeleting);
        fn_94_3014(members + 0x173A4, memberDeleting);
        fn_94_13F74(members + 0x5AB8, memberDeleting);
        fn_94_4E7C(members + 0x58D4, memberDeleting);
        fn_94_4EDC(members + 0x55CC, memberDeleting);
        fn_94_16438(members + 0x4748, memberDeleting);
        fn_94_5BA0(members + 0x4654, memberDeleting);
        fn_94_4B58(members + 0x4620, memberDeleting);
        fn_94_5C7C(members + 0x45AC, memberDeleting);
        fn_94_5CF0(members + 0x3E88, memberDeleting);
        fn_94_5DCC(members + 0x3E58, memberDeleting);
        fn_94_16530(members + 0x3C8C, memberDeleting);
        fn_94_5E94(members + 0x3C1C, memberDeleting);
        fn_94_5F40(members + 0x3B84, memberDeleting);
        fn_94_5FB4(members + 0x3B4C, memberDeleting);
        fn_94_6010(members + 0x3B28, memberDeleting);
        fn_94_606C(members + 0x3AF4, memberDeleting);
        fn_94_60C8(members + 0x3A90, memberDeleting);
        fn_94_6124(members + 0x38E0, memberDeleting);
        fn_94_6198(members + 0x367C, memberDeleting);
        fn_94_6204(members + 0x2C10, memberDeleting);
        fn_94_6294(members + 0x29F8, memberDeleting);
        fn_94_6324(members + 0x209C, memberDeleting);
        fn_94_63A8(members + 0x19E0, memberDeleting);
        fn_94_642C(members + 0x196C, memberDeleting);
        fn_94_4BF4(members + 0x1930, memberDeleting);
        fn_94_6560(members + 0x1888, memberDeleting);
        fn_94_4C50(members + 0x17D4, memberDeleting);
        fn_94_1659C(members + 0x1440, memberDeleting);
        fn_94_6934(members + 0x1180, memberDeleting);
        fn_94_6A08(members + 0x115C, memberDeleting);
        fn_94_6A80(members + 0xAC8, memberDeleting);
        fn_94_4D60(members + 0xAB0, memberDeleting);
        reinterpret_cast<soModuleAccesser*>(members + 0x9D0)->soModuleAccesser::~soModuleAccesser();
        fn_94_16650(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
