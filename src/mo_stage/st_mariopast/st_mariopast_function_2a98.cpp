#pragma force_active on
extern "C" void fn_48_1F8C(void* p, int flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_48_2A98(void* p, int flags) {
    if (p != 0) {
        fn_48_1F8C(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
