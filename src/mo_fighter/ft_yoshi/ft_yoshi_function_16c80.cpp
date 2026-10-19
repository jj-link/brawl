#pragma force_active on
extern "C" void* fn_95_4938(void* p, short n);

extern "C" void* fn_95_16C80(void* p, short n) {
    if (p != 0) {
        fn_95_4938(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
