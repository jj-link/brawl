#pragma force_active on
extern "C" void fn_63_2C40(void* p, int flag);

extern "C" void* fn_63_34F8(void* p, int del) {
    if (p) {
        fn_63_2C40(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
