#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_25290(void*, int);
}

extern "C" void* fn_27_CF608(void* p, int flag) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xC, fn_27_25290, 0x30, 0x1c);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
