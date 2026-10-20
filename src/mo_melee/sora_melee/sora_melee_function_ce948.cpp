#pragma force_active on
extern "C" {
void fn_27_25290(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_CE948(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, fn_27_25290, 0x30, 0x11);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}
