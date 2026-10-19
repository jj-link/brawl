#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__18soCollisionHitPartFv(void*, int);

void* fn_54_59B8(char* self, int del) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 2);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
