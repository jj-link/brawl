#pragma force_active on
extern "C" void* fn_108_4570(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_105B4(void* ptr, int flag) {
    if (ptr != 0) {
        fn_108_4570(ptr, 0);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
