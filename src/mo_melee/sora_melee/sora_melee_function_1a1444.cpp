#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__25soCollisionAttackAbsoluteFv(void);
}

extern "C" void* fn_27_1A1444(char* self, int del) {
    if (self) {
        __destroy_arr(self + 0xC, (void (*)(void*, int))__dt__25soCollisionAttackAbsoluteFv, 0x68, 6);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
