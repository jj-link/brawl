#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void* fn_96_8460(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_96_7A08(void*, short);
void* fn_96_7A74(void*, short);
void* fn_96_7B00(void*, short);
void* fn_96_7B8C(void*, short);
void* fn_96_6B10(void*, short);
void* fn_96_6AD0(void*, short);
void* fn_96_6BAC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_96_7C18(void*, short);
void* fn_96_6C08(void*, short);
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_84FC(void*, short);
void* fn_96_5F44(void*, short);
void* fn_96_853C(void*, short);
void* fn_96_4CE8(void*, short);
void* fn_96_4C88(void*, short);
void* fn_27_1A4B88(void*, short);
void* fn_96_7D5C(void*, short);
void* fn_96_4E2C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_96_6D7C(void*, short);
void* fn_96_27B8(void*, short);
void* fn_96_6E04(void*, short);
void* fn_96_6E60(void*, short);
void* fn_96_7DE4(void*, short);
void* fn_96_6ECC(void*, short);
void* fn_96_7E44(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CCC8(void*, short);
void* fn_96_6F2C(void*, short);
void* fn_96_259C(void*, short);
void* fn_96_2530(void*, short);
void* fn_96_24BC(void*, short);
void* fn_96_7EA0(void*, short);
void* fn_96_7040(void*, short);
void* fn_96_70AC(void*, short);
void* fn_96_7124(void*, short);
void* fn_96_2460(void*, short);
void* fn_96_7F18(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_96_817C(void* object, int deleting) {
    if (object) {
        if (object) {
            short d = -1;
            fn_96_8460(static_cast<char*>(object) + 0x2034, d);
            fn_27_1DBB60(static_cast<char*>(object) + 0x1ffc, d);
            char* p = static_cast<char*>(object);
            if (p + 0xcc) {
                if (p + 0x1a4c) {
                    fn_96_7A08(p + 0x1efc, d);
                    fn_96_7A74(p + 0x1dd0, d);
                    fn_96_7B00(p + 0x1ca4, d);
                    fn_96_7B8C(p + 0x1b78, d);
                    if (p + 0x1a4c) {
                        fn_96_6B10(p + 0x1b28, d);
                        fn_96_6AD0(p + 0x1b0c, d);
                        fn_96_6BAC(p + 0x1a60, d);
                        if (p + 0x1a4c) fn_27_C7770(p + 0x1a4c, d);
                    }
                }
                if (p + 0xcc) {
                    fn_96_7C18(p + 0x1a08, d);
                    fn_96_6C08(p + 0x19f0, d);
                    fn_96_7C74(p + 0x1854, d);
                    fn_96_6D1C(p + 0x17f4, d);
                    if (p + 0x1710) {
                        fn_96_84FC(p + 0x17f0, d);
                        fn_96_5F44(p + 0x1740, d);
                        fn_96_853C(p + 0x1710, d);
                    }
                    if (p + 0x1534) {
                        fn_96_4CE8(p + 0x1660, d);
                        fn_96_4C88(p + 0x164c, d);
                        if (p + 0x1628) fn_27_1A4B88(p + 0x1628, d);
                        fn_96_7D5C(p + 0x1584, d);
                        if (p + 0x1544) fn_96_4E2C(p + 0x1560, d);
                        fn_27_C74E8(p + 0x1534, d);
                    }
                    fn_96_6D7C(p + 0x1490, d);
                    fn_96_27B8(p + 0x145c, d);
                    fn_96_6E04(p + 0x1444, d);
                    fn_96_6E60(p + 0x12e0, d);
                    fn_96_7DE4(p + 0x1278, d);
                    fn_96_6ECC(p + 0x126c, d);
                    fn_96_7E44(p + 0x1244, d);
                    if (p + 0xfe4) {
                        __dt__27soCollisionAttackModuleImplFv(p + 0x1198, d);
                        fn_27_82AD4(p + 0x1194, d);
                        fn_27_4CAA0(p + 0x1110, d);
                        fn_27_19CCC8(p + 0xfe4, d);
                    }
                    fn_96_6F2C(p + 0xf80, d);
                    fn_96_259C(p + 0xf44, d);
                    fn_96_2530(p + 0xe9c, d);
                    fn_96_24BC(p + 0xde8, d);
                    fn_96_7EA0(p + 0xbdc, d);
                    fn_96_7040(p + 0x9fc, d);
                    fn_96_70AC(p + 0x9cc, d);
                    fn_96_7124(p + 0x9bc, d);
                    fn_96_2460(p + 0x9a4, d);
                    reinterpret_cast<soModuleAccesser*>(p + 0x8c4)->soModuleAccesser::~soModuleAccesser();
                    fn_96_7F18(p + 0xcc, d);
                }
            }
            fn_27_1D81C8(p, static_cast<short>(0));
        }
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
