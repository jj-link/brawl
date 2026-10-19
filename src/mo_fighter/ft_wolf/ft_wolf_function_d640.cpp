#pragma force_active on
extern "C" void fn_125_D5C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_D640(void* ptr, short count) {
    if (ptr != 0) {
        fn_125_D5C8(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
