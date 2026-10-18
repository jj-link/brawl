#pragma force_active on
extern "C" void* fn_27_1A405C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_10400(void* ptr, short mode) {
    if (ptr != 0) {
        fn_27_1A405C(ptr, -1);
        if (mode > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
