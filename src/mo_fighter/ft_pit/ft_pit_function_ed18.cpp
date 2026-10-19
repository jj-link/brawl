#pragma force_active on
extern "C" void* fn_112_3BA4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_ED18(void* p, short n) {
    if (p != 0) {
        fn_112_3BA4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
