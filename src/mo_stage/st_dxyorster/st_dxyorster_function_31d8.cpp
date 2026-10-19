#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__19soCollisionHitGroupFv(void*, int);

void* fn_76_31D8(void* self, int flag) {
    if (self != 0) {
        __destroy_arr((char*)self + 0xC, __dt__19soCollisionHitGroupFv, 0x38, 9);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
