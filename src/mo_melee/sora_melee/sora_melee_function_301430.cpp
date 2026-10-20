#pragma force_active on
extern "C" {
void fn_27_5B39C(void* p, short v);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_301430(void* p, int size) {
    if (p) {
        fn_27_5B39C(p, -1);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
