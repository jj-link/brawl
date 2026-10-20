#pragma force_active on
extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_19AB9C(void* self, int doDelete);
}

extern "C" void* fn_27_19AB9C(void* self, int doDelete) {
    if (self) {
        __destroy_arr((char*)self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 1);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
