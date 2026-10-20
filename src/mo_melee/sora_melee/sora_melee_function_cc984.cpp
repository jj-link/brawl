#pragma force_active on
typedef unsigned long u32;

extern "C" {
void __dt__19soCollisionHitGroupFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), u32, u32);
void __dl__FPv(void*);
}

extern "C" void* fn_27_CC984(char* self, int flag) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
