#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_37D3C(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* __dt__21soCollisionAttackPartFv(void*, short);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);

void* fn_73_9B5C(char* self, int flag) {
    if (self) {
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x74C, -1);
            if (self + 0x6C4) {
                __destroy_arr(self + 0x6D0, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364, (void (*)(void*, int))__dt__21soCollisionAttackPartFv, 0x90, 6);
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
