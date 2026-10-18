#pragma force_active on
extern "C" void* fn_100_4370(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_12C1C(void* ptr, short count) {
    if (ptr != 0) {
        fn_100_4370(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
