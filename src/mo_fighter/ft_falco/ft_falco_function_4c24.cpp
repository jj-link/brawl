#pragma force_active on
extern "C" void* fn_108_4C80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_4C24(void* ptr, short flag) {
    if (ptr != 0) {
        fn_108_4C80(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
