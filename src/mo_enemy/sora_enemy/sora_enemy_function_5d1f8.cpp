#pragma force_active on
extern "C" void fn_41_5D18C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5D1F8(void* ptr, int count) {
    if (ptr != 0) {
        fn_41_5D18C(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(count) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
