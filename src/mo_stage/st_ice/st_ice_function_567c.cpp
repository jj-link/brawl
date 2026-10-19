#pragma force_active on
extern "C" void __dt__21soCollisionAttackPartFv(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_62_567C(void* self, int flags)
{
    if (self != 0) {
        __destroy_arr((char*)self + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 2);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
