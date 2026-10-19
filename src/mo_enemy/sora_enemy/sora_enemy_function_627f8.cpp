#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_6278C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_627F8(void* ptr, int flags) {
    if (ptr != 0) {
        fn_41_62CC4(static_cast<char*>(ptr) + 0x1b8, -1);
        fn_41_6278C(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(flags) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
