#pragma force_active on
extern "C" void* fn_97_4C84(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_4C28(void* ptr, short baseDeleting) {
    if (ptr != 0) {
        fn_97_4C84(ptr, 0);
        if (baseDeleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
