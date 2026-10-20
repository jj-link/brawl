#pragma force_active on
extern "C" void* fn_113_35B8(void* p, short n);

extern "C" void operator delete(void* p);

extern "C" void* fn_113_1552C(void* p, short n) {
    if (p != 0) {
        fn_113_35B8(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
