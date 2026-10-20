#pragma force_active on
extern "C" void fn_27_4AD20(void* p, int flag);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_19C214(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_27_4AD20, 0x5c, 1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
