#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_57_A788(void* ptr, int flag);
}

extern "C" void* fn_57_A7C8(void* ptr, int flag)
{
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0x0C, (void (*)(void*, int))fn_57_A788, 8, 7);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
