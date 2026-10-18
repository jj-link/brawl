#pragma force_active on
extern "C" void fn_27_1A3B48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_5034(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_1A3B48(ptr, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
