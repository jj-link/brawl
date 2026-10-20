#pragma force_active on
extern "C" void fn_27_1FFCC(const void*);

extern "C" void* fn_27_1F9CC(void* p, int flag) {
    if (p) {
        fn_27_1FFCC(p);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
