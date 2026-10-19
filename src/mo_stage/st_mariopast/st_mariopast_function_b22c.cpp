#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_48_3E50(void* ptr, int size);
}

extern "C" void* fn_48_B22C(void* ptr, int size) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_48_3E50, 0xa0, 0x13);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
