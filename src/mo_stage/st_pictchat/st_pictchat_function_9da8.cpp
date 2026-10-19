#pragma force_active on
extern "C" {
void __dt__21soCollisionAttackPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_73_9DA8(void* self, int flags)
{
    if (self) {
        __destroy_arr((char*)self + 0xC, __dt__21soCollisionAttackPartFv, 0x90, 5);
        if (flags > 0)
            __dl__FPv(self);
    }
    return self;
}
