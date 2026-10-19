#pragma force_active on
extern "C" void* fn_116_4150(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_10074(void* p, short n) {
    if (p != 0) {
        fn_116_4150(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
