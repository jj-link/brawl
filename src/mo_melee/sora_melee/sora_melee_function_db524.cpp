#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* fn_27_84558(void* ptr, int count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_DB524(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_27_84558, 0xc, 1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
