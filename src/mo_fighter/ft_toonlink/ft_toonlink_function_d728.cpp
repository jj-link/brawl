#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_121_6FD0(void*, short);

extern "C" void* fn_121_D728(void* p, short flags) {
    if (p != 0) {
        fn_121_6FD0(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
