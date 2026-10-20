#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);

extern "C" void* fn_27_31F7B0(void* p, int flag) {
    if (p) {
        fn_27_BED74(p, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
