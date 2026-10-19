#pragma force_active on
extern "C" {
void* fn_27_1A09B4(void*, short);
void __dl__FPv(void*);

void* fn_125_23B0(void* p, short del) {
    if (p) {
        fn_27_1A09B4(p, -1);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
