#pragma force_active on
extern "C" void* fn_112_3E4C(void* p, short n);

extern "C" void* fn_112_EDEC(void* p, short n) {
    if (p != 0) {
        fn_112_3E4C(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
