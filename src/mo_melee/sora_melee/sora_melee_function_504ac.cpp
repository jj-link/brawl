#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_505E0(void* ptr, int count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_504AC(void* ptr, int del) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, fn_27_505E0, 0xc, 0xff);
        if (del > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
