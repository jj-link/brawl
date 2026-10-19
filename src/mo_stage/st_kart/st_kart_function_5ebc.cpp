#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* fn_49_69C8(void* p, int n);

extern "C" void* fn_49_5EBC(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_49_69C8, 0xa0, 1);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
