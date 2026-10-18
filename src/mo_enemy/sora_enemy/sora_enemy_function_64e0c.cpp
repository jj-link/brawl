#pragma force_active on
extern "C" void fn_41_65698(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_64E0C(void* ptr, int count) {
    if (ptr != 0) {
        fn_41_65698(static_cast<char*>(ptr) + 8, -1);
        if (static_cast<short>(count) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
