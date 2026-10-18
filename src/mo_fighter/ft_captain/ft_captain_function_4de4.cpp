#pragma force_active on
extern "C" void fn_100_3AA8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_4DE4(void* ptr, short destroy) {
    if (ptr != 0) {
        fn_100_3AA8(static_cast<char*>(ptr) + 0x1C0, -1);
        if (destroy > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
