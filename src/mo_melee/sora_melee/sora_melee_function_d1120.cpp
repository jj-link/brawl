#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_25290(void* ptr, int count);
void* fn_27_D1120(void* ptr, int flag);
}

extern "C" void* fn_27_D1120(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 0x41);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
