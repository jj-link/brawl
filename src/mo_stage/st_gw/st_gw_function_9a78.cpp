#pragma force_active on
extern "C" {
void __destroy_arr(void* ptr, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
void __dl__FPv(void* ptr);
void __dt__19soCollisionHitGroupFv(void* thisPtr, int flag);
void* fn_63_9A78(void* self, int flags);
}

void* fn_63_9A78(void* self, int flags) {
    if (self) {
        __destroy_arr((char*)self + 0xC, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
