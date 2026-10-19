#pragma force_active on
extern "C" {
void* fn_49_622C(void* ptr, int release);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_49_626C(void* ptr, int release) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, (void (*)(void*, int))fn_49_622C, 8, 7);
        if (release > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
