#pragma force_active on
typedef unsigned char u8;

extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void*);
void* fn_27_37D3C(void* p, int n);
}

extern "C" void* fn_48_B2FC(void* p, int n) {
    if (p != 0) {
        __destroy_arr((u8*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 0x13);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
