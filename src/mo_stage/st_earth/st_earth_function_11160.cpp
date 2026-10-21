#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_66_A0EC(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__24soCollisionHitModuleImplFv(void*, short);
void __dt__19soCollisionHitGroupFv(void*, int);
void fn_27_37D3C(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_66_11160(char* self, int flags) {
    if (self) {
        if (self + 0x568) {
            fn_27_26F0D0(self + 0x614, -1);
            if (self + 0x568 && self + 0x568) {
                __destroy_arr(self + 0x574, fn_66_A0EC, 0xA0, 1);
            }
        }
        if (self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x500, -1);
            if (self + 0x4BC) {
                __destroy_arr(self + 0x4C8, __dt__19soCollisionHitGroupFv, 0x38, 1);
            }
            if (self + 0x438) {
                __destroy_arr(self + 0x444, fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x35C) {
                __destroy_arr(self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 2);
            }
        }
        fn_27_262FCC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
