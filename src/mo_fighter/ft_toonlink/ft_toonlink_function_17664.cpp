#pragma force_active on
extern "C" void* fn_27_1A4D90(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_121_17664(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_1A4D90(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
