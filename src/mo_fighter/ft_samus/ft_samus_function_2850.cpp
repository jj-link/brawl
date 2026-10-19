#pragma force_active on
extern "C" void* fn_27_1A67F8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_2850(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_1A67F8(ptr, (short)-1);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
