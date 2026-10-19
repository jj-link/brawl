#pragma force_active on
extern "C" void* fn_27_A0C74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_2240(void* p, short flag) {
    if (p != 0) {
        fn_27_A0C74(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
