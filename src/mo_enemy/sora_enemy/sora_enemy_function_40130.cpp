#pragma force_active on
extern "C" void fn_41_40224(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_40130(void* ptr, int count) {
    if (ptr != 0) {
        fn_41_40224(static_cast<char*>(ptr) + 8, -1);
        if (static_cast<short>(count) > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
