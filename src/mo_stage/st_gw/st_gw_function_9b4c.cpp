#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18soCollisionHitPartFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_63_9B4C(void* self, int flag) {
    if (self != 0) {
        __destroy_arr((char*)self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 4);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
