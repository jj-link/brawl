#pragma force_active on
extern "C" void fn_27_37D3C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_47_40BC(char* p, int n) {
    if (p) {
        __destroy_arr(p + 0xc, fn_27_37D3C, 0x78, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
