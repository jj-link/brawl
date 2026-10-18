#pragma force_active on
extern "C" void fn_27_198A7C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_6948(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_198A7C(ptr, -1);
        if (static_cast<short>(flag) > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
