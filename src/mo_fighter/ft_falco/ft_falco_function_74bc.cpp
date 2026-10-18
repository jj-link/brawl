#pragma force_active on
extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_74BC(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_27_66114(ptr, static_cast<short>(-1));
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
