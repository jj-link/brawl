#pragma force_active on
extern "C" void* fn_108_4C80(void* ptr, short flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_108_D270(void* ptr, short flag) {
    if (ptr != 0) {
        fn_108_4C80(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
