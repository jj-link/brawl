#pragma force_active on
extern "C" {
void* fn_27_5B39C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_95_7148(void* p, short flag) {
    if (p != 0) {
        fn_27_5B39C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
