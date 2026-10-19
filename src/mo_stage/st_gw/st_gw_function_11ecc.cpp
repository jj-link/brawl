#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__18soCollisionHitPartFv(void*, int);
}

extern "C" void* fn_63_11ECC(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, __dt__18soCollisionHitPartFv, 0x68, 1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
