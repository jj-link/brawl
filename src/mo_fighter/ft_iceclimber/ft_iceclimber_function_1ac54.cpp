#pragma force_active on
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_105_1AC14(void* p, short flag);

extern "C" void* fn_105_1AC54(void* p, short flag) {
    if (p != 0) {
        fn_105_1AC14(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
