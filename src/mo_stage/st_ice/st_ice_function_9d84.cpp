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
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_62_9D84(void* self, int flags) {
    if (self) {
        if ((char*)self + 0x500) {
            fn_27_26F0D0((char*)self + 0x5AC, -1);
            if ((char*)self + 0x500 && (char*)self + 0x500) {
                __destroy_arr((char*)self + 0x50C, fn_62_A404, 0xA0, 1);
            }
        }
        if ((char*)self + 0x35C) {
            __dt__24soCollisionHitModuleImplFv((char*)self + 0x498, -1);
            if ((char*)self + 0x454) {
                __destroy_arr((char*)self + 0x460, __dt__19soCollisionHitGroupFv, 0x38, 1);
            }
            if ((char*)self + 0x3D0) {
                __destroy_arr((char*)self + 0x3DC, fn_27_37D3C, 0x78, 1);
            }
            if ((char*)self + 0x35C) {
                __destroy_arr((char*)self + 0x368, __dt__18soCollisionHitPartFv, 0x68, 1);
            }
        }
        fn_27_262FCC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
