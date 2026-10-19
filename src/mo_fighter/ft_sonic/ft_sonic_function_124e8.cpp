#pragma force_active on
extern "C" void* fn_123_396C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_124E8(void* ptr, short baseDeleting) {
    if (ptr != 0) {
        fn_123_396C(ptr, 0);
        if (baseDeleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
