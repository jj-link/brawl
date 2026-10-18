#pragma force_active on
extern "C" void fn_41_53118(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_52EE0(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_41_53118(static_cast<char*>(ptr) + 8, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
