#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_40_1E2F8(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__24soCollisionHitModuleImplFv(void*, short);
void __dt__19soCollisionHitGroupFv(void*, int);
void fn_27_37D3C(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_40_1DBC0(char* self, int flag) {
    if (self) {
        if (self + 0x1E28) {
            fn_27_26F0D0(self + 0x2D34, -1);
            if (self + 0x1E28 && self + 0x1E28) {
                __destroy_arr(self + 0x1E34, fn_40_1E2F8, 0xA0, 0x18);
            }
        }
        if (self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x1DC0, -1);
            if (self + 0x1874) {
                __destroy_arr(self + 0x1880, __dt__19soCollisionHitGroupFv, 0x38, 0x18);
            }
            if (self + 0xD28) {
                __destroy_arr(self + 0xD34, fn_27_37D3C, 0x78, 0x18);
            }
            if (self + 0x35C) {
                __destroy_arr(self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 0x18);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
