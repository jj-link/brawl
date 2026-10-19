#pragma force_active on
extern "C" {
void __dt__19soCollisionHitGroupFv(void* thisPtr, int flag);
void __destroy_arr(void* ptr, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
void __dl__FPv(void* ptr);
}

extern "C" void* fn_62_9EF4(char* self, int flag)
{
    if (self != 0) {
        __destroy_arr(self + 0xc, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
