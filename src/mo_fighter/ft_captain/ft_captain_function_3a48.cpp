#pragma force_active on
extern "C" void fn_100_3AA8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_3A48(void* ptr, int flag) {
    if (ptr != 0) {
        fn_100_3AA8(static_cast<char*>(ptr) + 0x38, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
