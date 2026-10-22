#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_63_ABDC(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__24soCollisionHitModuleImplFv(void*, short);
void __dt__19soCollisionHitGroupFv(void*, int);
void fn_27_37D3C(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void __dt__27soCollisionAttackModuleImplFv(void*, short);
void __dt__21soCollisionAttackPartFv(void*, int);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_63_9874(char* self, int flag) {
    if (self) {
        if (self + 0xA38) {
            fn_27_26F0D0(self + 0xAE4, -1);
            if (self + 0xA38 && self + 0xA38) {
                __destroy_arr(self + 0xA44, fn_63_ABDC, 0xA0, 1);
            }
        }
        if (self + 0x75C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x9D0, -1);
            if (self + 0x98C) {
                __destroy_arr(self + 0x998, __dt__19soCollisionHitGroupFv, 0x38, 1);
            }
            if (self + 0x908) {
                __destroy_arr(self + 0x914, fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x75C) {
                __destroy_arr(self + 0x768, __dt__18soCollisionHitPartFv, 0x68, 4);
            }
        }
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x6BC, -1);
            if (self + 0x634) {
                __destroy_arr(self + 0x640, fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364, __dt__21soCollisionAttackPartFv, 0x90, 5);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
