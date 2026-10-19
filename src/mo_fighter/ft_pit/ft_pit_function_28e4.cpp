#pragma force_active on
extern "C" void fn_27_1A61E0(void* p, short n);

extern "C" void* fn_112_28E4(void* p, short n) {
    if (p != 0) {
        fn_27_1A61E0(p, -1);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
