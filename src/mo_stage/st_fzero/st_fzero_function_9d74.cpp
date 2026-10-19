#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* fn_61_9D34(void* ptr, int flag);
void __dl__FPv(void*);
}

extern "C" void* fn_61_9D74(void* ptr, int flag) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_61_9D34, 8, 7);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
