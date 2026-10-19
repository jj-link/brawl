#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_40_1E2F8(void* obj, int flags);

extern "C" void* fn_40_307C0(void* obj, int flag) {
    if (obj) {
        __destroy_arr((void*)((char*)obj + 0xC), fn_40_1E2F8, 0xA0, 0xD);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
