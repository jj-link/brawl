#pragma force_active on
extern "C" {
void fn_27_2DD40C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_27_328C24(void* p, int flag) {
    if (p) {
        fn_27_2DD40C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
