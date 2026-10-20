#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_25290();

extern "C" void* fn_27_CEAE0(void* p, int del) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_25290, 0x30, 0x13);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
