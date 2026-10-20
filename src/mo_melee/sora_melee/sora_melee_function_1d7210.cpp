#pragma force_active on
extern "C" {
void* fn_27_8D588(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_1D7210(void* p, int n) {
    if (p) {
        if (p) {
            __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_8D588, 0xC, 0xA);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
