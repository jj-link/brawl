#pragma force_active on
extern "C" void fn_27_25290(void* ptr, int count);
extern "C" void __destroy_arr(void* ptr, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_27_D0DF0(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC, fn_27_25290, 0x30, 0x3D);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
