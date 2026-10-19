#pragma force_active on
extern "C" void* fn_122_48DC(void* p, short size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_122_175DC(void* p, short flag) {
    if (p != 0) {
        fn_122_48DC(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
