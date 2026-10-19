#pragma force_active on
extern "C" void fn_126_1980(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_1A40(void* p1, short p2) {
    if (p1 != 0) {
        fn_126_1980(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
