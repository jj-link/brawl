#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);
void* fn_73_9D10(void* self, int flags);
}

extern "C" void* fn_73_9D10(void* self, int flags) {
    if (self != 0) {
        __destroy_arr((char*)self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 4);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
