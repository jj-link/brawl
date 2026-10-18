#pragma force_active on
extern "C" void fn_97_1B88(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_1D00(void* ptr, short flag) {
    if (ptr != 0) {
        fn_97_1B88(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
