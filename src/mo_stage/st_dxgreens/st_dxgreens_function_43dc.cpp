#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__19soCollisionHitGroupFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_79_43DC(char* self, int del) {
    if (self) {
        __destroy_arr(self + 0xC, __dt__19soCollisionHitGroupFv, 0x38, 0x1E);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
