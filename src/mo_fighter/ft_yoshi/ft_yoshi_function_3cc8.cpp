#pragma force_active on
typedef signed short int16_t;

extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_3CC8(void* ptr, int16_t count) {
    if (ptr != 0 && count > 0)
        __dl__FPv(ptr);
    return ptr;
}
