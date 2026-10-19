#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__19soCollisionHitGroupFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_48_B0C4(void* ptr, int flag) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xC, __dt__19soCollisionHitGroupFv, 0x38, 0x19);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
