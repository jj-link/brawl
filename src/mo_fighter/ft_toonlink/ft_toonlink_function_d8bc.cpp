#pragma force_active on
extern "C" void* fn_121_6FD0(void* p, short flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_121_D8BC(void* p, short flags) {
    if (p != 0) {
        fn_121_6FD0(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
