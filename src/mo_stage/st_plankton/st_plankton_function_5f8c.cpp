#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_74_5F4C(void* ptr, int size);
}

extern "C" void* fn_74_5F8C(void* ptr, int count) {
    if (ptr != 0) {
        __destroy_arr((void*)((char*)ptr + 0xc), (void (*)(void*, int))fn_74_5F4C, 8, 6);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
