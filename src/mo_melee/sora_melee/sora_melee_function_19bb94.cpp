#pragma force_active on
extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_19BB94(void* self, int del) {
    if (self) {
        __destroy_arr((char*)self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 8);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
