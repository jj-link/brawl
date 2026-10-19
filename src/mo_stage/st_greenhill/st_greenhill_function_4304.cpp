#pragma force_active on
typedef void (*Dtor)(void*, int);

extern "C" void __dt__19soCollisionHitGroupFv(void*, int);
extern "C" void __destroy_arr(void*, Dtor, unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_72_4304(void* ptr, int flag)
{
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xC, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
