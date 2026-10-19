#pragma force_active on
extern "C" {
void __dt__19soCollisionHitGroupFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_48_AEF4(char* self, int flag) {
    if (self != 0) {
        __destroy_arr(self + 0xc, __dt__19soCollisionHitGroupFv, 0x38, 0x3a);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
