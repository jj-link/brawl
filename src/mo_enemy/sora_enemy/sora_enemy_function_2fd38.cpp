#pragma force_active on
extern "C" void* fn_27_C2E50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2FD38(void* p, short n) {
    if (p) {
        fn_27_C2E50(p, (short)-1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
