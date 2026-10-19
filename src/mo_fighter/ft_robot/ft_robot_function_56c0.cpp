#pragma force_active on
extern "C" void fn_27_1988E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_56C0(void* ptr, int size) {
    if (ptr != 0) {
        fn_27_1988E4(ptr, -1);
        if ((short)size > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
