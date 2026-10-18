#pragma force_active on
extern "C" void fn_27_64D9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_6210(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_64D9C(ptr, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
