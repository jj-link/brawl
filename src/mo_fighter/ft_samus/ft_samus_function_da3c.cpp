#pragma force_active on
extern "C" {
void* fn_94_4750(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_94_DA3C(void* p, short flags) {
    if (p != 0) {
        fn_94_4750(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
