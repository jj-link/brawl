#pragma force_active on
extern "C" void fn_27_25290();
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_CEFA8(void* ptr, int flag) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 0x18);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
