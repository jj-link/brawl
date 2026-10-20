#pragma force_active on
extern "C" void* fn_119_34B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_1346C(void* p, short flags) {
    if (p != 0) {
        fn_119_34B8(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
