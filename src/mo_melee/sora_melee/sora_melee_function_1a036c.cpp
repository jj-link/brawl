#pragma force_active on
extern "C" void* fn_27_1A032C(void* ptr, int count);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_1A036C(void* ptr, int count) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_27_1A032C, 0x10, 0x24);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
