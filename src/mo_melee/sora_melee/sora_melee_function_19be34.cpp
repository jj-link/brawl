#pragma force_active on
extern "C" void fn_27_85800();
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_19BE34(void* p, int flags) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_85800, 0x14, 1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
