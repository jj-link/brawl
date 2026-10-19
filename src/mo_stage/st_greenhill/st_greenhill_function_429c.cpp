#pragma force_active on
extern "C" void* fn_72_4DA8(void* p, int flag);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_72_429C(void* p, int flag) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_72_4DA8, 0xa0, 1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
