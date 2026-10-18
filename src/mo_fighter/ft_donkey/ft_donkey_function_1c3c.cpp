#pragma force_active on
extern "C" void fn_92_1B7C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_1C3C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_92_1B7C(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
