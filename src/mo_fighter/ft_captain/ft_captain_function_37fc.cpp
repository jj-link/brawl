#pragma force_active on
extern "C" void* fn_100_3858(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_37FC(void* ptr, int count) {
    if (ptr) {
        fn_100_3858(ptr, 0);
        if ((short)count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
