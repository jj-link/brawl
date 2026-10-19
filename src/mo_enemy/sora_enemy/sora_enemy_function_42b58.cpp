#pragma force_active on
extern "C" {
extern void fn_41_42AE0(void* p1, short p2);
extern void __dl__FPv(void*);

void* fn_41_42B58(void* p1, short p2) {
    if (p1 != 0) {
        fn_41_42AE0(p1, 0);
        if (p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}
}
