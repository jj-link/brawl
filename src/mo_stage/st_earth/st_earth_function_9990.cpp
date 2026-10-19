#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_66_9950(void*, int);
}

extern "C" void* fn_66_9990(void* ptr, int size) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, fn_66_9950, 8, 7);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
