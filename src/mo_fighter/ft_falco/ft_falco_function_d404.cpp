#pragma force_active on
extern "C" void* fn_108_4C80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_D404(void* ptr, short deleting) {
    if (ptr != 0) {
        fn_108_4C80(ptr, 0);
        if (deleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
