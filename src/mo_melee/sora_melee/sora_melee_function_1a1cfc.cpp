#pragma force_active on
extern "C" {
void fn_27_AB510(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_1A1CFC(void* p, int flags) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_AB510, 0x10, 0x19);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
