#pragma force_active on
extern "C" void fn_94_1AD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1D00(void* p, short shouldDelete) {
    if (p != 0) {
        fn_94_1AD0(p, 0);
        if (shouldDelete > 0)
            __dl__FPv(p);
    }
    return p;
}
