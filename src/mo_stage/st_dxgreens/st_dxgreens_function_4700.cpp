#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_79_46C0(void* p, int n);
}

extern "C" void* fn_79_4700(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_79_46C0, 8, 7);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
