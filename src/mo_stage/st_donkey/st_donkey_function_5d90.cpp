#pragma force_active on
extern "C" {
void fn_50_5D50(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_50_5D90(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_50_5D50, 8, 7);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
