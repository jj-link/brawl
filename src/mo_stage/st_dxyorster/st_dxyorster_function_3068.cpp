#pragma force_active on

extern "C" {
void* fn_27_26F0D0(void*, int);
void fn_76_3CA0(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__24soCollisionHitModuleImplFv(void*, short);
void __dt__19soCollisionHitGroupFv(void*, int);
void fn_27_37D3C(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_76_3068(char* self, int flags) {
    if (self) {
        if (self + 0xDC0) {
            fn_27_26F0D0(self + 0x136C, -1);
            if (self + 0xDC0 && self + 0xDC0) {
                __destroy_arr(self + 0xDCC, fn_76_3CA0, 0xA0, 9);
            }
        }
        if (self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv(self + 0xD58, -1);
            if (self + 0xB54) {
                __destroy_arr(self + 0xB60, __dt__19soCollisionHitGroupFv, 0x38, 9);
            }
            if (self + 0x710) {
                __destroy_arr(self + 0x71C, fn_27_37D3C, 0x78, 9);
            }
            if (self + 0x35C) {
                __destroy_arr(self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 9);
            }
        }
        fn_27_262FCC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
