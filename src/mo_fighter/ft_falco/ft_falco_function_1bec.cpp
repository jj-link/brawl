#pragma force_active on
extern "C" void fn_108_1B2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_1BEC(void* ptr, int count) {
    if (ptr != 0) {
        fn_108_1B2C(ptr, 0);
        if ((short)count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
