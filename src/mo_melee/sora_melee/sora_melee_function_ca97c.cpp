#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_A6978(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_CA97C(void* p, int del) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_27_A6978, 0x24, 0xf);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
