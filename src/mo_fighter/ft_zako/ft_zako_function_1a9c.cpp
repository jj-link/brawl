#pragma force_active on
extern "C" void fn_126_1980(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_1A9C(void* p, short flag) {
    if (p != 0) {
        fn_126_1980(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
