#pragma force_active on
extern "C" void* fn_93_21A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_12CB0(void* p, short flags) {
    if (p != 0) {
        fn_93_21A0(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
