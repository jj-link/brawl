#pragma force_active on
typedef signed int s32;

extern "C" {
void* fn_27_37D3C(void* p, s32 n);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_3956B4(void* p, s32 n) {
    if (p) {
        __destroy_arr((unsigned char*)p + 0x0c, (void (*)(void*, int))fn_27_37D3C, 0x78, 7);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
