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
void* fn_94_2F20(void*, short);
void* fn_94_2FB8(void*, short);
void* fn_94_3014(void*, short);
void* fn_94_3164(void*, short);
void* fn_94_4E7C(void*, short);
void* fn_94_4EDC(void*, short);
void* fn_94_5030(void*, short);
void* fn_94_5BA0(void*, short);
void* fn_94_4B58(void*, short);
void* fn_94_5C7C(void*, short);
void* fn_94_5CF0(void*, short);
void* fn_94_5DCC(void*, short);
void* fn_94_5E28(void*, short);
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
void* fn_94_65CC(void*, short);
void* fn_94_6934(void*, short);
void* fn_94_6A08(void*, short);
void* fn_94_6A80(void*, short);
void* fn_94_4D60(void*, short);
void* fn_94_6ADC(void*, short);
}

extern "C" void* fn_94_28AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_2B4C(members + 0x23CEC, memberDeleting);
        fn_94_2BA8(members + 0x23CB0, memberDeleting);
        fn_94_2C04(members + 0x23C48, memberDeleting);
        fn_94_2C60(members + 0x23BFC, memberDeleting);
        fn_94_2CBC(members + 0x23AA8, memberDeleting);
        fn_94_2D18(members + 0x23998, memberDeleting);
        fn_94_2DF4(members + 0x23950, memberDeleting);
        fn_94_2E50(members + 0x238D0, memberDeleting);
        fn_94_2EAC(members + 0x2380C, memberDeleting);
        fn_94_2F20(members + 0x23498, memberDeleting);
        fn_94_2FB8(members + 0x23468, memberDeleting);
        fn_94_3014(members + 0x232C4, memberDeleting);
        fn_94_3164(members + 0x5AF0, memberDeleting);
        fn_94_4E7C(members + 0x590C, memberDeleting);
        fn_94_4EDC(members + 0x5604, memberDeleting);
        fn_94_5030(members + 0x4750, memberDeleting);
        fn_94_5BA0(members + 0x465C, memberDeleting);
        fn_94_4B58(members + 0x4628, memberDeleting);
        fn_94_5C7C(members + 0x45B4, memberDeleting);
        fn_94_5CF0(members + 0x3E90, memberDeleting);
        fn_94_5DCC(members + 0x3E60, memberDeleting);
        fn_94_5E28(members + 0x3CC8, memberDeleting);
        fn_94_5E94(members + 0x3C58, memberDeleting);
        fn_94_5F40(members + 0x3BC0, memberDeleting);
        fn_94_5FB4(members + 0x3B88, memberDeleting);
        fn_94_6010(members + 0x3B64, memberDeleting);
        fn_94_606C(members + 0x3B30, memberDeleting);
        fn_94_60C8(members + 0x3ACC, memberDeleting);
        fn_94_6124(members + 0x391C, memberDeleting);
        fn_94_6198(members + 0x36B8, memberDeleting);
        fn_94_6204(members + 0x2C4C, memberDeleting);
        fn_94_6294(members + 0x2A34, memberDeleting);
        fn_94_6324(members + 0x20D8, memberDeleting);
        fn_94_63A8(members + 0x1A1C, memberDeleting);
        fn_94_642C(members + 0x19A8, memberDeleting);
        fn_94_4BF4(members + 0x196C, memberDeleting);
        fn_94_6560(members + 0x18C4, memberDeleting);
        fn_94_4C50(members + 0x1810, memberDeleting);
        fn_94_65CC(members + 0x147C, memberDeleting);
        fn_94_6934(members + 0x11BC, memberDeleting);
        fn_94_6A08(members + 0x1198, memberDeleting);
        fn_94_6A80(members + 0xB04, memberDeleting);
        fn_94_4D60(members + 0xAEC, memberDeleting);
        reinterpret_cast<soModuleAccesser*>(members + 0xA0C)->soModuleAccesser::~soModuleAccesser();
        fn_94_6ADC(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
