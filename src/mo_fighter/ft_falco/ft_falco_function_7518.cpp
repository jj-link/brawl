#pragma force_active on
extern "C" void fn_27_64D9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_7518(void* p, short count) {
    if (p != 0) {
        fn_27_64D9C(p, -1);
        if (count > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
