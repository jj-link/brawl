#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_48_3E50(void*, int);
}

extern "C" void* fn_48_ACBC(void* ptr, int doFree) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, fn_48_3E50, 0xa0, 0xcd);
        if (doFree > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
