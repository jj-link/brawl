#pragma force_active on
extern "C" void* fn_123_396C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_3910(void* ptr, short flag) {
    if (ptr != 0) {
        fn_123_396C(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
