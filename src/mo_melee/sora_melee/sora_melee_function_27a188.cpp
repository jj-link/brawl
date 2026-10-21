#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void fn_27_26F0D0(void*, s32);
void __dt__27soCollisionAttackModuleImplFv(void*, short);
void __dt__21soCollisionAttackPartFv(void*, short);
void fn_27_37D3C(void*, short);
void fn_27_262FCC(void*, s32);
void __destroy_arr(void*, void (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_27A188(u8* self, s32 flag) {
    if (self) {
        if (self + 0x520) {
            fn_27_26F0D0(self + 0x524, -1);
        }
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x47C, -1);
            if (self + 0x3F4) {
                __destroy_arr(self + 0x400, fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364, __dt__21soCollisionAttackPartFv, 0x90, 1);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
