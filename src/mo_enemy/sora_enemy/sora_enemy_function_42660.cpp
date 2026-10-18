#pragma force_active on
extern "C" void fn_41_42600(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_42660(void* p, short n) {
    if (p != 0) {
        fn_41_42600((char*)p + 8, -1);
        if (n > 0)
            __dl__FPv(p);
    }
    return p;
}
