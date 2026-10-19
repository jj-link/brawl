#pragma force_active on
extern "C" void* fn_41_2374(void* p, short size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_23B4(void* p, short size) {
    if (p != 0) {
        fn_41_2374(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
