#pragma force_active on
extern "C" void* fn_27_37D3C(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_57_A5EC(void* p, int n) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
