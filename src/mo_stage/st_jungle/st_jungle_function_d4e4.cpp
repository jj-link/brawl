#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_51_6278(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__24soCollisionHitModuleImplFv(void*, short);
void __dt__19soCollisionHitGroupFv(void*, int);
void fn_27_37D3C(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_51_D4E4(char* self, int flag) {
    if (self) {
        if (self + 0x618) {
            fn_27_26F0D0(self + 0x764, -1);
            if (self + 0x618 && self + 0x618) {
                __destroy_arr(self + 0x624, fn_51_6278, 0xA0, 2);
            }
        }
        if (self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv(self + 0x5B0, -1);
            if (self + 0x534) {
                __destroy_arr(self + 0x540, __dt__19soCollisionHitGroupFv, 0x38, 2);
            }
            if (self + 0x438) {
                __destroy_arr(self + 0x444, fn_27_37D3C, 0x78, 2);
            }
            if (self + 0x35C) {
                __destroy_arr(self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 2);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
