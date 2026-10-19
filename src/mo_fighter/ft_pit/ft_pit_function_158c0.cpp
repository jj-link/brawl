#pragma force_active on
extern "C" void fn_27_5B39C(void* p, short flag);

extern "C" void* fn_112_158C0(void* p, short flag) {
    if (p != 0) {
        fn_27_5B39C(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
