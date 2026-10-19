#pragma force_active on
extern "C" {
void __dt__19soCollisionHitGroupFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_51_57D4(void* ptr, int flag)
{
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
