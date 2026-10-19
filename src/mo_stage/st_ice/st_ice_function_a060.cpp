#pragma force_active on

extern "C" {
    void __dl__FPv(void*);
    void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
    void* fn_62_5724(void* ptr, int count);
    void* fn_62_A060(void* ptr, int count) {
        if (ptr != 0) {
            __destroy_arr((void*)((char*)ptr + 0xC), (void (*)(void*, int))fn_62_5724, (unsigned long)8, (unsigned long)6);
            if (count > 0) {
                __dl__FPv(ptr);
            }
        }
        return ptr;
    }
}
