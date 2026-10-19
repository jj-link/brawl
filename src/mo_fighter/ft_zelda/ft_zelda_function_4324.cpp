#pragma force_active on
extern "C" void* fn_27_5AE44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_4324(void* p, short flags) {
    if (p != 0) {
        fn_27_5AE44(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
