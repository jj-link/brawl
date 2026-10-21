#pragma force_active on

typedef unsigned long size_t;

extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_37D3C(void*, int);
void* __dt__21soCollisionAttackPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), size_t, size_t);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);

void* fn_57_A4C4(char* self, int flag) {
    if (self) {
        if (self + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(self + 0x50C, -1);
            if (self + 0x484) {
                __destroy_arr(self + 0x490,
                    (void (*)(void*, int))fn_27_37D3C,
                    (size_t)0x78, (size_t)1);
            }
            if (self + 0x358) {
                __destroy_arr(self + 0x364,
                    (void (*)(void*, int))__dt__21soCollisionAttackPartFv,
                    (size_t)0x90, (size_t)2);
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
