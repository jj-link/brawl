#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_801CFB14(void*, int);

extern "C" void* fn_801CFAB0(void* object, int flag) {
    if (object != 0) {
        __destroy_arr(object, fn_801CFB14, 0xC, 3);
        if (flag > 0)
            __dl__FPv(object);
    }
    return object;
}
