#pragma force_active on
extern "C" {
void fn_27_50588(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_C52A4(void* ptr, int destroy) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, fn_27_50588, 8, 1);
        if (destroy > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
