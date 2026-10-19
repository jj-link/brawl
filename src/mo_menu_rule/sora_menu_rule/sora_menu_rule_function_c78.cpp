#pragma force_active on
extern "C" {
void fn_18_CE0(void* p, int n);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_18_C78(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0x48, fn_18_CE0, 0xa8, 9);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
