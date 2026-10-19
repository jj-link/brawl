#pragma force_active on
extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_48_B364(char* self, int del) {
    if (self != 0) {
        __destroy_arr(self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 0x13);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
