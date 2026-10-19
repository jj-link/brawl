#pragma force_active on
extern "C" void* fn_120_12540(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_12580(void* p, int flag) {
    if (p != 0) {
        fn_120_12540(p, 0);
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
