#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);

void* fn_51_5A34(char* self, int flags) {
    if (self != 0) {
        __destroy_arr(self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
