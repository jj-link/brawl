#pragma force_active on
extern "C" void* fn_41_2490(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_24D0(void* p, int flags) {
    if (p != 0) {
        fn_41_2490(p, 0);
        if ((short)flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
