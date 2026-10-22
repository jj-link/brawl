#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1E0914(void*, s32);
void fn_27_3792A8(void*, s32);
void fn_27_31F7B0(void*, s32);
void fn_27_1E096C(void*, s32);
void fn_27_379300(void*, s32);
void fn_27_379358(void*, s32);
void fn_27_3793E0(void*, s32);
void fn_27_379484(void*, s32);
void fn_27_37AC68(void*, s32);
void fn_27_37ACA8(void*, s32);
void fn_27_37AE10(void*, s32);
void fn_27_37AFC8(void*, s32);
void fn_27_1E0B94(void*, s32);
void fn_27_379C2C(void*, s32);
void fn_27_313EF4(void*, s32);
void fn_27_301430(void*, s32);
void fn_27_37B128(void*, s32);
void fn_27_37B184(void*, s32);
void fn_27_37B220(void*, s32);
void fn_27_37B278(void*, s32);
void fn_27_1E30C4(void*, s32);
void fn_27_1E311C(void*, s32);
void fn_27_2DAD00(void*, s32);
void fn_27_37B2D4(void*, s32);
void fn_27_37B3E0(void*, s32);
void fn_27_37B43C(void*, s32);
void fn_27_37B498(void*, s32);
void fn_27_1E0C6C(void*, s32);
void fn_27_37B4F0(void*, s32);
void fn_27_98(void*, s32);
void __dl__FPv(void*);
void __dt__16soModuleAccesserFv(void*, s16);
}

extern "C" void* fn_27_3790E4(void* self, s32 deleting) {
    if (self) {
        u8* p = static_cast<u8*>(self);
        fn_27_1E0914(p + 0x6768, -1);
        fn_27_3792A8(p + 0x6718, -1);
        fn_27_31F7B0(p + 0x65C4, -1);
        fn_27_1E096C(p + 0x6578, -1);
        fn_27_379300(p + 0x64F8, -1);
        fn_27_379358(p + 0x63EC, -1);
        fn_27_3793E0(p + 0x6244, -1);
        fn_27_379484(p + 0x27DC, -1);
        fn_27_37AC68(p + 0x25F0, -1);
        fn_27_37ACA8(p + 0x22E8, -1);
        fn_27_37AE10(p + 0x1BBC, -1);
        fn_27_37AFC8(p + 0x1AC8, -1);
        fn_27_1E0B94(p + 0x1A94, -1);
        fn_27_379C2C(p + 0x1A20, -1);
        fn_27_313EF4(p + 0x1A00, -1);
        fn_27_301430(p + 0x19D0, -1);
        fn_27_37B128(p + 0x1804, -1);
        fn_27_37B184(p + 0x1794, -1);
        fn_27_37B220(p + 0x176C, -1);
        fn_27_37B278(p + 0x16EC, -1);
        fn_27_1E30C4(p + 0x16B0, -1);
        fn_27_1E311C(p + 0x1608, -1);
        fn_27_2DAD00(p + 0x1554, -1);
        fn_27_37B2D4(p + 0x12D4, -1);
        fn_27_37B3E0(p + 0x115C, -1);
        fn_27_37B43C(p + 0x1138, -1);
        fn_27_37B498(p + 0xAA4, -1);
        fn_27_1E0C6C(p + 0xA8C, -1);
        __dt__16soModuleAccesserFv(p + 0x9AC, -1);
        fn_27_37B4F0(self, -1);
        fn_27_98(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
