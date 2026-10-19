#pragma force_active on
extern "C" void* fn_41_252C(void* p, short n);

extern "C" void* fn_41_256C(void* p, short n) {
    if (p != 0) {
        fn_41_252C(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
