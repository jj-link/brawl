#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_93_5F68(void*, short);

extern "C" void* fn_93_1467C(void* p, short n) {
    if (p) {
        fn_93_5F68(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
