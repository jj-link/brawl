#pragma force_active on
extern "C" void fn_27_46B20(void* ptr, int size);
extern "C" void __destroy_arr(void* arr, void (*fn)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_27_CDDE8(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, fn_27_46B20, 0xb8, 1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
