#pragma force_active on
extern "C" {
void* fn_27_2AE00C(void* p, int n);
void __destroy_arr(void* p, void* (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_2AC960(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 8, fn_27_2AE00C, 0xc, 0xc);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
