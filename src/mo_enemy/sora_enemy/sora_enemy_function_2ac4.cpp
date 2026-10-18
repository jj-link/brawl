#pragma force_active on
extern "C" void fn_41_2A84(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2AC4(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_2A84(static_cast<char*>(ptr) + 12, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
