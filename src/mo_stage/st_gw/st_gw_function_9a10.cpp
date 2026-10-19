#pragma force_active on
extern "C" void* fn_63_ABDC(void* ptr, int size);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_63_9A10(void* ptr, int size) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_63_ABDC, 0xa0, 1);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
