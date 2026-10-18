#pragma force_active on
extern "C" {
void fn_27_5B39C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_56D4(void* p, int flag) {
    if (p != 0) {
        fn_27_5B39C(p, -1);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}
