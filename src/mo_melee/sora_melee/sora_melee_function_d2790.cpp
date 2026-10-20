#pragma force_active on
extern "C" {
void fn_27_8655C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_D2790(void* ptr, int count) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, fn_27_8655C, 0x34, 8);
        if (count > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}
