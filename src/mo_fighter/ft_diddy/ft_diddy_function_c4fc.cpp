#pragma force_active on
extern "C" void* fn_115_A230(void* ptr, short flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_115_C4FC(void* ptr, short baseDeleting) {
    if (ptr != 0) {
        fn_115_A230(ptr, 0);
        if (baseDeleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
