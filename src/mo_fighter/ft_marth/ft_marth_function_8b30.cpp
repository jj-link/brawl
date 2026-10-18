#pragma force_active on
extern "C" void fn_106_815C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_8B30(void* ptr, short flag) {
    if (ptr != 0) {
        if (ptr != 0) {
            fn_106_815C(ptr, 0);
        }
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
