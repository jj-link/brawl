#pragma force_active on
extern "C" void fn_27_A7E40(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_277CC(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_A7E40(ptr, 0);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
