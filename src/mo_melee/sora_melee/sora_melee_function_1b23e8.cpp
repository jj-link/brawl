#pragma force_active on
extern "C" void* fn_27_84198(void* p, int n);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);

extern "C" void* fn_27_1B23E8(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_84198, 0xC, 5);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
