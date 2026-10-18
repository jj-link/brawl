#pragma force_active on
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_15510(void* ptr, short deleting) {
    if (ptr != 0) {
        fn_27_1A2D10(ptr, -1);
        if (deleting > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
