#pragma force_active on
extern "C" void* fn_27_ACC5C(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_110_2F6C(void* p, short flag) {
    if (p != 0) {
        fn_27_ACC5C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
