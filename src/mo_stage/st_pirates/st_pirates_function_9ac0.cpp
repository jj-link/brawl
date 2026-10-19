#pragma force_active on
extern "C" void fn_52_363C(void* p, int flag);

extern "C" void* fn_52_9AC0(void* p, int flag) {
    if (p) {
        fn_52_363C(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
