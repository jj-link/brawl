#pragma force_active on
extern "C" void __dl__FPv(void* p);
extern "C" void __destroy_arr(void* arr, void (*fn)(void*, int), unsigned long elem, unsigned long count);
extern "C" void* fn_27_84218(void*, int);

extern "C" void* fn_27_DB344(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_84218, 0xc, 2);
        if (n > 0)
            __dl__FPv(p);
    }
    return p;
}
