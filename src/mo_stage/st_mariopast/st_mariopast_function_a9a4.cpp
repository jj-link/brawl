#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_48_3E50(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__24soCollisionHitModuleImplFv(void*, short);
void __dt__19soCollisionHitGroupFv(void*, int);
void fn_27_37D3C(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_48_A9A4(char* self, int flags) {
    if (self) {
        if (self + 0x4358) {
            fn_27_26F0D0(self + 0x67A4, -1);
            if (self + 0x4358 && self + 0x4358) {
                __destroy_arr(self + 0x4364, fn_48_3E50, 0xA0, 0x3A);
            }
        }
        if (self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x42F0, -1);
            if (self + 0x3634) {
                __destroy_arr(self + 0x3640, __dt__19soCollisionHitGroupFv, 0x38, 0x3A);
            }
            if (self + 0x1AF8) {
                __destroy_arr(self + 0x1B04, fn_27_37D3C, 0x78, 0x3A);
            }
            if (self + 0x35C) {
                __destroy_arr(self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 0x3A);
            }
        }
        fn_27_262FCC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
