#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_78_4D94(void* ptr, int count);
extern "C" void __destroy_arr(void* ptr, void* (*fn)(void*, int), unsigned long size, unsigned long count);

extern "C" void* fn_78_4DD4(void* ptr, int count) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, fn_78_4D94, 8, 7);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
