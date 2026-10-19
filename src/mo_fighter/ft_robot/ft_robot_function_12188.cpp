#pragma force_active on
extern "C" void* fn_120_599C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_12188(void* p, short shouldDelete) {
    if (p != 0) {
        fn_120_599C(p, 0);
        if (shouldDelete > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
