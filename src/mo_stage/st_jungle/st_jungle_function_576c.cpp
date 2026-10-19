#pragma force_active on
extern "C" void* fn_51_6278(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_51_576C(void* p, int n) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_51_6278, 0xa0, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
