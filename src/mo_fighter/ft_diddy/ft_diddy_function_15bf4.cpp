#pragma force_active on
extern "C" void fn_27_5B39C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_15BF4(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_5B39C(ptr, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
