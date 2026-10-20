#pragma force_active on
typedef unsigned char u8;

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18soCollisionHitPartFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_CC654(void* ptr, int del) {
    if (ptr) {
        __destroy_arr((u8*)ptr + 0xc, __dt__18soCollisionHitPartFv, 0x68, 2);
        if (del > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
