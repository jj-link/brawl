#pragma force_active on
extern "C" void fn_115_1B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1AAC(void* ptr, int flag) {
    if (ptr != 0) {
        fn_115_1B08(ptr, 0);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
