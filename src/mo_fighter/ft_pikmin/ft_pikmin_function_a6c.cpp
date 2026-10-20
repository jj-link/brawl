#pragma force_active on
extern "C" {
void fn_27_57BA0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_113_A6C(void* p, short flag) {
    if (p != 0) {
        fn_27_57BA0(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
