#pragma force_active on
extern "C" void* fn_66_A0EC(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_66_95E0(char* ptr, int count) {
    if (ptr != 0) {
        __destroy_arr(ptr + 0xc, (void (*)(void*, int))fn_66_A0EC, 0xa0, 1);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
