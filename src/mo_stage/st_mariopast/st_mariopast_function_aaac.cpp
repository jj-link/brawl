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
extern "C" void* fn_48_AAAC(char* self, int flags) {
    if (self) {
        if (self + 0x1F40) {
            fn_27_26F0D0(self + 0x2EEC, -1);
            if (self + 0x1F40 && self + 0x1F40) {
                __destroy_arr(self + 0x1F4C, fn_48_3E50, 0xA0, 0x19);
            }
        }
        if (self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x1ED8, -1);
            if (self + 0x1954) {
                __destroy_arr(self + 0x1960, __dt__19soCollisionHitGroupFv, 0x38, 0x19);
            }
            if (self + 0xD90) {
                __destroy_arr(self + 0xD9C, fn_27_37D3C, 0x78, 0x19);
            }
            if (self + 0x35C) {
                __destroy_arr(self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 0x19);
            }
        }
        fn_27_262FCC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}