#pragma force_active on
extern "C" void fn_27_46700(void* p, int flag);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_19DA78(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_46700, 0x60, 0xD);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
