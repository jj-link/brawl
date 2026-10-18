#pragma force_active on
extern "C" void* fn_115_113BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_11360(void* ptr, int count) {
    if (ptr != 0) {
        fn_115_113BC(ptr, 0);
        if ((short)count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
