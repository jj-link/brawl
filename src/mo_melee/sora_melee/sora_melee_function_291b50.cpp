#pragma force_active on
extern "C" void __dt__19soCollisionHitGroupFv(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_291B50(char* self, int flag) {
    if (self) {
        __destroy_arr(self + 0xc, __dt__19soCollisionHitGroupFv, 0x38, 3);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
