#pragma force_active on
extern "C" void* fn_95_3864(void*, short);

extern "C" void* fn_95_D360(void* ptr, short baseDeleting) {
    if (ptr != 0) {
        fn_95_3864(ptr, 0);
        if (baseDeleting > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
