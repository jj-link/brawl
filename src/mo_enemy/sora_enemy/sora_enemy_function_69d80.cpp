#pragma force_active on
extern "C" void* fn_41_69D1C(void* p, short flag);
extern "C" void* fn_41_33D4C(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_69D80(void* p, short flag) {
    if (p != 0) {
        fn_41_69D1C(static_cast<char*>(p) + 8, -1);
        fn_41_33D4C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
