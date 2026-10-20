#pragma force_active on
extern "C" void fn_27_25290(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_CF7A0(void* obj, int flag) {
    if (obj) {
        __destroy_arr((char*)obj + 0xC, fn_27_25290, 0x30, 0x1D);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
