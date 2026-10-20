#pragma force_active on
typedef signed int s32;

extern "C" void __destroy_arr(void*, void (*)(void*), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_C940C(void*);

extern "C" void* fn_27_1A262C(void* ptr, s32 flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 12, fn_27_C940C, 16, 6);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
