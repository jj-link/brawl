#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_84318(void* ptr, int size);

extern "C" void* fn_27_DB1DC(void* ptr, int size) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, fn_27_84318, 0xc, 1);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
