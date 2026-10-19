#pragma force_active on
extern "C" void* fn_95_F56C(void* ptr, short flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_95_F510(void* ptr, short flag) {
    if (ptr != 0) {
        short zero = 0;
        fn_95_F56C(ptr, zero);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
