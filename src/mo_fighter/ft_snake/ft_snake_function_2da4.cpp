#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_2DA4(void* p, short del) {
    if (p != 0) {
        fn_27_19816C(p, -1);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
