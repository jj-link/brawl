#pragma force_active on
extern "C" void* fn_124_A140(void*, short);
extern "C" void fn_124_A00C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_A1A0(void* ptr, int flag) {
    if (ptr != 0) {
        fn_124_A140(static_cast<char*>(ptr) + 0x204, -1);
        if (ptr != 0) {
            fn_124_A00C(ptr, 0);
        }
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
