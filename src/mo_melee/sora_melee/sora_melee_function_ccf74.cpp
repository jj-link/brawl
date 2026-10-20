#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dt__21soCollisionAttackPartFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_CCF74(char* self, int flags) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 3);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
