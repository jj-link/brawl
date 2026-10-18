#pragma force_active on
extern "C" void fn_108_60D8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_10B34(void* ptr, short count) {
    if (ptr != 0) {
        fn_108_60D8(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
