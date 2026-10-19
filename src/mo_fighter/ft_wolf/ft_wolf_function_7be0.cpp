#pragma force_active on
extern "C" {
void fn_27_C9EDC(void*, short);
void __dl__FPv(void*);

void* fn_125_7BE0(void* p, short flag) {
    if (p != 0) {
        fn_27_C9EDC(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
