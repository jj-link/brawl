#pragma force_active on
extern "C" {
void fn_27_25290();
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_D1450(char* ptr, int flag) {
    if (ptr) {
        __destroy_arr(ptr + 0xc, (void (*)(void*, int))fn_27_25290, 0x30, 9);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
