#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_37D3C(void*, int);

extern "C" void* fn_51_D6BC(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0x0c, (void (*)(void*, int))fn_27_37D3C, 0x78, 2);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
