#pragma force_active on
extern "C" {
void* fn_68_5E20(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_68_5E60(void* p, int n) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_68_5E20, 8, 6);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
