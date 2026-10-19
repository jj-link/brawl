#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_74_6830(void* p, int n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_74_5D00(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_74_6830, 0xa0, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
