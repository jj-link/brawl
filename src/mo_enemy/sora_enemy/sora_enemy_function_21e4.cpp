#pragma force_active on
extern "C" void fn_27_64874(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_21E4(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_64874(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
