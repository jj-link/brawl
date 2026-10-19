#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_36F4(void* p, short flags) {
    if (p != 0) {
        fn_27_5C674(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
