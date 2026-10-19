#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void* fn_27_37D3C(void* p, s32 n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_48_B12C(void* p, s32 n) {
    if (p) {
        __destroy_arr((u8*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 0x19);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
