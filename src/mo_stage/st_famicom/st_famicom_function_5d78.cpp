#pragma force_active on
typedef unsigned char u8;

extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_68_5D78(void* ptr, int flag)
{
    if (ptr) {
        __destroy_arr(static_cast<u8*>(ptr) + 0x0C,
                      __dt__18soCollisionHitPartFv, 0x68, 1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
