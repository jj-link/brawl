#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_56_61AC(void*, int);
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

extern "C" void* fn_56_5504(char* self, int flag) {
    if (self) {
        if (self + 0x6C0) {
            fn_27_26F0D0(self + 0x76C, -1);
            if (self + 0x6C0 && self + 0x6C0) {
                __destroy_arr(self + 0x6CC, fn_56_61AC, 0xA0, 1);
            }
        }
        if (self + 0x51C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x658, -1);
            if (self + 0x614) {
                __destroy_arr(self + 0x620, __dt__19soCollisionHitGroupFv, 0x38, 1);
            }
            if (self + 0x590) {
                __destroy_arr(self + 0x59C, fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x51C) {
                __destroy_arr(self + 0x528, __dt__18soCollisionHitPartFv, 0x68, 1);
            }
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
