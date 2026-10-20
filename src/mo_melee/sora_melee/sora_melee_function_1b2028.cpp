#pragma force_active on
extern "C" void* fn_27_840D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1B2028(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC,
                      (void (*)(void*, int))fn_27_840D8, 0xC, 7);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
