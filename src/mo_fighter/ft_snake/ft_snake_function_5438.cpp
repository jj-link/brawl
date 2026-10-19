#pragma force_active on
extern "C" void fn_122_3820(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_5438(void* p, short flag) {
    if (p != 0) {
        fn_122_3820(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
