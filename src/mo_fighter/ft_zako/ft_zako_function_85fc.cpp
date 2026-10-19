#pragma force_active on
extern "C" void* fn_126_7438(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_126_85FC(void* p, short n) {
    if (p != 0) {
        fn_126_7438(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
