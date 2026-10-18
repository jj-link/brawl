#pragma force_active on
extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_1F64(void* ptr, int count) {
    if (ptr != 0) {
        fn_27_7700(ptr, 0);
        if ((short)count > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
