#pragma force_active on
extern "C" void fn_121_1BB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_1CD0(void* p, short flags) {
    if (p != 0) {
        fn_121_1BB4(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
