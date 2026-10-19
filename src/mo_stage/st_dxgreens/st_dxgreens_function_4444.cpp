#pragma force_active on
typedef signed int s32;

extern "C" void* fn_27_37D3C(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_79_4444(void* p, s32 n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 0x1e);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
