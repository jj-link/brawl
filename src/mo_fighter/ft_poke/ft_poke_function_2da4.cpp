#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_2DA4(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_19816C(p1, -1);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
