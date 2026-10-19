#pragma force_active on
extern "C" void* fn_27_A1E80(void*, short);

extern "C" void* fn_110_4260(void* p, short flags) {
    if (p != 0) {
        fn_27_A1E80(p, -1);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
