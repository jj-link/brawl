#pragma force_active on
extern "C" void* fn_125_105D8(void* ptr, short count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_125_1057C(void* ptr, short flags) {
    if (ptr != 0) {
        fn_125_105D8(ptr, 0);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
