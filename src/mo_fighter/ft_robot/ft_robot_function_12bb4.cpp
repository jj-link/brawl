#pragma force_active on
extern "C" void* fn_27_1A405C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_12BB4(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_1A405C(p1, -1);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
