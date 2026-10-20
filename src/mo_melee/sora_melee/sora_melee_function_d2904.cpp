#pragma force_active on
extern "C" {
typedef void (*PFN_destroy)(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_AB510(void* p, int n);
}

extern "C" void* fn_27_D2904(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (PFN_destroy)fn_27_AB510, 0x10, 3);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
