#pragma force_active on
extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_6C3C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_66114(ptr, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
