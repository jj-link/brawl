#pragma force_active on
extern "C" void fn_95_1C58(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_1E2C(void* ptr, short count) {
    if (ptr != 0) {
        fn_95_1C58(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
