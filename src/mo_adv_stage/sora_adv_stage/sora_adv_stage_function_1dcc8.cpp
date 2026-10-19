#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), int, int);
extern "C" void __dl__FPv(void*);
extern "C" void fn_40_1E2F8(void*, int);

extern "C" void* fn_40_1DCC8(void* object, int flag) {
    if (object != 0) {
        __destroy_arr((char*)object + 0xC, fn_40_1E2F8, 0xA0, 0x18);
        if (flag > 0)
            __dl__FPv(object);
    }
    return object;
}
