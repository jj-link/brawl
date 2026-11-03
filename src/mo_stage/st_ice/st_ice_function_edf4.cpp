#pragma opt_common_subs off
#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_62_A404(void*, int);
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

extern "C" void* fn_62_EDF4(void* self, int flags) {
    if (self) {
        if ((char*)self + 0x6C0) {
            fn_27_26F0D0((char*)self + 0x76C, -1);
            if ((char*)self + 0x6C0 && (char*)self + 0x6C0) {
                __destroy_arr((char*)self + 0x6CC, fn_62_A404, 0xA0, 1);
            }
        }
        if ((char*)self + 0x51C) {
            __dt__24soCollisionHitModuleImplFv((char*)self + 0x658, -1);
            if ((char*)self + 0x614) {
                __destroy_arr((char*)self + 0x620, __dt__19soCollisionHitGroupFv, 0x38, 1);
            }
            if ((char*)self + 0x590) {
                __destroy_arr((char*)self + 0x59C, fn_27_37D3C, 0x78, 1);
            }
            if ((char*)self + 0x51C) {
                __destroy_arr((char*)self + 0x528, __dt__18soCollisionHitPartFv, 0x68, 1);
            }
        }
        if ((char*)self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv((char*)self + 0x47C, -1);
            if ((char*)self + 0x3F4) {
                __destroy_arr((char*)self + 0x400, fn_27_37D3C, 0x78, 1);
            }
            if ((char*)self + 0x358) {
                __destroy_arr((char*)self + 0x364, __dt__21soCollisionAttackPartFv, 0x90, 1);
            }
        }
        fn_27_262FCC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}