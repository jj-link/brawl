#pragma force_active on
extern "C" {
void fn_18_CE0(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_18_48E8(void* p, int flags) {
    if (p) {
        if (p) {
            __destroy_arr((char*)p + 0x48, fn_18_CE0, 0xa8, 9);
        }
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
