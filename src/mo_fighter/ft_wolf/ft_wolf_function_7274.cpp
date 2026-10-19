#pragma force_active on
extern "C" void* fn_27_5B39C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_7274(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_5B39C(ptr, static_cast<short>(-1));
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
