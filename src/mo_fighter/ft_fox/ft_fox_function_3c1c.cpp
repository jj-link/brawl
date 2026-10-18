#pragma force_active on
extern "C" void* fn_97_3C78(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_97_3C1C(void* ptr, short count) {
    if (ptr != 0) {
        fn_97_3C78(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
