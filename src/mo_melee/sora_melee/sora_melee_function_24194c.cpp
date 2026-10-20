#pragma force_active on
extern "C" void fn_27_23AB44(void* p1, int p2);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_27_24194C(void* p1, int p2) {
    if (p1) {
        fn_27_23AB44(p1, 0);
        if (p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}
