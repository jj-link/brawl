#pragma force_active on
extern "C" {
void fn_52_363C(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_52_C760(void* p, int size) {
    if (p != 0) {
        fn_52_363C(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
