#pragma force_active on
extern "C" {
void fn_95_1C58(void* p, short x);
void __dl__FPv(void* p);
}

extern "C" void* fn_95_1D74(void* p, short flag) {
    if (p != 0) {
        fn_95_1C58(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
