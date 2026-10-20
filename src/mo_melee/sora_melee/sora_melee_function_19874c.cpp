#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_9FB88(void* ptr, int size);
}

extern "C" void* fn_27_19874C(void* ptr, int size) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, fn_27_9FB88, 0xC, 1);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
