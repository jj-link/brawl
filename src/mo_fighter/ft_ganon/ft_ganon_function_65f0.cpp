#pragma force_active on
extern "C" void* fn_27_14B698(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_65F0(void* p, short flags) {
    if (p != 0) {
        fn_27_14B698(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
