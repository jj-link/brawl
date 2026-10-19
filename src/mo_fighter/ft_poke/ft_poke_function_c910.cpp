#pragma force_active on
extern "C" void fn_116_3844(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_C910(void* ptr, short flag) {
    if (ptr != 0) {
        fn_116_3844(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
