#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dt__18soCollisionHitPartFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_72_43D8(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
