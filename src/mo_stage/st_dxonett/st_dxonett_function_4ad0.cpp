#pragma force_active on

extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_37D3C(void*, int);
void* __dt__21soCollisionAttackPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_262FCC(void*, int);
void __dl__FPv(void*);

void* fn_78_4AD0(void* self, int flag) {
    if (self) {
        char* object = (char*)self;
        if (object + 0x358) {
            __dt__27soCollisionAttackModuleImplFv(object + 0x47C, -1);
            if (object + 0x3F4) {
                __destroy_arr(object + 0x400, (void (*)(void*, int))fn_27_37D3C, 0x78UL, 1UL);
            }
            if (object + 0x358) {
                __destroy_arr(object + 0x364, (void (*)(void*, int))__dt__21soCollisionAttackPartFv, 0x90UL, 1UL);
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
