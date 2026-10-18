#pragma force_active on
extern "C" void fn_92_33C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_3364(void* ptr, int flag) {
    if (ptr != 0) {
        fn_92_33C0(ptr, 0);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
