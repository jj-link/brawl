#pragma force_active on
extern "C" {
void fn_27_26F0D0(void*, int);
void fn_48_3E50(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__24soCollisionHitModuleImplFv(void*, short);
void __dt__19soCollisionHitGroupFv(void*, int);
void fn_27_37D3C(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
}
extern "C" void* fn_48_A88C(char* self, int flag) {
    if (self) {
        if (self + 0xE420) {
            fn_27_26F0D0(self + 0x1644C, -1);
            if (self + 0xE420) {
                if (self + 0xE420) {
                    __destroy_arr(self + 0xE42C, fn_48_3E50, 0xA0, 0xCD);
                }
            }
        }
        if (self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv(self + 0xE3B8, -1);
            if (self + 0xB6D4) {
                __destroy_arr(self + 0xB6E0, __dt__19soCollisionHitGroupFv, 0x38, 0xCD);
            }
            if (self + 0x56B0) {
                __destroy_arr(self + 0x56BC, fn_27_37D3C, 0x78, 0xCD);
            }
            if (self + 0x35C) {
                __destroy_arr(self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 0xCD);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}