#pragma force_active on
extern "C" void fn_27_198A7C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_7AB4(void* p, short s) {
    if (p != 0) {
        fn_27_198A7C(p, -1);
        if (s > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
