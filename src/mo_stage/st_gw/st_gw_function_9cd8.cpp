#pragma force_active on
extern "C" {
void __dt__21soCollisionAttackPartFv(void* p, int flags);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_63_9CD8(char* self, int flags) {
    if (self != 0) {
        __destroy_arr(self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 5);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
