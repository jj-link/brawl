#pragma force_active on
extern "C" {
void fn_113_68C(void* p, short v);
void __dl__FPv(void* p);
void* fn_113_804(void* p, short flag);
}

extern "C" void* fn_113_804(void* p, short flag) {
    if (p != 0) {
        fn_113_68C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
