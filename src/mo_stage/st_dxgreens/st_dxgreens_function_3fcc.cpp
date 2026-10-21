#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* __dt__21soCollisionAttackPartFv(void*, short);
void fn_27_262FCC(void*, int);
void* fn_27_37D3C(void*, short);
void __dl__FPv(void*);

extern "C" void* fn_79_3FCC(char* self, int flag) {
    if (self) {
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x14CC, -1);
            if (self + 0x1444) {
                __destroy_arr(self + 0x1450, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364, (void (*)(void*, int))__dt__21soCollisionAttackPartFv, 0x90, 0x1E);
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
