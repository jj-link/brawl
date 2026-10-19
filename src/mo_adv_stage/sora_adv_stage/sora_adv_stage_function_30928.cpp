#pragma force_active on
typedef int s32;

extern "C" void* fn_27_37D3C(void* p, s32 n);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_40_30928(void* p, s32 n) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 0xd);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
