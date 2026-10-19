#pragma force_active on
extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_48_AFC4(void* ptr, int deleteFlag) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xC, __dt__18soCollisionHitPartFv, 0x68, 0x3A);
        if (deleteFlag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
