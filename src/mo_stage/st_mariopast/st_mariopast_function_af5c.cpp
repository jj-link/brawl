#pragma force_active on
extern "C" void* fn_27_37D3C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_48_AF5C(void* p, int release) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 0x3a);
        if (release > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
