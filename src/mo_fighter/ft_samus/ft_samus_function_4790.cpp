#pragma force_active on
extern "C" void* fn_27_1A0CAC(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_4790(void* ptr, short count) {
    if (ptr != 0) {
        fn_27_1A0CAC(ptr, -1);
        if (count > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
