#pragma force_active on
extern "C" void fn_100_AAEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_AB4C(void* ptr, int freeFlag) {
    if (ptr != 0) {
        fn_100_AAEC(static_cast<char*>(ptr) + 8, -1);
        if (static_cast<short>(freeFlag) > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
