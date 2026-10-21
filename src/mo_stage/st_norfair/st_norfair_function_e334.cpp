#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void fn_27_37D3C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);

void* fn_54_E334(char* self, int flag) {
    if (self) {
        if ((unsigned long)(self + 0x358) != 0) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x6BC, -1);
            if ((unsigned long)(self + 0x634) != 0) {
                __destroy_arr(self + 0x640, fn_27_37D3C, 0x78, 1);
            }
            if ((unsigned long)(self + 0x358) != 0) {
                __destroy_arr(self + 0x364, __dt__21soCollisionAttackPartFv, 0x90, 5);
            }
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
