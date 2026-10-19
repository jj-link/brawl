#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_2E04(void* p, short flag) {
    if (p != 0) {
        fn_27_19816C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
