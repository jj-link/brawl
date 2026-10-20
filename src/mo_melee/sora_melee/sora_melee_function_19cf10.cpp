#pragma force_active on
extern "C" {
void __dt__21soCollisionAttackPartFv(void* p, int flags);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_19CF10(char* self, int flags) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 4);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
