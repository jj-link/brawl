#pragma force_active on
extern "C" void fn_27_19C818(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_6890(void* ptr, int count) {
    if (ptr != 0) {
        fn_27_19C818(ptr, -1);
        if ((short)count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
