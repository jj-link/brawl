#pragma force_active on
extern "C" void fn_27_1A5ED4(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_120_28BC(void* p, short flag) {
    if (p != 0) {
        fn_27_1A5ED4(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
