#pragma force_active on
extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_2040(void* p, short flags) {
    if (p != 0) {
        fn_27_7700(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
