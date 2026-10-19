#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_97_46A0(void* ptr, short count);

extern "C" void* fn_97_10608(void* p1, void* p2) {
    if (p1) {
        fn_97_46A0(p1, 0);
        if ((short)p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}
