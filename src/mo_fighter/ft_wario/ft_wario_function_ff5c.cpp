#pragma force_active on
extern "C" void* fn_110_4804(void* p, short size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_FF5C(void* p, short size) {
    if (p != 0) {
        fn_110_4804(p, 0);
        if (size > 0)
            __dl__FPv(p);
    }
    return p;
}
