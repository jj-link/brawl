#pragma force_active on
extern "C" void* fn_27_1966BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_2D20(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_1966BC(p1, -1);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
