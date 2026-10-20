#pragma force_active on
extern "C" void fn_113_4730(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_2C460(void* ptr, short baseDeleting) {
    if (ptr != 0) {
        fn_113_4730(ptr, 0);
        if (baseDeleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
