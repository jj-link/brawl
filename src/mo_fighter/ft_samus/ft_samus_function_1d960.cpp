#pragma force_active on
extern "C" void* fn_94_4DBC(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_94_1D960(void* p, short flag) {
    if (p != 0) {
        fn_94_4DBC(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
