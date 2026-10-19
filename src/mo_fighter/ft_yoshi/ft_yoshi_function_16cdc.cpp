#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_95_16D38(void* ptr, short size);

extern "C" void* fn_95_16CDC(void* p, short flags) {
    if (p != 0) {
        fn_95_16D38(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
