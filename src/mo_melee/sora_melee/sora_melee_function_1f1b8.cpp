#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1F1B8(void* p, short doDelete) {
    if (p) {
        fn_27_13C90(p, 0);
        if (doDelete > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
