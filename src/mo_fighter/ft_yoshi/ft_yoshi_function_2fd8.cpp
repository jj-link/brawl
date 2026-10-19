#pragma force_active on
extern "C" void* fn_27_ACC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_2FD8(void* ptr, signed short flag) {
    if (ptr != 0) {
        fn_27_ACC5C(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
