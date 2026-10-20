#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_50588(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_DB174(void* p, int del) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_27_50588, 8, 0x13);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
