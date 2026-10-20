#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__18soCollisionHitPartFv(void*, int);
}

extern "C" void* fn_27_291CF8(char* self, int del) {
    if (self != 0) {
        __destroy_arr(self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 0x3);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
