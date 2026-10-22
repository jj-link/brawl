#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_40_1E2F8(void*, int);
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

extern "C" void* fn_40_30664(char* self, int flag) {
    if (self) {
        if (self + 0x2040) {
            fn_27_26F0D0(self + 0x286C, -1);
            if (self + 0x2040 && self + 0x2040) {
                __destroy_arr(self + 0x204C, fn_40_1E2F8, 0xA0, 0xD);
            }
        }
        if (self + 0x117C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x1FD8, -1);
            if (self + 0x1CF4) {
                __destroy_arr(self + 0x1D00, __dt__19soCollisionHitGroupFv, 0x38, 0xD);
            }
            if (self + 0x16D0) {
                __destroy_arr(self + 0x16DC, fn_27_37D3C, 0x78, 0xD);
            }
            if (self + 0x117C) {
                __destroy_arr(self + 0x1188, __dt__18soCollisionHitPartFv, 0x68, 0xD);
            }
        }
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x10DC, -1);
            if (self + 0xAB4) {
                __destroy_arr(self + 0xAC0, fn_27_37D3C, 0x78, 0xD);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364, __dt__21soCollisionAttackPartFv, 0x90, 0xD);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
