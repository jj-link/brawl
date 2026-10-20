#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_AB510(void*, int);

extern "C" void* fn_27_1A1FE4(void* object, short shouldDelete) {
    if (object) {
        __destroy_arr((char*)object + 0xC, fn_27_AB510, 0x10, 0x8);
        if (shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}
