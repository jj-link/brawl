#pragma opt_common_subs off
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

extern "C" void* fn_48_ABB4(void* self, int flag) {
    if (self) {
        if ((char*)self + 0x18B0) {
            fn_27_26F0D0((char*)self + 0x249C, -1);
            if ((char*)self + 0x18B0 && (char*)self + 0x18B0) {
                __destroy_arr((char*)self + 0x18BC, fn_48_3E50, 0xA0, 0x13);
            }
        }
        if ((char*)self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv((char*)self + 0x1848, -1);
            if ((char*)self + 0x1414) {
                __destroy_arr((char*)self + 0x1420, __dt__19soCollisionHitGroupFv, 0x38, 0x13);
            }
            if ((char*)self + 0xB20) {
                __destroy_arr((char*)self + 0xB2C, fn_27_37D3C, 0x78, 0x13);
            }
            if ((char*)self + 0x35C) {
                __destroy_arr((char*)self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 0x13);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
