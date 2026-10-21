#pragma force_active on
typedef int s32;
typedef short s16;

extern "C" {
void fn_27_26F0D0(void*, int);
void fn_27_262FCC(void*, int);
void fn_27_37D3C(void*, s16);
void __dt__21soCollisionAttackPartFv(void*, s16);
void __dt__27soCollisionAttackModuleImplFv(void*, s16);
void __destroy_arr(void*, void (*)(void*, s16), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_27A354(char* self, s32 flag) {
    if (self) {
        if (self + 0x520) {
            fn_27_26F0D0(self + 0x524, -1);
        }
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x47C, -1);
            if (self + 0x3F4) {
                __destroy_arr(self + 0x400, fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364, __dt__21soCollisionAttackPartFv, 0x90, 1);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
