#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_2E888(void*, int);

extern "C" void* fn_27_CC0F0(void* obj, int del) {
    if (obj) {
        __destroy_arr((char*)obj + 0xC, fn_27_2E888, 0x44, 1);
        if (del > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
