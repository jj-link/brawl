#pragma force_active on
extern "C" void fn_27_69684(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_6B84(void* ptr, short count) {
    if (ptr != 0) {
        fn_27_69684(ptr, static_cast<short>(-1));
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
