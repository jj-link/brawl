#pragma force_active on
extern "C" {
void fn_27_46700(void* p, int flags);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_19DF08(void* p, int flags) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_27_46700, 0x60, 0xf);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
