#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_84098(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_C4628(void* ptr, int size) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, fn_27_84098, 12, 1);
        if (size > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
