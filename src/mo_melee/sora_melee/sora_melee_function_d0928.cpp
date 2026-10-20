#pragma force_active on
extern "C" void fn_27_25290(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_D0928(void* object, int flag) {
    if (object) {
        __destroy_arr((char*)object + 0xC, fn_27_25290, 0x30, 0x2C);
        if (flag > 0)
            __dl__FPv(object);
    }
    return object;
}
