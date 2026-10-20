#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_9FA50(void*, int);
}

extern "C" void* fn_27_CBF58(void* p, int del) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_9FA50, 0x2C, 1);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
