#pragma force_active on
extern "C" void* fn_27_C86F0(void* p, int size);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_C7A94(void* p, int flag) {
    if (p != 0) {
        __destroy_arr((char*)p + 0x8, (void (*)(void*, int))fn_27_C86F0, 0x14, 0xa);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
