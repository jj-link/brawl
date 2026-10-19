#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_126_1CA8(void* ptr, short count);

extern "C" void* fn_126_1C4C(void* ptr, short value) {
    if (ptr != 0) {
        fn_126_1CA8(ptr, 0);
        if (value > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
