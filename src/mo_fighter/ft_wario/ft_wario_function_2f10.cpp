#pragma force_active on
extern "C" void* fn_27_B64B8(void*, short);

extern "C" void* fn_110_2F10(void* p, short flags) {
    if (p != 0) {
        fn_27_B64B8(p, -1);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
