#pragma force_active on
extern "C" {
void fn_92_1B7C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_92_1DAC(void* ptr, short destroy) {
    if (ptr != 0) {
        fn_92_1B7C(ptr, 0);
        if (destroy > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
