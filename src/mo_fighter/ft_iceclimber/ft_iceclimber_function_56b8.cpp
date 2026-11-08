#include <so/collision/so_collision_attack_module_impl.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/so_module_accesser.h>
#pragma force_active on

void operator delete(void*);

extern "C" {
void* fn_105_3674(void*, short);
void* fn_105_51C4(void*, short);
void* fn_105_3814(void*, short);
void* fn_105_218C(void*, short);
void* fn_105_2228(void*, short);
void* fn_105_2268(void*, short);
void* fn_27_C7770(void*, short);
void* fn_105_3A80(void*, short);
void* fn_105_3ADC(void*, short);
void* fn_105_3B38(void*, short);
void* fn_27_93100(void*, short);
void* fn_27_19EB34(void*, short);
void* fn_27_1A4E94(void*, short);
void* fn_105_3BC4(void*, short);
void* fn_105_102B8(void*, short);
void* fn_105_5220(void*, short);
void* fn_105_5290(void*, short);
void* fn_105_3EA0(void*, short);
void* fn_105_3F78(void*, short);
void* fn_27_1A4778(void*, short);
void* fn_105_3FD8(void*, short);
void* fn_105_4100(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_105_4160(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_42F0(void*, short);
void* fn_105_434C(void*, short);
void* fn_105_43B8(void*, short);
void* fn_27_689B0(void*, short);
void* fn_27_C9A14(void*, short);
void* fn_105_4478(void*, short);
void* fn_105_52FC(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CC654(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_19D158(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_5370(void*, short);
void* fn_105_4680(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_105_476C(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4860(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* fn_105_49B4(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_105_56B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (p + 0x2718 != 0) {
            if (p + 0x2718 != 0) {
                fn_105_3674(p + 0x2718, 0);
            }
        }
        fn_105_51C4(p + 0x2708, 0);
        if (object != 0) {
            if (p + 0xCC != 0) {
                if (p + 0x2154 != 0) {
                    fn_105_3814(p + 0x2604, -1);
                    if (p + 0x24D8 != 0) {
                        fn_105_218C(p + 0x25B4, -1);
                        fn_105_2228(p + 0x2598, -1);
                        fn_105_2268(p + 0x24EC, -1);
                        if (p + 0x24D8 != 0)
                            fn_27_C7770(p + 0x24D8, -1);
                    }
                    if (p + 0x23AC != 0) {
                        fn_105_218C(p + 0x2488, -1);
                        fn_105_2228(p + 0x246C, -1);
                        fn_105_2268(p + 0x23C0, -1);
                        if (p + 0x23AC != 0)
                            fn_27_C7770(p + 0x23AC, -1);
                    }
                    if (p + 0x2280 != 0) {
                        fn_105_218C(p + 0x235C, -1);
                        fn_105_2228(p + 0x2340, -1);
                        fn_105_2268(p + 0x2294, -1);
                        if (p + 0x2280 != 0)
                            fn_27_C7770(p + 0x2280, -1);
                    }
                    if (p + 0x2154 != 0) {
                        fn_105_218C(p + 0x2230, -1);
                        fn_105_2228(p + 0x2214, -1);
                        fn_105_2268(p + 0x2168, -1);
                        if (p + 0x2154 != 0)
                            fn_27_C7770(p + 0x2154, -1);
                    }
                }
                if (p + 0xCC != 0) {
                    fn_105_3A80(p + 0x2110, -1);
                    fn_105_3ADC(p + 0x20F8, -1);
                    fn_105_3B38(p + 0x1F5C, -1);
                    if (p + 0x1EF0 != 0) {
                        fn_27_93100(p + 0x1F20, -1);
                        fn_27_19EB34(p + 0x1F00, -1);
                        fn_27_1A4E94(p + 0x1EF0, -1);
                    }
                    fn_105_3BC4(p + 0x1E94, -1);
                    if (p + 0x1D6C != 0) {
                        if (p + 0x1E4C != 0)
                            fn_105_102B8(p + 0x1E50, -1);
                        fn_105_5220(p + 0x1D9C, -1);
                        fn_105_5290(p + 0x1D6C, -1);
                    }
                    if (p + 0x1BA0 != 0) {
                        fn_105_3EA0(p + 0x1CBC, -1);
                        fn_105_3F78(p + 0x1CA8, -1);
                        if (p + 0x1C8C != 0)
                            fn_27_1A4778(p + 0x1C8C, -1);
                        fn_105_3FD8(p + 0x1BE8, -1);
                        fn_105_4100(p + 0x1BB0, -1);
                        fn_27_C74E8(p + 0x1BA0, -1);
                    }
                    fn_105_4160(p + 0x1AFC, -1);
                    fn_105_4294(p + 0x1AC8, -1);
                    fn_105_42F0(p + 0x1AB0, -1);
                    fn_105_434C(p + 0x194C, -1);
                    fn_105_43B8(p + 0x18E4, -1);
                    if (p + 0x18A0 != 0) {
                        fn_27_689B0(p + 0x18C8, -1);
                        if (p + 0x18A0 != 0)
                            fn_27_C9A14(p + 0x18A0, -1);
                    }
                    fn_105_4478(p + 0x1878, -1);
                    fn_105_52FC(p + 0x171C, -1);
                    if (p + 0x1508 != 0) {
                        reinterpret_cast<soCollisionHitModuleImpl*>(p + 0x16AC)
                            ->soCollisionHitModuleImpl::~soCollisionHitModuleImpl();
                        fn_27_CC984(p + 0x1668, -1);
                        fn_27_4CAA0(p + 0x15E4, -1);
                        fn_27_CC654(p + 0x1508, -1);
                    }
                    if (p + 0xFE4 != 0) {
                        reinterpret_cast<soCollisionAttackModuleImpl*>(p + 0x1468)
                            ->soCollisionAttackModuleImpl::~soCollisionAttackModuleImpl();
                        fn_27_82AD4(p + 0x1464, -1);
                        fn_27_4CAA0(p + 0x13E0, -1);
                        fn_27_19D158(p + 0xFE4, -1);
                    }
                    fn_105_4558(p + 0xF80, -1);
                    fn_105_4624(p + 0xF44, -1);
                    fn_105_5370(p + 0xE9C, -1);
                    fn_105_4680(p + 0xDE8, -1);
                    if (p + 0xBDC != 0) {
                        fn_27_13C90(p + 0xC78, -1);
                        fn_27_21038(p + 0xC64, -1);
                        fn_105_476C(p + 0xBDC, -1);
                    }
                    fn_105_47F4(p + 0x9FC, -1);
                    fn_105_4860(p + 0x9CC, -1);
                    fn_105_4918(p + 0x9BC, -1);
                    fn_105_4958(p + 0x9A4, -1);
                    reinterpret_cast<soModuleAccesser*>(p + 0x8C4)
                        ->soModuleAccesser::~soModuleAccesser();
                    fn_105_49B4(p + 0xCC, -1);
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0)
            operator delete(object);
    }
    return object;
}
