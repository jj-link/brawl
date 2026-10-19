#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);

void* fn_61_E6A0(void* self, int flags) {
    if (self) {
        __destroy_arr((char*)self + 0xC, __dt__21soCollisionAttackPartFv, 0x90, 2);
        if (flags > 0)
            __dl__FPv(self);
    }
    return self;
}
}
