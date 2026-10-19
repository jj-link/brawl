#pragma force_active on
extern "C" void fn_41_4E548(void* p, short s);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_4E5B8(void* p, short del) {
    if (p != 0) {
        fn_41_4E548(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
