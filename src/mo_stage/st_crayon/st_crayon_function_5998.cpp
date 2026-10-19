#pragma force_active on
typedef unsigned long u32;

extern "C" void __destroy_arr(void*, void (*)(void*, int), u32, u32);
extern "C" void* fn_27_37D3C(void* p, int n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_56_5998(char* p, int n) {
    if (p != 0) {
        __destroy_arr(p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
