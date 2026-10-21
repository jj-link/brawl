#pragma force_active on
typedef short s16;

extern "C" {
void* fn_27_37D3C(void*, s16);
void __dt__21soCollisionAttackPartFv(void*, s16);
void __dt__27soCollisionAttackModuleImplFv(void*, s16);
void fn_27_262FCC(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_73_9A74(char* self, int flag) {
    if (self) {
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x50C, -1);
            if (self + 0x484) {
                __destroy_arr(self + 0x490, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364, (void (*)(void*, int))__dt__21soCollisionAttackPartFv, 0x90, 2);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
