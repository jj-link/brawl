#pragma force_active on
extern "C" void fn_27_841D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1B2550(void* object, int flag) {
    if (object) {
        __destroy_arr((char*)object + 0xC, fn_27_841D8, 0xC, 1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
