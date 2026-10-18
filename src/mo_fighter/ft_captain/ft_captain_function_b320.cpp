#pragma force_active on
extern "C" void* fn_100_B2C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_B320(void* ptr, int count) {
    if (ptr != 0) {
        fn_100_B2C0(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(count) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
