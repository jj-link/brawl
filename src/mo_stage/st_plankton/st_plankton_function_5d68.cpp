#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__19soCollisionHitGroupFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_74_5D68(char* self, int flag) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
