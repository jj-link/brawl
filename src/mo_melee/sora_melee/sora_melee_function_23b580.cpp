#pragma force_active on
extern "C" {
extern void fn_27_23AB44(void*, int);
extern void __dl__FPv(void*);

void* fn_27_23B580(void* p1, int p2) {
    if (p1 != 0) {
        fn_27_23AB44(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
}
