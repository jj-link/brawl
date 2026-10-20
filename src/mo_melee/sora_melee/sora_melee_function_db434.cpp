#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_845D8(void* ptr, int count);
}

extern "C" void* fn_27_DB434(void* ptr, int flags) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, (void (*)(void*, int))fn_27_845D8, 0xC, 5);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
