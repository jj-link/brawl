#pragma force_active on
extern "C" void fn_40_1C140(void*, int);

extern "C" void* fn_40_3060C(void* p, int del) {
    if (p != 0) {
        fn_40_1C140(p, 0);
        if (del > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
