#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_72_4DA8(void*, int);
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

extern "C" void* fn_72_BC58(char* self, int flag) {
    if (self) {
        if (self + 0x8B0) {
            fn_27_26F0D0(self + 0x95C, -1);
            if (self + 0x8B0 && self + 0x8B0) {
                __destroy_arr(self + 0x8BC, fn_72_4DA8, 0xA0, 1);
            }
        }
        if (self + 0x63C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x848, -1);
            if (self + 0x804) {
                __destroy_arr(self + 0x810, __dt__19soCollisionHitGroupFv, 0x38, 1);
            }
            if (self + 0x780) {
                __destroy_arr(self + 0x78C, fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x63C) {
                __destroy_arr(self + 0x648, __dt__18soCollisionHitPartFv, 0x68, 3);
            }
        }
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x59C, -1);
            if (self + 0x514) {
                __destroy_arr(self + 0x520, fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364, __dt__21soCollisionAttackPartFv, 0x90, 3);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
