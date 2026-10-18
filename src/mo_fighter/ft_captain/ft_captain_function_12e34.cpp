#pragma force_active on
extern "C" void* fn_100_12DF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_12E34(void* ptr, short count) {
    if (ptr != 0) {
        if (ptr != 0) {
            fn_100_12DF4(ptr, 0);
        }
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
