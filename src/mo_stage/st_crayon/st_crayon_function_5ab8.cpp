#pragma force_active on
extern "C" {
void fn_56_5A10(void* p, int flags);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_56_5AB8(void* p, int flags) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xC, fn_56_5A10, 8, 6);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
