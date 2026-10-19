#pragma force_active on
extern "C" void* fn_112_451C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_CA10(void* p, short flags) {
    if (p != 0) {
        fn_112_451C(p, 0);
        if (flags > 0)
            __dl__FPv(p);
    }
    return p;
}
