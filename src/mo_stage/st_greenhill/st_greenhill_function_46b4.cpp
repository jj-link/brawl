#pragma force_active on
extern "C" void* fn_72_460C(void* ptr, int size);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_72_46B4(void* ptr, int size) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_72_460C, 8, 6);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
