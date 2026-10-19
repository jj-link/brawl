#pragma force_active on
extern "C" void* fn_104_38A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_C23C(void* p, short flag) {
    if (p != 0) {
        fn_104_38A0(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
