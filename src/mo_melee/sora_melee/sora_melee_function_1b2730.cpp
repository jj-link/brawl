#pragma force_active on
extern "C" void* fn_27_84358(void*, int);
extern "C" void __destroy_arr(void*, void* (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1B2730(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_84358, 0xC, 4);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
