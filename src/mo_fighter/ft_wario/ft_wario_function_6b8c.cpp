#pragma force_active on
extern "C" {
extern void* fn_27_14B698(void*, short);
extern void __dl__FPv(void*);

void* fn_110_6B8C(void* p, short a2) {
    if (p != 0) {
        fn_27_14B698(p, -1);
        if (a2 > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
