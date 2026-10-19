#pragma force_active on
extern "C" void* fn_27_1A3530(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_53F0(void* p, short flag) {
    if (p) {
        fn_27_1A3530(p, (short)-1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
