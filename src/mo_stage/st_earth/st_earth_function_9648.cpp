#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__19soCollisionHitGroupFv(void*, int);
}

extern "C" void* fn_66_9648(void* self, int flag) {
    if (self != 0) {
        __destroy_arr((char*)self + 0xc, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
