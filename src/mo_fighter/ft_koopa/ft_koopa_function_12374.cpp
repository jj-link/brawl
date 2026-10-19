#pragma force_active on
extern "C" void* fn_27_1A3D50(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_12374(void* ptr, short val) {
    if (ptr != 0) {
        fn_27_1A3D50(ptr, -1);
        if (val > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
