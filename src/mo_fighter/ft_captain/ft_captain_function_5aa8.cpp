#pragma force_active on
extern "C" void fn_100_3AA8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_5AA8(void* ptr, short flag) {
    if (ptr != 0) {
        fn_100_3AA8(static_cast<char*>(ptr) + 0x88, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
