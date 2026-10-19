#pragma force_active on
extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_4E7C(void* p, short flag) {
    if (p != 0) {
        fn_27_66114(p, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
