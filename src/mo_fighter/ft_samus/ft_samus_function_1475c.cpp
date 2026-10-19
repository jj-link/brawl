#pragma force_active on
extern "C" void* fn_27_C31CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1475C(void* p, short flags) {
    if (p != 0) {
        fn_27_C31CC(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
