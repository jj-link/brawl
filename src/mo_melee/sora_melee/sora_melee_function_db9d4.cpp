#pragma force_active on
extern "C" void* fn_27_84298(void* ptr, int size);
extern "C" void __destroy_arr(void* ptr, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_27_DB9D4(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_27_84298, 0xc, 1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
