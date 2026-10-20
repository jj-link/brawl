#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_C940C(void*, int);

extern "C" void* fn_27_1A2524(void* object, int shouldDelete) {
    if (object) {
        __destroy_arr((char*)object + 0xC, (void (*)(void*, int))fn_27_C940C, 16, 11);
        if (shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}
