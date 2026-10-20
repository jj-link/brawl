#pragma force_active on
extern "C" void* fn_27_84218(void* p, int n);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_DB3BC(void* p, int n) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_84218, 0xC, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
