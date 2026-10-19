#pragma force_active on
extern "C" void fn_125_1B84(void* p, short flag);

extern "C" void* fn_125_1BE8(void* p, short del) {
    if (p != 0) {
        fn_125_1B84(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
