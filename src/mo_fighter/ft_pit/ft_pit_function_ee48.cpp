#pragma force_active on
extern "C" void* fn_112_EEA4(void* p, short size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_112_EE48(void* p, short flag) {
    if (p != 0) {
        fn_112_EEA4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
