#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_8D588(void*, int);

extern "C" void* fn_27_1D7D98(void* p, int flags) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_27_8D588, 0xc, 0xa);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
