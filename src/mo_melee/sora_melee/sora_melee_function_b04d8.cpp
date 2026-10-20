#pragma force_active on
extern "C" void fn_27_50588(void* ptr, int destroy);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" {
void* fn_27_B04D8(void* ptr, int destroy) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, fn_27_50588, 8, 8);
        if (destroy > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
