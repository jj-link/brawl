#pragma force_active on
extern "C" void fn_71_276C(void* p, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_71_2CC0(void* p, int size) {
    if (p != 0) {
        fn_71_276C(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
