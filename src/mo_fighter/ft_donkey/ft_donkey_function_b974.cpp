#pragma force_active on
extern "C" void fn_92_B8FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_B974(void* p1, int p2) {
    if (p1 != 0) {
        fn_92_B8FC(p1, 0);
        if ((short)p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
