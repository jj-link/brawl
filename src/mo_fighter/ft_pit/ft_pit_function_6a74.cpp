#pragma force_active on
extern "C" void fn_27_69684(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_6A74(void* ptr, short val) {
    if (ptr != 0) {
        fn_27_69684(ptr, -1);
        if (val > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
